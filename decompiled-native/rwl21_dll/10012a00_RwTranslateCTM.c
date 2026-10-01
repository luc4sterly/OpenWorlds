// 10012a00 RwTranslateCTM [Global]
// program: RWL21.DLL

bool RwTranslateCTM(float param_1,float param_2,float param_3)

{
  float *pfVar1;
  int iVar2;
  
                    /* 0x12a00  517  RwTranslateCTM */
  iVar2 = 2;
  pfVar1 = (float *)FUN_1001d770();
  iVar2 = FUN_1001c820(pfVar1,param_1,param_2,param_3,iVar2);
  return (bool)('\x01' - (iVar2 == 0));
}


