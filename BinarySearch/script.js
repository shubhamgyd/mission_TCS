function login() {
  var username = document.getElementById("username").value;
  var password = document.getElementById("password").value;

  // Check if username and password are valid
  if (
    username === localStorage.getItem("username") &&
    localStorage.getItem("password")
  ) {
    // Redirect to the dashboard page
    window.location.href = "dashboard.html";
  } else {
    // Store user login information in Local Storage
    localStorage.setItem("username", username);
    localStorage.setItem("password", password);
    window.location.href = "dashboard.html";
  }
}

// Automatically login user if login information is stored in Local Storage
window.onload = function () {
  var storedUsername = localStorage.getItem("username");
  var storedPassword = localStorage.getItem("password");

  if (storedUsername && storedPassword) {
    document.getElementById("username").value = storedUsername;
    document.getElementById("password").value = storedPassword;
    login();
  }
};
