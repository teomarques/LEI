
# T 1

**Domains**
- *AI to improve dependability and security of complex systems*
- *Improving the dependability of AI*

**You should be able to know:**
- *What is a (relational) database?*
- *How to install and configure a database server?*
- *How to design a database schema?*
- *How to develop a database application? (Including database specific languages)*
- *What are the main database administration tasks? (Including security challenges)*

**T / TP**
- *Relational Model & Structured Query Language (SQL)*
- *Entity-Relationship Model*
- *Functional Dependencies and Database Normalization*
- *Transactions and Concurrency Control*
- *Development of Database Applications*

**PL**
- *Installing a Database Management System (DBMS)*
- *SQL*
- *Entity-Relationship Model*
- *Transactions and Concurrency Control*
- *Procedural SQL (PL/pgSQL)*
- *Database Indexing and SQL Tunning*

## ***SCHEDULE***

![[Pasted image 20250203113232.png]]

# **DBMS (Database Management System)**

-> Oracle Database; PostgreSQL; MySQL; IBM DB2; Microsoft SQL Server

**DEMO 1**

| localhost (my machine) | DMBS       |
| ---------------------- | ---------- |
| unidb.py               | 10.3.2.4.1 |

## Why DS?

- Database apps used to be build on top of the file sistems -> **problem**
- Data redundancy and inconsistency
	- data stored in multiple formats (duplication)
- Difficulty in accessing data
	- need to write a new program to carry out each new task
- Data isolation issues
	- multiple files and formats
- Integrity problems
	- integrity constraints
	- hard to add new constraints or change existing ones
- Atomicity of updates
	- Failures may cause inconsistent state
- Conncurrent acces by multiple users
	- needed for performance
	- uncontrolled concurrent accesses can lead to inconsistencies
- Security problems
	- hard to provide user acces to some data

**Database systems provide solutions to all the problems above**

## Data Models 

- A collection of tools for describing
	-> *data*
	-> *data relationships*
	-> *data semantics*
	-> *data constrainsts*
- Relational Model
- Entity-Relationship (ER) data model
- Object based data models
- Semi-structured data model (XML)
- other older models such as: network model or hierarchicla model

### Relational Model 

The most common model used, looks like an excel sheet (heather, rows and columns)

### Schemas and Instances

The <u>logical schema</u> describes the overall logical structure of the database 
	- e.g. what the information on the database consists of and the relationship between data
The <u>physical schema</u> describes the overall physical structure of the schema
An <u>instance</u> (time) is the actual content of the database at a particular point in time

(columns "objects" can relate to other databases)

| Logical Design                                | ---> | Physical Design         |
| --------------------------------------------- | ---- | ----------------------- |
| conceptual model (entities and relationships) |      | physical model (tables) |

### Database Languages

A database system provides a language to specify the database schema and to express queries and updates to the data
	- <u>Data Definition Language</u> (**DDL**): defining relations ; deleting relations ; modifying relations
	- <u>Data Manipulation Language</u> (**DML**): query information from the database and insert, delete and modify tuples
<u>Structured Query Language</u> **(SQL)** -> is the reference language for databases

### DDL 

```sql
create table instructor(
ID char(5),
name varchar(20),
dept_name varchar(20),
salary numeric(8,2),
primary key (ID));
```
-> The DDL compiler generates a set of table templates stored in a data
dictionary

### DML

-> Language for accessing and updating the data organized by the
appropriate data model (aka query language)

there are two types of data-manipulation languages:
- <u>Procedural DML</u> - require a **user** to specify what data are needed and how to get those data
- <u>Declarative DML</u> - require a user to specify what data are needed without specifying how to get those data

-> ***Declarative DML*** are also referred as ***non-procedural DMLs***
-> the portion of a DML that involves info retrieval is called a ***query language***

```SQL
select name
from instructor
where dept_name = 'Comp. Sci.’;
```

# Commands

