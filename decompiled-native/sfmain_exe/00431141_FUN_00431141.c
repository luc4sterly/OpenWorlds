// 00431141 FUN_00431141 [Global]
// programa: sfmain.exe

longlong __fastcall FUN_00431141(undefined4 param_1,uint param_2)

{
  code *pcVar1;
  int iVar2;
  
  iVar2 = (*(code *)PTR_FUN_0043e7ec)();
  pcVar1 = *(code **)(iVar2 + 0x68);
  if (((pcVar1 != (code *)0x1) && (pcVar1 != (code *)0x2)) && (pcVar1 != (code *)0x3)) {
    iVar2 = (*(code *)PTR_FUN_0043e7ec)();
    *(undefined4 *)(iVar2 + 0x68) = 2;
    (*pcVar1)();
    return (ulonglong)param_2 << 0x20;
  }
  return CONCAT44(param_2,0xffffffff);
}


