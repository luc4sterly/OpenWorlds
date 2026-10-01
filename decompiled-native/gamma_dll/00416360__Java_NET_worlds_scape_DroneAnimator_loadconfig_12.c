// 00416360 _Java_NET_worlds_scape_DroneAnimator_loadconfig@12 [Global]
// program: gamma.dll

void _Java_NET_worlds_scape_DroneAnimator_loadconfig_12(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
                    /* 0x16360  219  _Java_NET_worlds_scape_DroneAnimator_loadconfig@12 */
  if (param_3 == 0) {
    FUN_00434b70(param_1,0);
    return;
  }
  iVar1 = (**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
  FUN_00434b70(param_1,iVar1);
  (**(code **)(*param_1 + 0x2a8))(param_1,param_3,iVar1);
  return;
}