| comando                                                       | ação                                                                                      |
| ------------------------------------------------------------- | ----------------------------------------------------------------------------------------- |
| **\dt**                                                       | faz listagem da database do diretório onde se encontra                                    |
| **\d coluna**                                                 | faz listagem da "sub-tabela" da coluna especificada                                       |
| **create table *name* (*heather specified parameters*);**     | cria nova tabela dentro do diretorio especificado                                         |
| **select \* from *table*;**                                   | mostra registro da tabela (\* seleciona tudo)                                             |
| **insert into *registro* values (*value 1*, *value 2*);**     | adiciona novos valores passados como parâmetro para a tabela especificada (registro)      |
| **update *tabela* set *registro* = *valor* where *condição*** | refatora registro da tabela para um valor onde o registro existente respeita uma condição |
| **delete from *tabela* where *registro* = *valor***           | apaga todos os registros que respeitam um valor da tabela                                 |

### Comments

- We *never* store sensitive information in *plain text* (such as passwords)
- Advantages of the **geographic spread DBMS**:
	- to reduce the probability of having redundancy in data
- **never** connect to the postgres databases of:
	- *administrative database*
	- *user admin.*
- text are *case sensitive*



---


# AULA T2

## *RELATIONAL MODEL*

-> Primary model for data processing
-> Simple, independent from any low-level data structures
-> Incorprated new features and capabilities over time

***Relation*** --> ***Table***

### ***relational database*** 

1. A **relational database** is a collection of **relations** (tables)
2. Each **table** has a unique **name**
3. A **tuple** (row) in a **relation** (table) represents relationships among a set of **vales**, each one representing an **attribute** (column)
4. A **relation instance** refers to a specific **instance** of a **relation**, containing a specific set of rows
```
relations - tables

tuple - rows

attribute - column
```

<u>relational databases</u>
![[Pasted image 20250210115040.png]]

**PREREQ RELATION** -> pré-requisito para a base de dados

### ***domain of the attributes***

- A **Domain** is a set of permitted values for the attribute
	- Ex: a domain of the *salary* attribute of the instructor relation is a <u>set of all the possible salary values</u>

- The **Domain** of each attribute **must be atomic** (cannot be divided)
	- Ex: the *salary* attribute of the instructor relation <u>can store a single salary value</u>
	- Imagine that an attribute phone_number is added to the instructor relation, to represent the (several) phone numbers of each instructor. Is this atomic?
		- It depends on how we treat this phone number. It can be divided in country code, area code, etc., but if we treat it as an indivisible unit, then it is atomic.

- The **Null Value** is a special case representing that the value is *unknown* or does not exist

### ***relation schema***
-> logical structure of the relation: R = (A1, A2, …, An)

![[Pasted image 20250210123059.png]]

### ***database schema***
-> is the **logical structure** of the database

### ***database instance***
-> is a **snapshot of the data** in the database at a given instance in time

# *KEYS*

- used to *identify a specific row* in a table
- establishes a *relation* between a *row in one table* and a *row in another table*
- **can be any value**

#### ***SuperKeys***

-> a set of **one or more attributes** that can be used to **identify univocally** a tuple in a relation

#### ***Candidate Keys***

-> A **superkey** that has **only one attribute** (?)
-> It is possible to have *several candidate keys* for a single relation
-> It is important to *identify all candidate keys* - their value **cannot repeat**

```A candidate key is the smallest set of attributes that ensures each row in a relation is uniquely identified. Any redundant subset must also be considered, but only if all subsets are invalid as superkeys, making the original set a candidate key. ```

#### **Primary Keys**

-> **The Primary key is one of the candidate keys**
(are sometimes referred as *primary key constraints*)

- Usually listed *first* and *underlined*
	- ex:
		department(<u>dept_name</u>, building, budget)
	- in case it includes several attributes:
		classroom(<u>building</u>, <u>room_number</u>, capacity)

#### **Foreign Keys**

-> A **foreign-key constraint** from attribute(s) *A* (**foreign key**) in *r1* to the **primary key** *B* of *r2* states that **the values of A for each tuple in r1 must be the value of B for some tuple in r2**

- The **referencing relation** is one where the *foreign key exists* (r1)
- The **referenced relation** is the one *referenced by the foreign key* (r2)
	- `the referenced attributes must be the primary key of the referenced relation`
	- `in referential integrity constraints the referenced attributes must be a candidate key (the requirement above is relaxed)`

