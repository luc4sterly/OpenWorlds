// 004419a0 FUN_004419a0 [Global]
// program: gamma.dll

int FUN_004419a0(int param_1)

{
  int *piVar1;
  HRESULT HVar2;
  int *piStack_10;
  
  piVar1 = (int *)(**(code **)(*(int *)(param_1 + -0x10) + 0xc4))();
  if (piVar1 == (int *)0x0) {
    return 1;
  }
  CoInitialize((LPVOID)0x0);
  HVar2 = CoCreateInstance((IID *)&DAT_00477fcc,(LPUNKNOWN)0x0,1,(IID *)&DAT_00467088,&piStack_10);
  if (-1 < HVar2) {
    HVar2 = FUN_00445e70(piVar1,piStack_10,0);
    (**(code **)(*piStack_10 + 8))(piStack_10);
  }
  CoFreeUnusedLibraries();
  CoUninitialize();
  if (HVar2 == -0x7ff8fffe) {
    return 0;
  }
  return HVar2;
}


