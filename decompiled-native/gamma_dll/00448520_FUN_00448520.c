// 00448520 FUN_00448520 [Global]
// programa: gamma.dll

undefined4 * __thiscall
FUN_00448520(void *this,undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  FUN_004437d0(this,param_2,param_3,(int)this + 0x74,param_1);
  *(undefined ***)this = &PTR_LAB_0047b8bc;
  *(undefined ***)((int)this + 0xc) = &PTR_LAB_0047b8d4;
  *(undefined ***)((int)this + 0x10) = &PTR_LAB_0047b918;
  *(undefined4 *)((int)this + 0x48) = 0;
  FUN_0044b240((void *)((int)this + 0x4c),0);
  FUN_0044b240((void *)((int)this + 0x50),1);
  FUN_0044b240((void *)((int)this + 0x54),1);
  *(undefined4 *)((int)this + 0x58) = 0;
  *(undefined4 *)((int)this + 0x5c) = 0;
  *(undefined4 *)((int)this + 0x60) = 0;
  *(undefined4 *)((int)this + 100) = 0;
  *(undefined4 *)((int)this + 0x68) = 0;
  *(undefined4 *)((int)this + 0x6c) = 0;
  *(undefined4 *)((int)this + 0x70) = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)((int)this + 0x74));
  InitializeCriticalSection((LPCRITICAL_SECTION)((int)this + 0x8c));
  *(undefined4 *)((int)this + 0xa4) = 0;
  *(undefined4 *)((int)this + 0xa8) = 1;
  *(undefined4 *)((int)this + 0xac) = 0;
  *(undefined4 *)((int)this + 0xb0) = 0;
  *(undefined4 *)((int)this + 0xb4) = 0;
  *(undefined4 *)((int)this + 0xb8) = 0;
  SetEvent(*(HANDLE *)((int)this + 0x54));
  return this;
}


