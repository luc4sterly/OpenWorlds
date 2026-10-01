// 00416620 _Java_NET_worlds_scape_DroneAnimator_getAnimationTime@16 [Global]
// program: gamma.dll

float10 _Java_NET_worlds_scape_DroneAnimator_getAnimationTime_16
                  (int *param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  byte *pbVar1;
  int *piVar2;
  float10 fVar3;
  
                    /* 0x16620  215  _Java_NET_worlds_scape_DroneAnimator_getAnimationTime@16 */
  pbVar1 = (byte *)(**(code **)(*param_1 + 0x2a4))(param_1,param_4,0);
  piVar2 = (int *)FUN_00402e90(param_1,param_2,&DAT_0046ffe0);
  fVar3 = FUN_00435630(piVar2,param_1,param_3,pbVar1);
  (**(code **)(*param_1 + 0x2a8))(param_1,param_4,pbVar1);
  return (float10)(float)fVar3;
}


