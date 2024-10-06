select FLAVOR
from (
    select FLAVOR
    , sum(TOTAL_ORDER) as TOT_SUM
    from (
        SELECT *
        from FIRST_HALF
        union
        select *
        from JULY 
    ) a
    group by FLAVOR
    order by TOT_SUM desc
) a
limit 3