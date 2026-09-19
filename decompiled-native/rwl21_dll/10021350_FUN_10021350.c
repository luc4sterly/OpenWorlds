// 10021350 FUN_10021350 [Global]
// programa: RWL21.DLL

undefined4 * FUN_10021350(char *param_1,uint param_2)

{
  char *_Filename;
  char *pcVar1;
  FILE *_File;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  char local_40c [6];
  undefined1 auStack_406 [2];
  uint local_404;
  char local_400 [1024];
  
  local_40c[0] = 'Y';
  local_40c[1] = 0xa6;
  local_40c[2] = 0x6a;
  local_40c[3] = 0x95;
  local_404 = 0;
  if (param_1 == (char *)0x0) {
    FUN_1000cba0(1);
    return (undefined4 *)0x0;
  }
  if (((param_2 & 1) != 0) && ((param_2 & 2) != 0)) {
    FUN_1000cba0(0x3d);
    return (undefined4 *)0x0;
  }
  if ((param_2 & 0xffffff80) != 0) {
    FUN_1000cba0(0x3d);
    return (undefined4 *)0x0;
  }
  _Filename = (char *)FUN_10009ae0(param_1);
  if (_Filename == (char *)0x0) {
    pcVar1 = FUN_10043de0(param_1,&DAT_1005ad00,local_400);
    if (pcVar1 != (char *)0x0) {
      _Filename = (char *)FUN_10009ae0(local_400);
    }
    if (_Filename == (char *)0x0) {
      pcVar1 = FUN_10043de0(param_1,&DAT_1005acf8,local_400);
      if (pcVar1 != (char *)0x0) {
        _Filename = (char *)FUN_10009ae0(local_400);
      }
      goto LAB_1002141d;
    }
LAB_10021441:
    if (_Filename == (char *)0x0) {
      pcVar1 = FUN_10043de0(param_1,&DAT_1005ace8,local_400);
      if (pcVar1 != (char *)0x0) {
        _Filename = (char *)FUN_10009ae0(local_400);
      }
      goto LAB_10021465;
    }
LAB_10021489:
    if (_Filename == (char *)0x0) {
      FUN_1000cba0(0x2b);
      return (undefined4 *)0x0;
    }
  }
  else {
LAB_1002141d:
    if (_Filename == (char *)0x0) {
      pcVar1 = FUN_10043de0(param_1,&DAT_1005acf0,local_400);
      if (pcVar1 != (char *)0x0) {
        _Filename = (char *)FUN_10009ae0(local_400);
      }
      goto LAB_10021441;
    }
LAB_10021465:
    if (_Filename == (char *)0x0) {
      pcVar1 = FUN_10043de0(param_1,&DAT_1005ace0,local_400);
      if (pcVar1 != (char *)0x0) {
        _Filename = (char *)FUN_10009ae0(local_400);
      }
      goto LAB_10021489;
    }
  }
  _File = FID_conflict___wfopen(_Filename,&DAT_1005ad0c);
  if (_File == (FILE *)0x0) {
    FUN_1000cba0(0xe);
    return (undefined4 *)0x0;
  }
  puVar2 = FUN_10037030(DAT_1005acdc);
  if (puVar2 == (undefined4 *)0x0) {
    FUN_1000cba0(3);
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2[0xc] = 0;
    puVar2[0xf] = 0;
    puVar2[0xd] = 0;
    puVar2[0xe] = 0;
    puVar2[7] = 0;
    puVar2[8] = 0;
    puVar2[9] = 0;
    puVar2[1] = 0;
    iVar4 = (**(code **)(PTR_DAT_1005b69c + 0x2a0))(puVar2);
    if (iVar4 == 0) {
      FUN_10037010(DAT_1005acdc,puVar2);
      puVar2 = (undefined4 *)0x0;
    }
  }
  if (puVar2 != (undefined4 *)0x0) {
    uVar3 = (**(code **)(PTR_DAT_1005b69c + 0x350))(3,0x100);
    puVar2[0xd] = uVar3;
    puVar2[0xe] = 0x300;
    if ((puVar2 != (undefined4 *)0x0) && (puVar2[0xd] != 0)) {
      _fread(local_40c + 4,1,2,_File);
      iVar4 = _strncmp(local_40c + 4,&DAT_1005ad08,2);
      if (iVar4 == 0) {
        local_404 = FUN_10021620(_File,puVar2,(param_2 & 4) >> 2 | 2);
      }
      else {
        _fread(auStack_406,1,2,_File);
        iVar4 = _strncmp(local_40c + 4,local_40c,4);
        if (iVar4 == 0) {
          local_404 = FUN_10021da0(_File,puVar2,(param_2 & 4) >> 2 | 4);
        }
      }
      _fclose(_File);
      if ((local_404 != 0) && (puVar2[9] != 0)) {
        return puVar2;
      }
      goto LAB_10021601;
    }
  }
  FUN_1000cba0(3);
  if (puVar2 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
LAB_10021601:
  RwDestroyRaster(puVar2);
  return (undefined4 *)0x0;
}


