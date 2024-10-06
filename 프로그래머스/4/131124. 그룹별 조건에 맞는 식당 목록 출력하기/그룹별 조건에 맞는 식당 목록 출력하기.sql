with GROUP_CNT as (
    SELECT a.MEMBER_ID
    , b.MEMBER_NAME
    , count(a.REVIEW_ID) as CNT
    from REST_REVIEW a
    left outer join MEMBER_PROFILE b
                 on a.MEMBER_ID = b.MEMBER_ID
    group by a.MEMBER_ID, b.MEMBER_NAME
)
select b.MEMBER_NAME
, a.REVIEW_TEXT
, DATE_FORMAT(a.REVIEW_DATE, '%Y-%m-%d') as REVIEW_DATE
from REST_REVIEW  a
inner join GROUP_CNT b
             on a.MEMBER_ID = b.MEMBER_ID
and b.CNT = (
    select max(CNT)
    from GROUP_CNT
)
order by REVIEW_DATE asc, REVIEW_TEXT asc