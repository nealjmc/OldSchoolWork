# Documentation :fire:

## Cities

Gather all cities and paginate the results.

- [Get - /cities](http://localhost:3000/cities) - get all cities
- [Get - /cities:id](http://localhost:3000/cities/1) - get city by ID
- [Get - /cities?page=N](http://localhost:3000/cities?page=2) - paginate the results

## Countries

Gather all cities and paginate the results.

- [Get - /countries](http://localhost:3000/countries) - get all cities
- [Get - /countries:CODE](http://localhost:3000/countries/ABW) - get city by code
- [Get - /countries:CODE?region=REGION](http://localhost:3000/countries/ABW) - get city by code
- [Get - /countries?page=:N](http://localhost:3000/countries?page=2) - paginate the results
- [Get - /countries/:CODE/cities](http://localhost:3000/countries/USA/cities) - grab all cities within a country
- [Get - /countries/:CODE/cities?page=N](http://localhost:3000/countries/USA/cities?page=2) - grab all cities within a country and paginate results
