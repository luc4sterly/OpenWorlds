// 004419b0 FUN_004419b0 [Global]
// programa: gamma.dll

undefined4 FUN_004419b0(int param_1)

{
  int *piVar1;
  HRESULT HVar2;
  int *piStack_c;
  
  piVar1 = (int *)(**(code **)(*(int *)(param_1 + -0x10) + 0xc4))();
  if (piVar1 == (int *)0x0) {
    return 1;
  }
  CoInitialize((LPVOID)0x0);
  HVar2 = CoCreateInstance((IID *)&DAT_00477fcc,(LPUNKNOWN)0x0,1,(IID *)&DAT_00467088,&piStack_c);
  if (-1 < HVar2) {
    FUN_00445e70(piVar1,piStack_c,1);
    (**(code **)(*piStack_c + 8))(piStack_c);
  }
  CoFreeUnusedLibraries();
  CoUninitialize();
  return 0;
}


