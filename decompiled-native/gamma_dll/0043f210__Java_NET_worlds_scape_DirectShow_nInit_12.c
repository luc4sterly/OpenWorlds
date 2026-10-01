// 0043f210 _Java_NET_worlds_scape_DirectShow_nInit@12 [Global]
// program: gamma.dll

void _Java_NET_worlds_scape_DirectShow_nInit_12(int *param_1,undefined4 param_2,int param_3)

{
  uint *this;
  int iVar1;
  
                    /* 0x3f210  199  _Java_NET_worlds_scape_DirectShow_nInit@12 */
  if (param_3 == 0) {
    this = FUN_0044e010(0x34);
    if (this != (uint *)0x0) {
      FUN_0043fdb0(this);
    }
  }
  else {
    this = FUN_0044e010(0x28);
    if (this != (uint *)0x0) {
      FUN_00440f60(this);
    }
    iVar1 = (**(code **)(*this + 8))();
    if (iVar1 == 0) {
      FUN_0044d5a0(s_Could_not_create_DirectX_8_media_00477cf0);
      if (this != (uint *)0x0) {
        (**(code **)*this)(1);
      }
      this = FUN_0044e010(0x60);
      if (this != (uint *)0x0) {
        FUN_00440320(this,param_3);
      }
      (**(code **)(*this + 8))();
    }
  }
  (**(code **)(*param_1 + 0x1b4))(param_1,param_2,DAT_0049def4,this);
  (**(code **)(*this + 8))();
  return;
}


