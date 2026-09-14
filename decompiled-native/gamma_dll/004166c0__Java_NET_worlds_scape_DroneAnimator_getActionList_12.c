// 004166c0 _Java_NET_worlds_scape_DroneAnimator_getActionList@12 [Global]
// programa: gamma.dll

undefined4
_Java_NET_worlds_scape_DroneAnimator_getActionList_12(int *param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  
                    /* 0x166c0  214  _Java_NET_worlds_scape_DroneAnimator_getActionList@12 */
  if (DAT_004894fc != 0) {
    FUN_00402800(s_nDroneAnimator_0046fffc,0xb9);
  }
  DAT_00489500 = param_1;
  uVar1 = FUN_00415a40(param_1,DAT_004894f0,DAT_004894f8);
  DAT_004894fc = uVar1;
  FUN_00434e50(param_3,&LAB_00416680);
  DAT_00489500 = (int *)0x0;
  DAT_004894fc = 0;
  return uVar1;
}