---

# PL 2

![[24_25-bd-pl2_sqlIntro.pdf]]

| keywords              | meaning                                          |
| --------------------- | ------------------------------------------------ |
| ==DISTINCT==          | to select the **unique argument** in between all |
| =="="==               | equal of                                         |
| ==<>==                | different of                                     |
| ==<==                 | if it is less than                               |
| ==>==                 | if it is greater than                            |
| ==">="==              | if it is greater or equal                        |
| =="<="==              | if it is less or equal                           |
| ==BETWEEN==           | to search between a range                        |
| ==LIKE==              | used to search in between a pattern              |
| ==IN==                | if it is                                         |
| ==WHERE (condition)== | to state a condition that it has to verify       |
| ==IS (or IS NOT)==    | to verify if the value corresponds to some other |
|                       |                                                  |
used to select the *unique argument* in between all. Ex: select

---
# TP 3

(E.R. diagram is relating the tables according to the relations below)

| Patient |
| ------- |
| pk      |

| Nurses          |
| --------------- |
| id           pk |

| Tests |
| ----- |
| pk    |

| Doctor |
| ------ |
| pk     |

| Speciality       |
| ---------------- |
| id            pk |

| Exams          |
| -------------- |
| id          pk |

| Type           |
| -------------- |
| id          pk |
| patient        |

*relations:*
- Nurses -||---o< Tests
- Patient >o---0|- Doctor
- Patient -||----o< Tests
- Patient -||--takes--o< Exams
- Exams >o----o< Doctor
- Exams >o-----||- Type
- Doctor >o------|< Speciality
- Tests   >o------||- Doctor
	

PS: **when its only ONE hospital (and not many) you don't need to create an Entity (table)**

PS: **Avoid NULL Foreign Keys (or keys in general)**

PS: **Define Values as UN (unique) - as we can't have more than one primary key, if we have more than one values and already have a pk, define the others as UN**
PS: **We avoid NULL FKs, so we also set them NN (not null)**

---

# PL 3

==Cartesian Product==

![[24_25-bd-pl3_sqlJunções.pdf]]

```sql
SELECT * FROM Cliente, Fatura
```

![[Pasted image 20250220185827.png]]
![[Pasted image 20250220185839.png]]

==Join (equi-junção)==

*without* join:

```sql
SELECT emp.nome, funcao, dep.nome
FROM emp, dep
WHERE emp.ndep = dep.ndep;
```

*with* join:

```sql
SELECT emp.nome, funcao, dep.nome
FROM emp JOIN dep
ON emp.ndep = dep.ndep;
```

![[Pasted image 20250220190443.png]]

could also be:

```sql
SELECT e.nome, funcao, d.nome
FROM emp AS e 
JOIN dep AS d
ON emp.ndep = dep.ndep;
```

==Inner Join==

- Join by defect.
- Only registers that respect the Join condition appear in the result.

```sql
SELECT emp.nome, emp.ndep, dep.ndep, dep.nome
FROM emp INNER JOIN dep
WHERE emp.ndep = dep.ndep;
```

![[Pasted image 20250221094553.png]]

==Outer Join==

- to join both Emp and Dep tables, independent of some employees not belonging to any department, nor some departments not having employees, outer join is required.

- *outer join* can be **==LEFT JOIN==** (on the left side of the table) or **RIGHT JOIN** (on the right side of the join condition)

