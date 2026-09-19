// 10049210 __ftell_lk [Global]
// programa: RWL21.DLL

/* Library Function - Single Match
    __ftell_lk
   
   Library: Visual Studio 1998 Release */

int __cdecl __ftell_lk(undefined4 *param_1)

{
  uint _FileHandle;
  byte bVar1;
  long _Offset;
  int iVar2;
  int *piVar3;
  long lVar4;
  char *pcVar5;
  char *pcVar6;
  uint uVar7;
  int local_4;
  
  _FileHandle = param_1[4];
  if ((int)param_1[1] < 0) {
    param_1[1] = 0;
  }
  _Offset = __lseek(_FileHandle,0,1);
  if (_Offset < 0) {
    return -1;
  }
  uVar7 = param_1[3];
  if ((uVar7 & 0x108) == 0) {
    return _Offset - param_1[1];
  }
  pcVar6 = (char *)param_1[2];
  iVar2 = (int)*param_1 - (int)pcVar6;
  local_4 = iVar2;
  if ((uVar7 & 3) == 0) {
    if ((uVar7 & 0x80) == 0) {
      piVar3 = FUN_100490e0();
      *piVar3 = 0x16;
      return -1;
    }
  }
  else if ((*(byte *)(*(int *)((int)&DAT_1005f6d0 + ((int)(_FileHandle & 0xffffffe7) >> 3)) + 4 +
                     (_FileHandle & 0x1f) * 0x24) & 0x80) != 0) {
    for (; pcVar6 < (char *)*param_1; pcVar6 = pcVar6 + 1) {
      if (*pcVar6 == '\n') {
        local_4 = local_4 + 1;
      }
    }
  }
  if (_Offset != 0) {
    if ((uVar7 & 1) != 0) {
      if (param_1[1] == 0) {
        local_4 = 0;
      }
      else {
        uVar7 = param_1[1] + iVar2;
        piVar3 = (int *)((int)&DAT_1005f6d0 + ((int)(_FileHandle & 0xffffffe7) >> 3));
        iVar2 = (_FileHandle & 0x1f) * 0x24;
        if ((*(byte *)(*piVar3 + 4 + iVar2) & 0x80) != 0) {
          lVar4 = __lseek(_FileHandle,0,2);
          if (lVar4 == _Offset) {
            pcVar5 = (char *)param_1[2];
            pcVar6 = pcVar5 + uVar7;
            for (; pcVar5 < pcVar6; pcVar5 = pcVar5 + 1) {
              if (*pcVar5 == '\n') {
                uVar7 = uVar7 + 1;
              }
            }
            bVar1 = *(byte *)((int)param_1 + 0xd) & 0x20;
          }
          else {
            __lseek(_FileHandle,_Offset,0);
            if (((0x200 < uVar7) || ((param_1[3] & 8) == 0)) ||
               (uVar7 = 0x200, (param_1[3] & 0x400) != 0)) {
              uVar7 = param_1[6];
            }
            bVar1 = *(byte *)(*piVar3 + 4 + iVar2) & 4;
          }
          if (bVar1 != 0) {
            uVar7 = uVar7 + 1;
          }
        }
        _Offset = _Offset - uVar7;
      }
    }
    return local_4 + _Offset;
  }
  return local_4;
}


