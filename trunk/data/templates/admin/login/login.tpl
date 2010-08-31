<div id="loginContainer">
  <div id="loginBox" class="box">
    <div class="left"></div>
    <div class="right"></div>
    <div class="heading">
      <h1>Please enter your login details.</h1>
    </div>
    <div class="content" style="min-height: 150px;">
        <form action="/admin/login" method="post">
          <table style="width: 100%;">
            <tr>
              <td style="text-align: center;" rowspan="4"><img src="/images/admin/login.png" alt="Please enter your login details." /></td>
            </tr>
            <tr>
              <td>Username:<br />
                <input type="text" name="username" value="" style="margin-top: 4px;" /><br /><br />
                Password:<br />
                <input type="password" name="password" value="" style="margin-top: 4px;" />
              </td>
            </tr>
            <tr>
              <td>&nbsp;</td>
            </tr>
            <tr>
              <td style="text-align: right;"><input type="image" src="/images/admin/btn_login.png"></td>
            </tr>
          </table>
        </form>
    </div>
  </div>
</div>
