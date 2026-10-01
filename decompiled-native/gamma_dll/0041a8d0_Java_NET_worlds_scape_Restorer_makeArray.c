// 0041a8d0 Java_NET_worlds_scape_Restorer_makeArray [Global]
// program: gamma.dll

/* class _jobject * __stdcall Java_NET_worlds_scape_Restorer_makeArray(struct JNIEnv_ *,class
   _jclass *,class _jclass *,long) */

_jobject *
Java_NET_worlds_scape_Restorer_makeArray
          (JNIEnv_ *param_1,_jclass *param_2,_jclass *param_3,long param_4)

{
  _jobject *p_Var1;
  
                    /* 0x1a8d0  6
                       ?Java_NET_worlds_scape_Restorer_makeArray@@YGPAV_jobject@@PAUJNIEnv_@@PAV_jclass@@1J@Z
                        */
  p_Var1 = (_jobject *)(**(code **)(*(int *)param_1 + 0x2b0))(param_1,param_4,param_3,0);
  return p_Var1;
}


