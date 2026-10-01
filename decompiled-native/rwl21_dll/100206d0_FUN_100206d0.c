// 100206d0 FUN_100206d0 [Global]
// program: RWL21.DLL

int FUN_100206d0(FILE *param_1,char *param_2,int param_3)

{
  bool bVar1;
  int _C;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  int local_4;
  
  do {
    do {
      _C = _fgetc(param_1);
    } while (_C == 0x20);
  } while (((_C == 0xd) || (_C == 9)) || (_C == 0xb));
  pcVar3 = param_2;
  if (_C == 0x22) {
    bVar1 = false;
    local_4 = 0;
    _C = _fgetc(param_1);
    while (((_C != -1 && (_C != 0xd)) && (_C != 10))) {
      if ((_C != 0x5c) || (bVar1)) {
        if ((_C == 0x22) && (!bVar1)) break;
        if (local_4 < param_3 + -1) {
          *pcVar3 = (char)_C;
          bVar1 = false;
          pcVar3 = pcVar3 + 1;
          local_4 = local_4 + 1;
        }
      }
      else {
        bVar1 = true;
      }
      _C = _fgetc(param_1);
    }
    if (_C == 0x22) goto LAB_100207c7;
  }
  else {
    iVar4 = 0;
    while (_C != -1) {
      if (DAT_1005bb4c < 2) {
        uVar2 = *(ushort *)(PTR_DAT_1005b940 + _C * 2) & 8;
      }
      else {
        uVar2 = __isctype(_C,8);
      }
      if (uVar2 != 0) break;
      if (iVar4 < param_3 + -1) {
        *pcVar3 = (char)_C;
        pcVar3 = pcVar3 + 1;
        iVar4 = iVar4 + 1;
      }
      _C = _fgetc(param_1);
    }
  }
  _ungetc(_C,param_1);
LAB_100207c7:
  *pcVar3 = '\0';
  if (*param_2 != '\0') {
    return 1;
  }
  return -(uint)(_C == -1);
}


