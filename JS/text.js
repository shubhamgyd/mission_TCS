const Bike = function (model, color) {
  this.model = model;
  this.color = color;
};

Bike.prototype.getDetails = function () {
  return this.model + " has " + this.color + " color.";
};

const bk = new Bike("BMW", "Black");
console.log(bk.getDetails());