==LEFT JOIN==
*warnings*
	**syntax** 
	-> the order of the tables presented in the table follows **only** the SELECT order
	-> the direction of the *LEFT JOIN* or *RIGHT JOIN* follows **only** the order of the written command. 
	e.g. 	```
```sql
FROM dep LEFT JOIN emp 
ON emp.NDEP = dep.NDEP;
```
 > *LEFT JOIN* means that all the correspondent elements in *emp* will join even if NULL 
 > 		**DEP JOINS EVEN IT LEFT ELEMENT IS NOT CORRESPONDED**
 > *RIGHT JOIN* means that all the correspondent elements in *dep* will join even if NULL
 > 		**EMP JOINS EVEN IF RIGHT ELEMENT IS NOT CORRESPONDED**

```sql
SELECT emp.NOME, emp.NDEP, dep.NDEP, dep.NOME
FROM dep LEFT JOIN emp ON emp.NDEP = dep.NDEP;
```

![[Pasted image 20250221095823.png]]

**BETWEEN**
```sql
SELECT NOME, SAL, ESCALAO
FROM emp, descontos
WHERE sal BETWEEN salinf AND salsup;
```

==Self (INNER) JOIN==

```sql
select e1.nemp, e1.nome, e1.encar, e2.nemp, e2.nome
from emp as e1, emp as e2
where e1.encar=e2.nemp;
```
> when displaying multiple characteristics repetitively, name the same attributes differently

### Relational Operators

![[Pasted image 20250306194813.png]]

__Compatibility in Union__
- Both must have the same number of columns
- The correspondent columns, in the relation must have the same type of data

==union with ALL==
```sql
SELECT nome, funcao, sal
FROM emp
WHERE ndep = 30
AND sal > 220000

UNION ALL

SELECT nome, funcao, sal
FROM emp
WHERE funcao = 'Vendedor'
```

==intersection with INTERSECT==
```sql
SELECT nome, funcao, sal
FROM emp
WHERE ndep = 30
AND sal > 220000

INTERSECT

SELECT nome, funcao, sal
FROM emp
WHERE funcao = 'Vendedor'
```

==exception with EXCEPT==
```sql
SELECT nome, funcao, sal
FROM emp
WHERE ndep = 30 AND sal > 220000

EXCEPT

