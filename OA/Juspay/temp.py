from flask import Flask, jsonify, request
import sqlite3

app = Flask(__name__)


# Database initialization
def initialize_database():
    connection = sqlite3.connect("employee_database.db")
    cursor = connection.cursor()

    # Create Employee_Table if it doesn't exist
    cursor.execute(
        """CREATE TABLE IF NOT EXISTS Employee_Table
                      (id INTEGER PRIMARY KEY AUTOINCREMENT,
                      name TEXT NOT NULL,
                      age INTEGER NOT NULL,
                      position TEXT NOT NULL,
                      salary REAL NOT NULL)"""
    )

    connection.commit()
    connection.close()


# Create a new employee record in the database
def create_employee_record(employee_data):
    connection = sqlite3.connect("employee_database.db")
    cursor = connection.cursor()

    cursor.execute(
        """INSERT INTO Employee_Table (name, age, position, salary)
                      VALUES (?, ?, ?, ?)""",
        (
            employee_data["name"],
            employee_data["age"],
            employee_data["position"],
            employee_data["salary"],
        ),
    )

    connection.commit()
    connection.close()


# Retrieve all employee records from the database
def get_all_employees():
    connection = sqlite3.connect("employee_database.db")
    cursor = connection.cursor()

    cursor.execute("SELECT * FROM Employee_Table")
    employees = cursor.fetchall()

    connection.close()

    return employees


# Retrieve an employee record from the database by ID
def get_employee(id):
    connection = sqlite3.connect("employee_database.db")
    cursor = connection.cursor()

    cursor.execute("SELECT * FROM Employee_Table WHERE id=?", (id,))
    employee = cursor.fetchone()

    connection.close()

    return employee


# Update an employee record in the database
def update_employee(id, employee_data):
    connection = sqlite3.connect("employee_database.db")
    cursor = connection.cursor()

    cursor.execute(
        """UPDATE Employee_Table SET name=?, age=?, position=?, salary=?
                      WHERE id=?""",
        (
            employee_data["name"],
            employee_data["age"],
            employee_data["position"],
            employee_data["salary"],
            id,
        ),
    )

    connection.commit()
    connection.close()


# Delete an employee record from the database
def delete_employee(id):
    connection = sqlite3.connect("employee_database.db")
    cursor = connection.cursor()

    cursor.execute("DELETE FROM Employee_Table WHERE id=?", (id,))

    connection.commit()
    connection.close()


# Greeting
@app.route("/greeting", methods=["GET"])
def greeting():
    return "Hello world!"


# Create Employee
@app.route("/employee", methods=["POST"])
def create_employee():
    employee_data = request.get_json()
    create_employee_record(employee_data)
    return jsonify(employee_data), 201


# Get all Employee details
@app.route("/employees/all", methods=["GET"])
def get_all_employees_route():
    employees = get_all_employees()
    return jsonify(employees)


# Get Employee details
@app.route("/employee/<id>", methods=["GET"])
def get_employee_route(id):
    employee = get_employee(id)
    if employee:
        return jsonify(employee)
    else:
        return jsonify({"error": "Employee not found"}), 404


# Update Employee
@app.route("/employee/<id>", methods=["PUT"])
def update_employee_route(id):
    employee_data = request.get_json()
    update_employee(id, employee_data)
    return jsonify(employee_data)


# Delete Employee
@app.route("/employee/<id>", methods=["DELETE"])
def delete_employee_route(id):
    delete_employee(id)
    return "", 204


if __name__ == "__main__":
    initialize_database()
    app.run(port=8080, host="0.0.0.0")
