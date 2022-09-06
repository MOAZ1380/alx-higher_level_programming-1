#!/usr/bin/node

const dict = require('./101-data').dict;
let sort = {}
Object.entries(dict).map(([k, v]) => {
  Object.hasOwn(sort, v) ? sort[v].push(k) : sort[v] = [k];
});
console.log(sort);
