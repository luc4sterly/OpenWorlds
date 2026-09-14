// 00423370 _Java_NET_worlds_scape_ScapePicTexture_makeTexture@16 [Global]
// programa: gamma.dll

void _Java_NET_worlds_scape_ScapePicTexture_makeTexture_16
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int local_18;
  int local_14;
  
                    /* 0x23370  281  _Java_NET_worlds_scape_ScapePicTexture_makeTexture@16 */
  local_18 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049d194);
  local_14 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049d198);
  piVar1 = (int *)FUN_00422b30(param_1,param_3,param_4,1,(int *)0x0,&local_18,&local_14);
  (**(code **)(*param_1 + 0x1b4))(param_1,param_2,DAT_0049d194,local_18);
  (**(code **)(*param_1 + 0x1b4))(param_1,param_2,DAT_0049d198,local_14);
  if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
    (**(code **)(*param_1 + 0x1b4))(param_1,param_2,DAT_0049d190,*piVar1);
  }
  FUN_00451780(piVar1);
  return;
}


