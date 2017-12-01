const Raindrops = function() {};

Raindrops.prototype.convert = function(number) {
  let out = "";
  if (number % 3 == 0) { out += "Pling"; }
  if (number % 5 == 0) { out += "Plang"; }
  if (number % 7 == 0) { out += "Plong"; }
  if (out.length == 0) { out = number.toString(); }
  return out;
};

module.exports = Raindrops;
