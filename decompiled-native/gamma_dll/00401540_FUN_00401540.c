// 00401540 FUN_00401540 [Global]
// program: gamma.dll

int * __thiscall FUN_00401540(void *this,LPCSTR param_1)

{
  int iVar1;
  DWORD dwBytes;
  HGLOBAL pvVar2;
  LPVOID pvVar3;
  uint uVar4;
  
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0xffffffff;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  iVar1 = FUN_00401610(param_1,0x8002);
  if (iVar1 != -1) {
    FUN_0044da60(iVar1,0,2);
    dwBytes = FUN_0044da60(iVar1,0,1);
    FUN_0044da60(iVar1,0,0);
    if (dwBytes != 0) {
      pvVar2 = GlobalAlloc(2,dwBytes);
      *(HGLOBAL *)this = pvVar2;
      if (*(int *)this != 0) {
        pvVar3 = GlobalLock(*(HGLOBAL *)this);
        *(LPVOID *)((int)this + 4) = pvVar3;
        if (*(int *)((int)this + 4) != 0) {
          uVar4 = FUN_0044dad0(iVar1,*(char **)((int)this + 4),dwBytes);
          if (dwBytes == uVar4) {
            *(DWORD *)((int)this + 8) = dwBytes;
          }
        }
      }
    }
    FUN_0044da00(iVar1);
  }
  if (*(int *)((int)this + 8) < 0) {
    FUN_00401630(this,param_1);
  }
  return this;
}


