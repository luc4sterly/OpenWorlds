// 00416740 _Java_NET_worlds_scape_DroneAnimator_update@28 [Global]
// programa: gamma.dll

void _Java_NET_worlds_scape_DroneAnimator_update_28
               (int *param_1,undefined4 param_2,int param_3,int param_4,uint param_5,float param_6)

{
  int iVar1;
  void *this;
  int iVar2;
  
                    /* 0x16740  223  _Java_NET_worlds_scape_DroneAnimator_update@28 */
  if (param_4 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_00412cf0(param_1,param_4);
  }
  if (param_3 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_00412cf0(param_1,param_3);
  }
  this = (void *)FUN_00402e90(param_1,param_2,&DAT_0046ffe0);
  FUN_00435520(this,param_5,iVar2,iVar1,param_6);
  return;
}


