// 10016260 RwTransformJointTM [Global]
// program: RWL21.DLL

bool RwTransformJointTM(int param_1)

{
  float *pfVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  int iVar2;
  
                    /* 0x16260  512  RwTransformJointTM */
  iVar2 = 1;
  pfVar1 = (float *)FUN_1001d710(DAT_1005dfd0);
  iVar2 = FUN_1001c500(extraout_ECX,extraout_EDX,pfVar1,param_1,iVar2);
  return (bool)('\x01' - (iVar2 == 0));
}


