// 0043f450 _Java_NET_worlds_scape_DirectShow_nOpen@12 [Global]
// programa: gamma.dll

void _Java_NET_worlds_scape_DirectShow_nOpen_12(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int *piVar2;
  
                    /* 0x3f450  200  _Java_NET_worlds_scape_DirectShow_nOpen@12 */
  uVar1 = (**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
  piVar2 = (int *)(**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049def4);
  (**(code **)(*piVar2 + 0x14))(uVar1);
  piVar2 = (int *)(**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049def4);
  (**(code **)(*piVar2 + 0x20))();
  (**(code **)(*param_1 + 0x2a8))(param_1,param_3,uVar1);
  return;
}


