const getHostname = () => {
  return 'http://localhost:3000'
}

/**
 * Calls to api and mounts to elementId
 * @param {string} elementId element to mount
 */
const getCities = (elementId, paramList = []) => {
  document.getElementById(elementId).innerHTML = ''
  buildUrlWithParams('cities', paramList).then(url => {
    let totalResults = 0
    fetch(url)
      .then(res =>
        res.json().then(json => {
          totalResults = json.length
          document.getElementById('resultsLength').innerText = totalResults
          let rows = createTableRows(json)
          let headers = createTableHeader(Object.keys(json[0]))
          document.getElementById(elementId).appendChild(headers)
          rows.forEach(row => {
            document.getElementById(elementId).appendChild(row)
          })
        })
      )
      .catch(e => {
        console.error(e)
        //   alert('Error getting cities!')
      })
  })
}

const createTableRows = json => {
  let rows = []
  Object.values(json).map((value, key) => {
    let newRow = _createElement('tr')
    Object.values(value).map(value => {
      let col = _createElement('td')
      col.innerText = value
      newRow.appendChild(col)
    })
    rows.push(newRow)
  })
  return rows
}

const _createElement = type => {
  return document.createElement(type)
}

const createTableHeader = (arrayOfHeaders = []) => {
  let row = _createElement('thead')
  arrayOfHeaders.forEach(header => {
    let col = _createElement('th')
    col.innerText = header
    row.appendChild(col)
  })
  return row
}

const getCountries = (elementId, paramList = []) => {
  document.getElementById(elementId).innerHTML = ''
  buildUrlWithParams('countries', paramList).then(url => {
    let totalResults = 0
    fetch(url)
      .then(res =>
        res.json().then(json => {
          totalResults = json.length
          document.getElementById('resultsLength').innerText = totalResults
          let rows = createTableRows(json)
          let headers = createTableHeader(Object.keys(json[0]))
          document.getElementById(elementId).appendChild(headers)
          rows.forEach(row => {
            document.getElementById(elementId).appendChild(row)
          })
        })
      )
      .catch(e => {
        console.error(e)
        //   alert('Error getting cities!')
      })
  })
}

const getCitiesInCountry = (elementId, paramList = []) => {
  document.getElementById(elementId).innerHTML = ''
  buildUrlWithParams('countries', paramList).then(url => {
    let totalResults = 0
    fetch(url)
      .then(res =>
        res.json().then(json => {
          totalResults = json.length
          document.getElementById('resultsLength').innerText = totalResults
          let rows = createTableRows(json)
          let headers = createTableHeader(Object.keys(json[0]))
          document.getElementById(elementId).appendChild(headers)
          rows.forEach(row => {
            document.getElementById(elementId).appendChild(row)
          })
        })
      )
      .catch(e => {
        console.error(e)
        //   alert('Error getting cities!')
      })
  })
}

const buildParams = (url, listOfParams) => {
  let params = new URLSearchParams(url)
  listOfParams.forEach(param => {
    let object = Object.entries(param)
    let key = object[0][0]
    let value = object[0][1]
    params.append(key, value)
  })
  return params
}

const buildUrlWithParams = (path = '', paramsList = []) => {
  return new Promise((resolve, reject) => {
    try {
      let url = new URL(`${getHostname()}/${path}?`)
      let params = buildParams(url, paramsList)
      url += params
      resolve(url)
    } catch (e) {
      reject(e)
    }
  })
}

const buildCountryDropDown = elementToAppendto => {
  buildUrlWithParams('countries/all', []).then(url => {
    fetch(url).then(res =>
      res.json().then(json => {
        $('#ddlCountries').html(() => {
          // dropdown div
          let dropdowndiv = document.createElement('div')
          dropdowndiv.classList.add('dropdown')

          // open button
          let openbutton = document.createElement('button')
          openbutton.classList.add('btn')
          openbutton.classList.add('btn-secondary')
          openbutton.classList.add('dropdown-toggle')
          openbutton.type = 'button'
          openbutton.id = 'ddlOpenCountries'
          openbutton.setAttribute('data-toggle', 'dropdown')
          openbutton.textContent = 'Sort by country'
          dropdowndiv.appendChild(openbutton)

          //dropdown menu
          let dropdownMenu = document.createElement('div')
          dropdownMenu.classList.add('dropdown-menu')

          //dropdown options
          json.forEach(country => {
            let link = document.createElement('a')
            link.name = 'countryCode'
            link.classList.add('dropdown-item')
            link.textContent = `${country.Code}`
            dropdownMenu.appendChild(link)
          })
          dropdowndiv.appendChild(dropdownMenu)
          document.getElementById(elementToAppendto).appendChild(dropdowndiv)
        })
      })
    )
  })
}
// <div class="dropdown">
//   <button
//     class="btn btn-secondary dropdown-toggle"
//     type="button"
//     id="dropdownMenuButton"
//     data-toggle="dropdown"
//     aria-haspopup="true"
//     aria-expanded="false"
//   >
//     Minumum Population
//   </button>
//   <div class="dropdown-menu" aria-labelledby="dropdownMenuButton">
//     <a name="minPop" class="dropdown-item" href="#">0</a>
//     <a name="minPop" class="dropdown-item" href="#">1000</a>
//     <a name="minPop" class="dropdown-item" href="#">10,000</a>
//     <a name="minPop" class="dropdown-item" href="#">100,000</a>
//     <a name="minPop" class="dropdown-item" href="#">1,000,000</a>
//   </div>
// </div>
