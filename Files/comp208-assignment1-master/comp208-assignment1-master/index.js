const express = require('express')
const cors = require('cors')
const app = express()
const dbHelper = require('./dbHelper')
const bodyParser = require('body-parser')
const fs = require('fs')
dbHelper.openDb()
app.use(bodyParser.json())
app.use(cors())

app.get('/docs', (req, res) => {
  let documentationPath = fs.readFile(
    './documentation/README.md',
    'utf8',
    (err, data) => {
      if (err) res.status(500).send(err)
      res.send(data)
    }
  )
})

/**
 * return array of all cities – limit the actual number of cities to 10
 */
app.get('/cities', (req, res) => {
  let page = req.query.page
  if (page) {
    let offset = page > 0 ? (page - 1) * 10 : 0
    dbHelper.getCities(offset).then(results => res.send(results))
  } else {
    dbHelper.getCities().then(dbResults => {
      res.send(dbResults)
    })
  }
})

/**
 * Post new city
 */
app.post('/cities', (req, res) => {
  let city = req.body
  dbHelper
    .addCity(city)
    .then(results => {
      res.status(201).send(results)
    })
    .catch(e => {
      res.status(500).send(e)
    })
})

/**
 * return city with id=N
 */
app.get('/cities/:id', (req, res) => {
  let id = req.params.id
  dbHelper.getSpecificCities(id).then(results => res.send(results))
})

/**
 * return array of all countries – limit the number of countries to 10
 */
app.get('/countries', (req, res) => {
  let page = req.query.page
  if (page) {
    let offset = page > 0 ? (page - 1) * 10 : 0
    dbHelper.getCountries(offset).then(results => res.send(results))
  } else {
    dbHelper.getCountries().then(results => res.send(results))
  }
})

app.get('/countries/all', (req, res) => {
  dbHelper.getAllDistictCountries().then(results => res.send(results))
})
/**
 * return country whose id is CODE
 */
app.get('/countries/:id', (req, res) => {
  let id = req.params.id
  dbHelper.getSpecificCountry(id).then(results => res.send(results))
})

/**
 * return all cities within the country whose code is CODE – limit to 10
 */
app.get('/countries/:id/cities', (req, res) => {
  let id = req.params.id
  let page = req.query.page
  let district = req.query.region
  let minPop = req.query.mp

  dbHelper
    .getCitiesInCountry(id, page, district, minPop)
    .then(results => res.status(200).send(results))
    .catch(e => res.status(500))
})

let server = app.listen(3000, () => {
  console.log('Server Started.', server.address().port)
})
