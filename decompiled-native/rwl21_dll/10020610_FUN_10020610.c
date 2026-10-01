// 10020610 FUN_10020610 [Global]
// program: RWL21.DLL

size_t FUN_10020610(FILE *param_1,uint *param_2,size_t param_3,int param_4)

{
  uint uVar1;
  size_t sVar2;
  int iVar3;
  
  sVar2 = _fread(param_2,1,param_3,param_1);
  if ((int)sVar2 < 1) {
    FUN_1000cba0(10);
  }
  else if (param_4 != 1) {
    if (param_4 == 2) {
      iVar3 = (int)param_3 / param_4 + -1;
      if (-1 < iVar3) {
        do {
          iVar3 = iVar3 + -1;
          *(ushort *)param_2 = CONCAT11((char)(short)*param_2,(char)((ushort)(short)*param_2 >> 8));
          param_2 = (uint *)((int)param_2 + 2);
        } while (-1 < iVar3);
        return sVar2;
      }
    }
    else {
      if (param_4 != 4) {
        FUN_1000cba0(0x6c);
        return sVar2;
      }
      iVar3 = (int)param_3 / param_4 + -1;
      if (-1 < iVar3) {
        do {
          uVar1 = *param_2;
          iVar3 = iVar3 + -1;
          *param_2 = (uVar1 & 0xff00 | uVar1 << 0x10) << 8 | (uVar1 & 0xff0000) >> 8 | uVar1 >> 0x18
          ;
          param_2 = param_2 + 1;
        } while (-1 < iVar3);
        return sVar2;
      }
    }
  }
  return sVar2;
}


