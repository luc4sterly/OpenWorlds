// 10010db0 RwScaleCTM [Global]
// programa: RWL21.DLL

bool RwScaleCTM(float param_1,float param_2,float param_3)

{
  float *pfVar1;
  int iVar2;
  
                    /* 0x10db0  360  RwScaleCTM */
  iVar2 = 2;
  pfVar1 = (float *)FUN_1001d770();
  iVar2 = FUN_1001c940(pfVar1,param_1,param_2,param_3,iVar2);
  return (bool)('\x01' - (iVar2 == 0));
}


