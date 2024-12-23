SELECT * FROM sales

CREATE TABLE sales_temp
(
   stor_id        char(4)           NOT NULL

         REFERENCES stores(stor_id),

   ord_num        varchar(20)       NOT NULL,
   ord_date       datetime          NOT NULL,
   qty            smallint          NOT NULL,
   payterms       varchar(12)       NOT NULL,

   title_id       tid

         REFERENCES titles(title_id),


   CONSTRAINT UPKCL_sales_temp PRIMARY KEY CLUSTERED (stor_id, ord_num, title_id)
)

INSERT INTO sales_temp SELECT * FROM sales

SELECT * FROM sales_temp
SELECT * FROM sales