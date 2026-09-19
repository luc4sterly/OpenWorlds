// 10015f50 RwTransformCTM [Global]
// programa: RWL21.DLL

bool RwTransformCTM(int param_1)

{
  float *pfVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  int iVar2;
  
                    /* 0x15f50  506  RwTransformCTM */
  iVar2 = 1;
  pfVar1 = (float *)FUN_1001d770();
  iVar2 = FUN_1001c500(extraout_ECX,extraout_EDX,pfVar1,param_1,iVar2);
  return (bool)('\x01' - (iVar2 == 0));
}


