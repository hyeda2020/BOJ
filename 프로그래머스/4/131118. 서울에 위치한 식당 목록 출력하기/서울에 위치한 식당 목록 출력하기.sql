select REST_ID, REST_NAME, FOOD_TYPE, FAVORITES, ADDRESS,
round(AVG(REVIEW_SCORE), 2) as SCORE
from (
    select a.REST_ID, b.REST_NAME, b.FOOD_TYPE, b.FAVORITES, b.ADDRESS, a.REVIEW_SCORE
    from REST_REVIEW a
    inner join REST_INFO b
    on a.REST_ID = b.REST_ID
    and b.ADDRESS like '서울%'
) a
group by REST_ID
order by SCORE desc, FAVORITES desc