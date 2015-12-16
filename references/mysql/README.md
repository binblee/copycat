# MySQL


### No index

```
mysql> explain select * from code_area where code = 'b';
+----+-------------+-----------+------+---------------+------+---------+------+------+-------------+
| id | select_type | table     | type | possible_keys | key  | key_len | ref  | rows | Extra       |
+----+-------------+-----------+------+---------------+------+---------+------+------+-------------+
|  1 | SIMPLE      | code_area | ALL  | NULL          | NULL | NULL    | NULL |   27 | Using where |
+----+-------------+-----------+------+---------------+------+---------+------+------+-------------+
1 row in set (0.00 sec)

mysql> set profiling=1;
Query OK, 0 rows affected (0.00 sec)

mysql> select * from code_area where code = 'b';
+------+------+------+
| id   | code | area |
+------+------+------+
| NULL | b    | NULL |
| NULL | b    | NULL |
+------+------+------+
2 rows in set (0.00 sec)

mysql> show profile for query 1;
+--------------------------------+----------+
| Status                         | Duration |
+--------------------------------+----------+
| starting                       | 0.000022 |
| Waiting for query cache lock   | 0.000004 |
| checking query cache for query | 0.000008 |
| checking privileges on cached  | 0.000004 |
| checking permissions           | 0.000009 |
| sending cached result to clien | 0.000545 |
| logging slow query             | 0.000010 |
| cleaning up                    | 0.000004 |
+--------------------------------+----------+
8 rows in set (0.00 sec)
```

### Indexed

```
alter table code_area add index code_index (code);
```

Results

```
mysql> show profiles;
+----------+------------+---------------------------------------------------+
| Query_ID | Duration   | Query                                             |
+----------+------------+---------------------------------------------------+
|        1 | 0.00060575 | select * from code_area where code = 'b'          |
|        2 | 0.01989000 | alter table code_area add index code_index (code) |
|        3 | 0.00118025 | explain select * from code_area where code = 'b'  |
|        4 | 0.00097725 | set profiling=1                                   |
|        5 | 0.00080200 | select * from code_area where code = 'b'          |
+----------+------------+---------------------------------------------------+
5 rows in set (0.00 sec)


mysql> show profile for query 5;
+--------------------------------+----------+
| Status                         | Duration |
+--------------------------------+----------+
| starting                       | 0.000142 |
| Waiting for query cache lock   | 0.000004 |
| checking query cache for query | 0.000035 |
| checking permissions           | 0.000005 |
| Opening tables                 | 0.000016 |
| System lock                    | 0.000008 |
| Waiting for query cache lock   | 0.000019 |
| init                           | 0.000019 |
| optimizing                     | 0.000008 |
| statistics                     | 0.000037 |
| preparing                      | 0.000011 |
| executing                      | 0.000002 |
| Sending data                   | 0.000038 |
| end                            | 0.000003 |
| query end                      | 0.000003 |
| closing tables                 | 0.000005 |
| freeing items                  | 0.000005 |
| Waiting for query cache lock   | 0.000001 |
| freeing items                  | 0.000428 |
| Waiting for query cache lock   | 0.000006 |
| freeing items                  | 0.000002 |
| storing result in query cache  | 0.000003 |
| logging slow query             | 0.000002 |
| cleaning up                    | 0.000002 |
+--------------------------------+----------+
24 rows in set (0.00 sec)

mysql> explain select * from code_area where code = 'c';
+----+-------------+-----------+------+---------------+------------+---------+-------+------+-------------+
| id | select_type | table     | type | possible_keys | key        | key_len | ref   | rows | Extra       |
+----+-------------+-----------+------+---------------+------------+---------+-------+------+-------------+
|  1 | SIMPLE      | code_area | ref  | code_index    | code_index | 258     | const |    1 | Using where |
+----+-------------+-----------+------+---------------+------------+---------+-------+------+-------------+
1 row in set (0.00 sec)
```
