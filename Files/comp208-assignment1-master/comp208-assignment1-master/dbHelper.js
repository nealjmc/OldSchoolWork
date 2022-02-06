const mysql = require('mysql')
const creds = require('./creds')
let connection = mysql.createConnection(creds)
let conn
/**
 * Open Db
 */
const openDb = () => {
  conn = connection.connect()
}

/**
 * Close db
 */
const closeDb = () => {
  conn = connection.end()
}

/**
 * Get all cities
 * @param {int} offset Offset for pagination
 */
const getCities = (offset = 0) => {
  return new Promise((resolve, reject) => {
    connection.query(
      'select * from city limit 10 offset ?',
      [offset],
      (error, results) => {
        if (error) {
          reject(error)
        }
        resolve(results)
      }
    )
  })
}

/**
 * Get city by code
 * @param {string} id city id
 */
const getSpecificCity = id => {
  return new Promise((resolve, reject) => {
    connection.query(
      'select * from city where ID like ?',
      [id],
      (error, results) => {
        if (error) {
          reject(error)
        }
        resolve(results)
      }
    )
  })
}

/**
 * Get Country by id
 * @param {int} id country id
 */
const getSpecificCountry = id => {
  return new Promise((resolve, reject) => {
    connection.query(
      'select * from country where Code like ?',
      [id],
      (error, results) => {
        if (error) {
          reject(error)
        }
        resolve(results)
      }
    )
  })
}

/**
 * Get all countries
 * @param {int} offset Offset for pagination
 */
const getCountries = (offset = 0) => {
  return new Promise((resolve, reject) => {
    connection.query(
      'select * from country limit 10 offset ?',
      [offset],
      (error, results) => {
        if (error) {
          reject(error)
        }
        resolve(results)
      }
    )
  })
}

/**
 * Get all cities in country
 * @param {int} id Country id
 */
const getCitiesInCountry = (
  id,
  page = null,
  district = null,
  minPop = null
) => {
  return new Promise((resolve, reject) => {
    let queryParams = [id]
    let query =
      'select city.ID, city.Name, city.CountryCode, city.District, city.Population from city ' +
      ' join country on country.Code = city.countryCode' +
      ' WHERE city.CountryCode like ?'

    if (district) {
      query += " AND city.District like '?'"
      queryParams.push(district)
    }
    if (minPop) {
      query += ' AND city.Population >= ?'
      minPop = parseInt(minPop)
      queryParams.push(minPop)
    }
    query += ' LIMIT 10'
    if (page) {
      query += ' OFFSET ?'
      page = parseInt(page)
      queryParams.push(page)
    }
    console.log(query)
    connection.query(query, queryParams, (error, results) => {
      if (error) {
        console.log(error)
        reject(error)
      }
      resolve(results)
    })
  })
}

/**
 * Add city to DB
 * @param {object} city City object
 */
const addCity = city => {
  return new Promise((resolve, reject) => {
    let query =
      'insert into world.city (city.Name, city.CountryCode, city.District, city.Population) '
    let values = 'values (?, ?, ?, ?)'
    connection.query(
      query + values,
      [city.Name, city.Country, city.District, city.Population],
      (error, results) => {
        if (error) {
          reject(error)
        } else {
          resolve(results)
        }
      }
    )
  })
}

const getAllDistictCountries = () => {
  return new Promise((resolve, reject) => {
    let query = 'select distinct Code from country;'
    connection.query(query, [], (error, results) => {
      if (error) {
        reject(error)
      } else {
        resolve(results)
      }
    })
  })
}
module.exports = {
  getCities,
  getSpecificCity,
  getCitiesInCountry,
  getCountries,
  getSpecificCountry,
  openDb,
  closeDb,
  addCity,
  getAllDistictCountries
}
