#导入
from pyecharts import options as opts
from pyecharts.charts import Pie
from pyecharts.faker import Faker

# 准备数据
lst=[['华为',1000],['小米',4000],['iPhone',500]]
c = (
    Pie()   #绘制饼图
    #.add("", [list(z) for z in zip(Faker.choose(), Faker.values())])
    .add('',lst)
    .set_colors(["blue", "green", "yellow", "red", "pink", "orange", "purple"])
    .set_global_opts(title_opts=opts.TitleOpts(title="2028年北京手机出库占比情况"))
    .set_series_opts(label_opts=opts.LabelOpts(formatter="{b}: {c}"))
    .render("Phone.html")
)
# print([list(z) for z in zip(Faker.choose(), Faker.values())])