function Stack() {
  this.arr = [];

  this.push = function (item) {
    for (var i = this.arr.length - 1; i >= 0; i--) {
      this.arr[i + 1] = this.arr[i];
    }
    this.arr[0] = item;
  };
  this.pop = function (item) {
    if (this.arr.length == 0) {
      return "Stack underflow";
    }
    // MISSING1
    var poppedValue = this.arr[0];
    for (var i = 0; i < this.arr.length - 1; i++) {
      this.arr[i] = this.arr[i + 1];
    }
    this.arr.length -= 1;
    return poppedValue;
  };
  this.top = function () {
    // return MISSING2;
    return this.arr[0];
  };
  this.isEmpty = function () {
    // MISSING3;
    return this.arr.length == 0;
  };
}

function stacksEqual(stack1, stack2) {
  while (!stack1.isEmpty() && !stack2.isEmpty()) {
    if (stack1.top() !== stack2.top()) {
      return false;
    }
    stack1.pop();
    stack2.pop();
  }
  return stack1.isEmpty() && stack2.isEmpty();
}
