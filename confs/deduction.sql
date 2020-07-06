-- ----------------------------
-- Table structure for deduction
-- ----------------------------
-- 设计比较简单，该表中应该还有user_id, start_time, account(开通服务的账户)等。
-- 自动扣费模块应该还有扣费历史记录表，该表也和deduction表关联。
-- 自动扣费模块应该还有支付方式表，该表也和deduction表关联。

CREATE TABLE `deduction` (
  `id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `title` varchar(500) DEFAULT NULL COMMENT '扣费服务标题',
  `desc` varchar(500) DEFAULT NULL COMMENT '扣费服务描述',
  `status` int(11) DEFAULT NULL COMMENT '状态 ：枚举： 0->生效 1->失效',
  `pay_method_id` int(11) DEFAULT NULL COMMENT '当前支付方式',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8;