SELECT nome, funcao, sal
FROM emp
WHERE funcao = 'Vendedor'
```

---

# T 3

## Weak Entity Sets

- A **weak entity set** is one whose *existence is dependent on another entity set*, called its **identifying entity set**
	- *only exists because of another (strong) entity set*

- An entity set that is not a weak entity set is termed a **strong entity set**

- Every weak entity must be associated with an identifying entity

- The relationship associating the weak entity set with the identifying entity set is called the **identifying relationship**

- The **primary key** of a weak entity **is the primary key of the identifying entity**, along with extra attributes

![[Pasted image 20250224121322.png]]

- A relationship may also have attributes, called **descriptive attributes**

- Such attributes may be represented in the form of **weak entity sets**

example:
![[Pasted image 20250224121426.png]]

## *n-ary* Relationships Sets

- Relationships in databases are mostly binary, but in some relationships appear to be **nonbinary** (*n-ary*)

- For example, one could create a **ternary relationship** parent, relating a child to his/her mother and father

![[Pasted image 20250224121544.png]]

- Relationships that appear to be nonbinary can actually be better represented by **several binary relationships**
	- The ternary relationship mother/father could also be represented by two binary relationships, mother and father
	- It is always possible to replace a nonbinary (n-ary, for n > 2) relationship set by a number of *distinct binary relationship sets* (but it might not always be the best choice)
		![[Pasted image 20250224121946.png]]

## Specialization

- An entity set may include **subgroupings** of entities that are **distinct in some way from other entities in the set**
	- i.e., a subset of entities within an entity set may have attributes that are not shared by all the entities in the entity set
	- e.g., the entity set person may be further classified as *employee or student*

- The process of **designating subgroupings within an entity** set is called **specialization**

- The *specialization of person* allows *distinguishing* among person entities according to whether they are employees or students

Person specialization:
![[Pasted image 20250224125527.png]]

## Overlapping and Disjoint Specialization

An entity may **belong** to **multiple specialized entity sets** OR it may belong to ***at most*** **one specialized entity set**

| **Overlapping specialization** | **Disjoint Specialization** |
| ------------------------------ | --------------------------- |
| *multiple* sets permitted      | at most *one* permitted     |

- The specialization relationship may also be referred to as a *superclass-subclass relationship*
- Not always identifiable in the diagram

*Person* specialization
![[Pasted image 20250224130114.png]]

Whether or not an entity in the *higher-level* entity set **must belong** to **at least one** of the *lower-level entity sets*
-> ==Total Specialization==

| **Total specialization**                                                                      | **Partial specialization**                                                                                 |
| --------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------- |
| each *higher-level* entity *must belong* <br>to a *lower-level* entity set                    | *some higher-level* entities *may not* <br>*belong* to *any lower-level* entity set                        |
| e.g., all persons in the university <br>database are either and employee <br>and/or a student | e.g., there are persons that are neither<br>employees nor students, but they are<br>in the database anyway |

---

# PL 4

## Character Manipulation functions

| Function                                             | Use                                                                                                   |
| ---------------------------------------------------- | ----------------------------------------------------------------------------------------------------- |
| ==**CONCAT**(str1,str2)==                            | *concatenates two strings                                                                             |
| ==**INITCAP**(str)==                                 | converts the *first letter* of *each word* to *higher case* (Capitalized) and the rest to lower case  |
| ==**LENGTH**(str)==                                  | gives the *length of a string*                                                                        |
| ==**LOWER**(str)== / ==**UPPER**(str)==              | converts ALL the characters of a string to *lower or *upper case                                      |
| ==**SUBSTR**(str, pos, \[n])==                       | gives *sub-strings* of the entry function beginning on the character *pos* and (facultative) size *n* |
| ==(REPLACE, POSITION, LPAD, RPAD, LTRIM, RTRIM...)== | <br>(other functions, search for them)                                                                |
## Numerical Functions

| Function                                         | Use                                                               |
| ------------------------------------------------ | ----------------------------------------------------------------- |
| ==**ROUND**(num,\[n])==                          | *rounds the value* to the closest integer if not specified        |
| ==**TRUNC**(num,\[n])==                          | does the same as round but truncates (*removes the decimal*)      |
| ==**CEIL**(num)==                                | gives the *lowest intege higher or equal* to the entry parameter  |
| ==**FLOOR**(num)==                               | gives the *highest intege lesser or equal* to the entry parameter |
| ==(ABS, MOD, POWER,<br>SQRT, SIN, COS, LOG...)== |                                                                   |
### Group functions

ex: 
```sql
SELECT funcao, MAX(sal)
FROM emp
GROUP BY funcao
HAVING MAX(sal) > 200000;
```

==**AVG()**==

- returns the average of the column values
```sql
SELECT funcao, AVG(sal)
FROM emp
GROUP BY funcao
ORDER BY funcao ASC;
```

==**COUNT(\*)**==

- returns all the values of the table values that are not null ("\*", which means all, can be another number)
```sql
SELECT COUNT(*) ”Todos”,
COUNT(sal) ”# salarios não nulos”,
COUNT(premios) ”# premios não nulos”
FROM emp;
```
example 2 (using the keyword DISTINCT):
```sql
SELECT COUNT(DISTINCT funcao)
FROM emp;
```

==**COALESCE(a, b)**==
- a: column name desired
- b: if NULL display this

==**MAX(parameter) + GROUP BY**==
```sql
SELECT funcao, MAX(sal)
FROM emp
GROUP BY funcao
HAVING MAX(sal) > 200000;
```

```output
"Analista"	565000
"Encarregado"	450975
"Presidente"	890000
"Vendedor"	221250
```
-  "*GROUP BY*" here is **mandatory** because we cannot use **grouping functions** (MAX()) without grouping data
- "*GROUP BY*" takes rows that the **same values** and groups them into **one**, where there can be done operations. 

order of commands:
***SELECT*** ->
***FROM*** ->
***WHERE*** -> restricts the data **before** the group by function
***GROUP BY*** ->
***HAVING*** -> restricts the groups themselves (the result of the group by) - relates to the properties of the elements restricted by groups
	ex:
```sql
WHERE NOT thumb HAVING size >= 4
```
***JOIN*** ->
***ON*** -> searches for the columns used in JOIN
***ORDER BY*** -> order elements selected following a pattern (ASC, DESC, \[parameter], ... )

---

# T 4

**Outline**
- Functional Dependencies
	- Functional Dependency Diagrams
	- Inference Rules
	- Minimum Coverage
- Normal Forms
	- Redundant and Duplicated Data
	- 1st Normal Form (1NF), 2nd Normal Form (2NF), 3rd Normal Form (3NF)
	- Boyce-Codd Normal Form (BCNF)
- Decomposition using Functional Dependencies

### Design Alternatives to reduce redundancy

example:
![[Pasted image 20250303113407.png]]

avoid:
	==Redundancy==
		-> a bad design may result in repeated information
	==Incompleteness==
		->  a bad design may make certain aspects of the enterprise difficult or impossible to model

design approaches

***Entity-Relationship Model (top-down)*** --> *large projects*
- *Entities* and *entity sets*
- *Relationships* and *relationship sets*
- *Cardinalities* and *participation*
- *Relational schema*

***Normalization Theory (bottom-up)*** --> *small projects*
- *Universal relation* and *primary key*
- Functional dependencies analysis
- *Normal forms*
- *Relational schema*

##### **Recommended: E-R + Normalization**

Design the **Entity-Relationship** (E-R) **diagram**

- *Entities* and *entity sets*
- *Relationships* and *relationship sets*
- *Cardinalities* and *participation*
- Obtain a *first relational schema*

Improve the schema using **functional dependencies** and **normalization**

- Identify the relations that need improvement or further refinement
- Identify functional dependencies
- Apply normal forms
- Obtain the final relational schema!

**X** ==**functionally determines**== **Y** if and only if (kinda primary keys): 
	*each X value in R is associated with precisely one Y value in R*
**Y** is **==functionally dependent==** on **X** if (**X determines Y**):
	*for every valid instance of X, that value of X uniquely determines the value of Y*

	written as: X --> Y

ex:
![[Pasted image 20250303122803.png]]

**Functional Dependency Diagrams**
![[Pasted image 20250303123052.png]]

#### Rules to reduce or change a set of Functional Dependencies (FDs)
(into another set of equivalent FDs)

- **Reflexive**: *if* Y is a subset of X, *then* X determines Y
- **Augmentation**: *if* X determines Y, *then* XZ determines YZ for any Z
- **Transitive**: *if* X determines Y *and* Y determines Z, *then* X also determines Z
- Union: if X determines Y and X determines Z, then X also determines Y and Z
- Decomposition: if X determines Y and Z, then X determines Y and X determines Z separately
- Pseudo transitive: if X determines Y and YZ determines W, then XZ determines W

---

# TP 5

## Transaction

- A logical unit of work that *must* be either *completed* or entirely *aborted*.
	- All SQL statements in the transaction must be **completed** successfully
	- If any **fail**, the ENTIRE transaction is **rolled back** to the original database state before the transaction (changes discarded)
- A successful transaction changes the db from one *consistent state* to another consistent state
	- "consistent state" -> ALL data integrity constraints are satisfied
- Most formed by two or more db requests

## Concurrency

![[Pasted image 20250310114100.png]]

- when many transactions take place *at the same time*
	- lets us assure the performance of a DBMS
- e.g. many users / programs access a DBMS at the same time -> many concurrent transactions

> prone PROBLEMS
> 	 Lost updates
> 	 Uncommitted data
> 	 Inconsistent retrievals

### Properties

1. ==Atomicity== 
	1. Requires that all operations (SQL requests) of a transaction be completed. If not, the transaction is aborted
2. ==Consistency== 
	1. Indicates the permanence of the database's consistent state
	2. A transaction takes a database from one consistent state to another 
3. ==Isolation==
	1. The data used during the execution of a transaction cannot be used by another transaction until the first one is completed
4. ==Durability==
	1. Transaction changes that are done and committed, cannot be undone or lost, even in the event of a system failure

### Serializability

- Ensures that the schedule for the *concurrent execution of the transactions yields consistent results*
	- The selected order of concurrent transaction operations leads to the same final state as if the transactions had been executed in a serial fashion
- If only a single transaction is executed, serializability is not an issue (but key when multiple transactions are likely to be executed concurrently over the same data)

### SQL

A transaction ends with: **COMMIT** or **ROLLBACK**

When a transaction is initiated, the sequence must continue through all SQL statements until:

- **COMMIT** 
	- All changes are permanently recorded within the database, and transaction ends
- **ROLLBACK**
	- All changes are aborted, database is rolled back, and transaction ends
- **End of a program**
	- All changes are permanently recorded within the database: equivalent to COMMIT
- **Program is abnormally terminated**
	- Database changes are aborted, database is rolled back: equivalent to ROLLBACK

example:
```sql
update product
set prod_qoh = prod_qok - 2
where prod_code = '1558-QW1';

