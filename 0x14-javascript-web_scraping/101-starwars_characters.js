#!/usr/bin/node
// A script that prints all characters of a Star Wars movie

const request = require('request');

const movie = process.argv[2];
const api = 'https://swapi-api.hbtn.io/api/';
const url = api + 'films/' + movie + '/';
request.get({ url: url }, settle);

function settle (e, r, b) {
  if (!e) {
    const promises = [];
    const characters = JSON.parse(b).characters;
    for (const character of characters) {
      promises.push(
        new Promise(function (resolve, reject) {
          request.get(character, function (err, res, body) {
            if (!err) {
              resolve(JSON.parse(body).name);
            }
          });
        })
      );
    }
    Promise.allSettled(promises)
      .then(function (names) {
        for (const name of names) {
          console.log(name.value);
        }
      });
  }
}
