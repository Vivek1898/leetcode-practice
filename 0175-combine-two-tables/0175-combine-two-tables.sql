# Write your MySQL query statement below
sElect firstName,lastName,city,state from Person t1 left join Address t2 on t1.personId = t2.personId;
