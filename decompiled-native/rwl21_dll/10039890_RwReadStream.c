// 10039890 RwReadStream [Global]
// program: RWL21.DLL

bool RwReadStream(int *param_1,undefined4 *param_2,uint param_3)

{
  FILE *_File;
  size_t sVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  
                    /* 0x39890  323  RwReadStream */
  if (((param_1 == (int *)0x0) || (param_2 == (undefined4 *)0x0)) || (param_3 == 0)) {
    FUN_1000cba0(1);
    return false;
  }
  if (param_1[1] != 1) {
    FUN_1000cba0(0x56);
    return false;
  }
  iVar4 = *param_1;
  if (0 < iVar4) {
    if (iVar4 < 3) {
      _File = (FILE *)param_1[2];
      sVar1 = _fread(param_2,1,param_3,_File);
      if (sVar1 != param_3) {
        if ((_File->_flag & 0x10U) == 0) {
          iVar4 = 10;
        }
        else {
          iVar4 = 0x58;
        }
        FUN_1000cba0(iVar4);
      }
      return sVar1 == param_3;
    }
    if (iVar4 == 3) {
      if ((uint)(param_1[3] - param_1[2]) < param_3) {
        FUN_1000cba0(0x58);
        return false;
      }
      puVar3 = (undefined4 *)(param_1[4] + param_1[2]);
      for (uVar2 = param_3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *param_2 = *puVar3;
        puVar3 = puVar3 + 1;
        param_2 = param_2 + 1;
      }
      for (uVar2 = param_3 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
        *(undefined1 *)param_2 = *(undefined1 *)puVar3;
        puVar3 = (undefined4 *)((int)puVar3 + 1);
        param_2 = (undefined4 *)((int)param_2 + 1);
      }
      param_1[2] = param_1[2] + param_3;
      return true;
    }
  }
  FUN_1000cba0(0x57);
  return false;
}


