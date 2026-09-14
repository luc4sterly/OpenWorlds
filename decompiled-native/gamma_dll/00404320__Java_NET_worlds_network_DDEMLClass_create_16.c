// 00404320 _Java_NET_worlds_network_DDEMLClass_create@16 [Global]
// programa: gamma.dll

undefined1
_Java_NET_worlds_network_DDEMLClass_create_16
          (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  LPCSTR pCVar1;
  LPCSTR pCVar2;
  uint *this;
  
                    /* 0x4320  177  _Java_NET_worlds_network_DDEMLClass_create@16 */
  pCVar1 = (LPCSTR)(**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
  pCVar2 = (LPCSTR)(**(code **)(*param_1 + 0x2a4))(param_1,param_4,0);
  this = FUN_0044e010(0x18);
  if (this != (uint *)0x0) {
    FUN_00404140(this,pCVar1,pCVar2,0);
  }
  (**(code **)(*param_1 + 0x2a8))(param_1,param_3,pCVar1);
  (**(code **)(*param_1 + 0x2a8))(param_1,param_4,pCVar2);
  (**(code **)(*param_1 + 0x1b4))(param_1,param_2,DAT_0048907c,this);
  return (char)this[4];
}


