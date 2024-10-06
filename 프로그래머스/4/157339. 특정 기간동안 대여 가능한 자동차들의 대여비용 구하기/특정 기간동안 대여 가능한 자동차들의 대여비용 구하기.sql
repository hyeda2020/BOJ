select *
from (
    select a.CAR_ID, a.CAR_TYPE
    , ROUND((a.daily_fee * 30 * (100 - DISCOUNT_RATE) / 100)) as FEE
    from CAR_RENTAL_COMPANY_CAR a
    left outer join CAR_RENTAL_COMPANY_DISCOUNT_PLAN b
         on a.CAR_TYPE = b.CAR_TYPE
    where (a.CAR_TYPE = '세단' or a.CAR_TYPE = 'SUV')
      and b.DURATION_TYPE = '30일 이상'
      and a.CAR_ID not in (
        select car_id
        from CAR_RENTAL_COMPANY_RENTAL_HISTORY 
        where end_date >= '2022-11-01 00:00:00'
      )
) a
where FEE between '500000' and '2000000'
order by FEE desc, CAR_TYPE asc, CAR_ID desc