update customer
set cust_balance = cust_balance + 87.98
where cust_number = '10011';

commit;
```
``good programming practice dictates that we should include COMMIT at the end of a transaction declaration``

*transaction begins **implicitly*** when the first SQL statement is reached

some DBMS (e.g. PostgreSQL) use transaction management statements to indicate the beginning of a new transaction
	e.g. **BEGIN TRANSACTION**

others allow assigning characteristics for the transaction such as parameters to the BEGIN statement
	e.g. Oracle uses the **SET TRANSACTION** statement to declare the start of a new transaction and its properties

read only transactions can only execute *select* statements
	**SET TRANSACTION READ ONLY**

> !! ATTENTION !! ==**Autocommit**==
> 	Each individual database interaction (i.e., each SQL statement) will be executed in its own *transaction that is ***implicitly committed***
> <u>Important</u>: a SQL statement executed in autocommit mode **cannot be rolled back** (e.g. *psql*)
> - You can explicitly start a transaction with **BEGIN TRANSACTION**
> - Autocommit can be turned off using **\set AUTOCOMMIT off**

### Savepoints

- works like a checkpoint for ***rollback***
	- restores the transaction state to what it was at the time of the savepoint
	- all savepoints are removed after the ending of the transaction

```sql
SAVEPOINT name
ROLLBACK TO SAVEPOINT name
RELEASE SAVEPOINT name
```

example:

```sql
begin;
insert into table1 values (1);
savepoint my_savepoint;
insert into table1 values (2);
rollback to savepoint my_savepoint;
insert into table1 values (3);
commit;
```
```sql
begin;
insert into table1 values (1);
savepoint my_savepoint;
insert into table1 values (2);
release savepoint my_savepoint;
insert into table1 values (3);
commit;
```

How to see the result?

## Transaction Log

- Used to **keep track of all transaction operations** that update the database
	- used for recovery purposes

> **It includes:**
> 	A record for the *beginning* of the transaction
> 	For *each transaction operation* (SQL statement):
> 		• *Type* of operation (INSERT, UPDATE, DELETE)
> 		• Names of the *objects* affected (the name of the table)
> 		• The “before” and “after” values for the fields *updated*
> 		• Pointers to the previous and next transaction log entries for the same transaction
> 	The ending (COMMIT) of the transaction

example of transaction log format:
![[Pasted image 20250310122828.png]]


# Concurrency Control

- To coordinate **simultaneous execution** of transactions in a **multiuser DS**
- oriented towards preserving the *isolation* property of concurrently executing transactions

Data integrity and consistency problems (assuming no concurrency mechanisms are in place):
- Lost updates
- Uncommitted data
- Inconsistent retrievals

### Lost Updates

Occurs when two concurrent transactions, T1 and T2, are *updating the same data* element and **one of the updates is lost** (overwritten)

![[Pasted image 20250310125728.png]]

### Uncommitted Data

Occurs when two transactions, T1 and T2, are executed concurrently and *T1 is rolled back after T2 has* **accessed the uncommitted data**

![[Pasted image 20250310130409.png]]

### Inconsistent Retrievals

Occur when a *transaction accesses data before and after one or more other transactions finish working with such data*
- The problem is that the transaction might read some data before it is changed and other data after it is changed

![[Pasted image 20250310130546.png]]

### The Scheduler

- Process that *establishes the order* in which the operations are executed within concurrent transactions

---

# PL 5

- In the **conceptual model** for an ER diagram there are ***NO  FOREIGN KEYS***
- Relations:
	- One to one does not exist
	- Many to many creates **always ONE table**, with their respective primary key and the foreign key of the other