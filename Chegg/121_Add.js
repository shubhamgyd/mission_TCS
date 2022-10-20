class Vec3 {
  constructor(x, y, z) {
    this.x = 0;

    this.y = 0;

    this.z = 0;
  }

  add = function (newVec) {
    this.x += newVec.x;

    this.y += newVec.y;

    this.z += newVec.z;

    return this;
  };
}

const newVec = new Vec3(10, 10, 10);

console.log(Vec3.copy(testvec));
