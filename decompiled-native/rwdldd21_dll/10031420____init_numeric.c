// 10031420 ___init_numeric [Global]
// program: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___init_numeric
   
   Library: Visual Studio 1998 Release */

int __cdecl ___init_numeric(threadlocinfo *_LocInfo)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  void *unaff_EDI;
  uint _Lc_type;
  
  _Lc_type = (uint)DAT_10037d0a;
  if (DAT_10037898 != 0) {
    iVar1 = ___getlocaleinfo((_locale_t)0x1,_Lc_type,(LPCWSTR)0xe,0x10037cd8,unaff_EDI);
    iVar2 = ___getlocaleinfo((_locale_t)0x1,_Lc_type,(LPCWSTR)0xf,0x10037cdc,unaff_EDI);
    iVar3 = ___getlocaleinfo((_locale_t)0x1,_Lc_type,(LPCWSTR)0x10,0x10037ce0,unaff_EDI);
    fix_grouping(DAT_10037ce0);
    if ((iVar1 != 0 || iVar2 != 0) || iVar3 != 0) {
      _free(DAT_10037cd8);
      _free(DAT_10037cdc);
      _free(DAT_10037ce0);
      DAT_10037cd8 = (void *)0x0;
      DAT_10037cdc = (void *)0x0;
      DAT_10037ce0 = (char *)0x0;
      return -1;
    }
    if (*(undefined **)PTR_PTR_10038600 != &DAT_100385c8) {
      _free(*(undefined **)PTR_PTR_10038600);
      _free(*(void **)(PTR_PTR_10038600 + 4));
      _free(*(void **)(PTR_PTR_10038600 + 8));
    }
    *(void **)PTR_PTR_10038600 = DAT_10037cd8;
    *(void **)(PTR_PTR_10038600 + 4) = DAT_10037cdc;
    *(char **)(PTR_PTR_10038600 + 8) = DAT_10037ce0;
    _DAT_10036ee8 = 1;
    DAT_10036ee4 = **(undefined1 **)PTR_PTR_10038600;
    return 0;
  }
  _free(DAT_10037cd8);
  _free(DAT_10037cdc);
  _free(DAT_10037ce0);
  DAT_10037cd8 = (void *)0x0;
  DAT_10037cdc = (void *)0x0;
  DAT_10037ce0 = (char *)0x0;
  pvVar4 = _malloc(2);
  *(void **)PTR_PTR_10038600 = pvVar4;
  if (*(undefined2 **)PTR_PTR_10038600 == (undefined2 *)0x0) {
    return -1;
  }
  **(undefined2 **)PTR_PTR_10038600 = DAT_10034b94;
  pvVar4 = _malloc(2);
  *(void **)(PTR_PTR_10038600 + 4) = pvVar4;
  if (*(undefined1 **)(PTR_PTR_10038600 + 4) == (undefined1 *)0x0) {
    return -1;
  }
  **(undefined1 **)(PTR_PTR_10038600 + 4) = 0;
  pvVar4 = _malloc(2);
  *(void **)(PTR_PTR_10038600 + 8) = pvVar4;
  if (*(undefined1 **)(PTR_PTR_10038600 + 8) == (undefined1 *)0x0) {
    return -1;
  }
  **(undefined1 **)(PTR_PTR_10038600 + 8) = 0;
  _DAT_10036ee8 = 1;
  DAT_10036ee4 = **(undefined1 **)PTR_PTR_10038600;
  return 0;
}


