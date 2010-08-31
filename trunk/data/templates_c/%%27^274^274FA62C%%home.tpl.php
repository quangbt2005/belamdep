<?php /* Smarty version 2.6.20, created on 2010-07-01 14:54:14
         compiled from admin/home/home.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'number_format', 'admin/home/home.tpl', 21, false),)), $this); ?>
<div id="bigBox">
  <div class="box">
    <div class="left"></div>
    <div class="right"></div>
    <div class="heading">
      <h1 class="bkg_dashboard">Dashboard</h1>
    </div>
    <div class="content">
      <div class="header1">Đơn hàng mới nhất</div>
      <div class="blu-container" style="padding: 10px;">
        <table width="100%" class="vlist" cellpadding="0" cellspacing="0">
          <tr>
            <th>Khách hàng</th>
            <th>Tổng tiền</th>
            <th>Ngày đặt hàng</th>
            <th>Tình trạng</th>
          </tr>
          <?php $_from = $this->_tpl_vars['Orders']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['order']):
?>
          <tr onMouseOver="this.style.backgroundColor='#71FFB8';" onMouseOut="this.style.backgroundColor='transparent';">
            <td><?php echo $this->_tpl_vars['order']['customers_name']; ?>
</td>
            <td align="right"><?php echo smarty_number_format(array('number' => $this->_tpl_vars['order']['value']), $this);?>
&nbsp;VND</td>
            <td align="right"><?php echo $this->_tpl_vars['order']['date_purchased']; ?>
</td>
            <td><?php echo $this->_tpl_vars['order']['orders_status_name']; ?>
</td>
          </tr>
          <?php endforeach; endif; unset($_from); ?>
        </table>
      </div>
    </div>
  </div>
</div>