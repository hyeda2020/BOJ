select count(ID) as FISH_COUNT
, MAX(LENGTH) as MAX_LENGTH
, FISH_TYPE
from (
    select ID
        , FISH_TYPE
        , case when LENGTH is null then 10 else LENGTH end LENGTH
    from FISH_INFO
) a
group by FISH_TYPE
having avg(LENGTH) >= 33
order by FISH_TYPE
;