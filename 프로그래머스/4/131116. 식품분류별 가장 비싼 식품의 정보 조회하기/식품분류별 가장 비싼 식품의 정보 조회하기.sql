select b.CATEGORY	
, b.PRICE as MAX_PRICE
, b.PRODUCT_NAME
from (select CATEGORY
, max(PRICE) as MAX_PRICE
from FOOD_PRODUCT
group by CATEGORY
) a, FOOD_PRODUCT b
where a.MAX_PRICE = b.PRICE
  and b.CATEGORY in (
    '과자', '국', '김치', '식용유'
  )
group by b.CATEGORY
order by b.price desc