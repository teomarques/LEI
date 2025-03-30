## Deadlines

| What?            | When?      | How Much? |
| ---------------- | ---------- | --------- |
| Midterm delivery | 21/03      | 35%       |
| Two Checkpoints  | -          | 5% each   |
| Final Delivery   | 22/05      | 55%       |
| Final Defense    | Early June | -         |
## Topics

1. Create a *conceptual* (ER diagram) and *physical* (Relational) data model
2. implement database system with *PostgreSQL* - (<u>pgAdmin</u>)
3. Develop a *REST API* to interact with the database - (<u>python</u>)
4. Implement various functionalities using SQL, PL / pgSQL, triggers and functions

## Technical constraints

- The Entity-relationship model should be created using *ONDA*
- The project is to be developed in *Python*
- The project must use the *PostgreSQL* DBMS
- The interaction with the REST API should be done using *Postman* tool
- The use of ORMs is not allowed
- SQL queries should be created using the operators taught in the course; other operators/functionalities are allowed but need to be explicitly justified!

# University Management System

understanding the main entities:

**Users** (with sub-types)
- *Students*
- *Instructors*
- *Administrative Staff*
**Academic Structures**
- *Courses* (a discipline)
- *Course Editions* (specific offering of course in a given year)
- *Classes* (T; PL)
- *Degree Programs* (complete program of study)
- *Classrooms and Buildings*
**Activities**
- *Extracurricular* (clubs, sports)
**Financial**
- *Student Financial Accounts*
- *Fees and Payments*
**Academic Records**
- *Grades*
- *Attendance*
- *Evaluation Periods*

---

## Notes

- Justify that the course edition is associated both with the student
- Justify the instructor - assistant relation and why the coordinator is a relation between disciplina_ed and instructor