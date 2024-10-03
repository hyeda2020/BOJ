select a.ID
, b.FISH_NAME
, a.LENGTH
from FISH_INFO a
left outer join FISH_NAME_INFO b
             on a.FISH_TYPE = b.FISH_TYPE
where LENGTH = (select max(LENGTH) from FISH_INFO c where a.FISH_TYPE = c.FISH_TYPE)
order by a.ID asc
;