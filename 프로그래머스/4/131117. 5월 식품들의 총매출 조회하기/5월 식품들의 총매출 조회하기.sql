select PRODUCT_ID, PRODUCT_NAME, sum(AMOUNT * PRICE) as TOTAL_SALES
from (
    select a.PRODUCT_ID, b.PRODUCT_NAME, a.AMOUNT, b.PRICE
    from FOOD_ORDER a
    inner join FOOD_PRODUCT b
    on a.PRODUCT_ID = b.PRODUCT_ID
    where a.PRODUCE_DATE between '2022-05-01' and '2022-05-31'
) a
group by PRODUCT_ID
order by TOTAL_SALES desc, PRODUCT_ID asc