
#ifndef ___clutter_marshal_MARSHAL_H__
#define ___clutter_marshal_MARSHAL_H__

#include	<glib-object.h>

G_BEGIN_DECLS

/* BOOLEAN:BOXED (./clutter-marshal.list:1) */
extern void _clutter_marshal_BOOLEAN__BOXED (GClosure     *closure,
                                             GValue       *return_value,
                                             guint         n_param_values,
                                             const GValue *param_values,
                                             gpointer      invocation_hint,
                                             gpointer      marshal_data);

/* BOOLEAN:STRING,UINT,FLAGS (./clutter-marshal.list:2) */
extern void _clutter_marshal_BOOLEAN__STRING_UINT_FLAGS (GClosure     *closure,
                                                         GValue       *return_value,
                                                         guint         n_param_values,
                                                         const GValue *param_values,
                                                         gpointer      invocation_hint,
                                                         gpointer      marshal_data);

/* DOUBLE:VOID (./clutter-marshal.list:3) */
extern void _clutter_marshal_DOUBLE__VOID (GClosure     *closure,
                                           GValue       *return_value,
                                           guint         n_param_values,
                                           const GValue *param_values,
                                           gpointer      invocation_hint,
                                           gpointer      marshal_data);

/* UINT:VOID (./clutter-marshal.list:4) */
extern void _clutter_marshal_UINT__VOID (GClosure     *closure,
                                         GValue       *return_value,
                                         guint         n_param_values,
                                         const GValue *param_values,
                                         gpointer      invocation_hint,
                                         gpointer      marshal_data);

/* VOID:BOXED (./clutter-marshal.list:5) */
#define _clutter_marshal_VOID__BOXED	g_cclosure_marshal_VOID__BOXED

/* VOID:BOXED,FLAGS (./clutter-marshal.list:6) */
extern void _clutter_marshal_VOID__BOXED_FLAGS (GClosure     *closure,
                                                GValue       *return_value,
                                                guint         n_param_values,
                                                const GValue *param_values,
                                                gpointer      invocation_hint,
                                                gpointer      marshal_data);

/* VOID:INT (./clutter-marshal.list:7) */
#define _clutter_marshal_VOID__INT	g_cclosure_marshal_VOID__INT

/* VOID:INT64,INT64,FLOAT,BOOLEAN (./clutter-marshal.list:8) */
extern void _clutter_marshal_VOID__INT64_INT64_FLOAT_BOOLEAN (GClosure     *closure,
                                                              GValue       *return_value,
                                                              guint         n_param_values,
                                                              const GValue *param_values,
                                                              gpointer      invocation_hint,
                                                              gpointer      marshal_data);

/* VOID:INT,INT (./clutter-marshal.list:9) */
extern void _clutter_marshal_VOID__INT_INT (GClosure     *closure,
                                            GValue       *return_value,
                                            guint         n_param_values,
                                            const GValue *param_values,
                                            gpointer      invocation_hint,
                                            gpointer      marshal_data);

/* VOID:FLOAT,FLOAT (./clutter-marshal.list:10) */
extern void _clutter_marshal_VOID__FLOAT_FLOAT (GClosure     *closure,
                                                GValue       *return_value,
                                                guint         n_param_values,
                                                const GValue *param_values,
                                                gpointer      invocation_hint,
                                                gpointer      marshal_data);

/* VOID:INT,INT,INT,INT (./clutter-marshal.list:11) */
extern void _clutter_marshal_VOID__INT_INT_INT_INT (GClosure     *closure,
                                                    GValue       *return_value,
                                                    guint         n_param_values,
                                                    const GValue *param_values,
                                                    gpointer      invocation_hint,
                                                    gpointer      marshal_data);

/* VOID:OBJECT (./clutter-marshal.list:12) */
#define _clutter_marshal_VOID__OBJECT	g_cclosure_marshal_VOID__OBJECT

/* VOID:OBJECT,FLOAT,FLOAT (./clutter-marshal.list:13) */
extern void _clutter_marshal_VOID__OBJECT_FLOAT_FLOAT (GClosure     *closure,
                                                       GValue       *return_value,
                                                       guint         n_param_values,
                                                       const GValue *param_values,
                                                       gpointer      invocation_hint,
                                                       gpointer      marshal_data);

/* VOID:OBJECT,FLOAT,FLOAT,FLAGS (./clutter-marshal.list:14) */
extern void _clutter_marshal_VOID__OBJECT_FLOAT_FLOAT_FLAGS (GClosure     *closure,
                                                             GValue       *return_value,
                                                             guint         n_param_values,
                                                             const GValue *param_values,
                                                             gpointer      invocation_hint,
                                                             gpointer      marshal_data);

/* VOID:OBJECT,OBJECT,PARAM (./clutter-marshal.list:15) */
extern void _clutter_marshal_VOID__OBJECT_OBJECT_PARAM (GClosure     *closure,
                                                        GValue       *return_value,
                                                        guint         n_param_values,
                                                        const GValue *param_values,
                                                        gpointer      invocation_hint,
                                                        gpointer      marshal_data);

/* VOID:OBJECT,POINTER (./clutter-marshal.list:16) */
extern void _clutter_marshal_VOID__OBJECT_POINTER (GClosure     *closure,
                                                   GValue       *return_value,
                                                   guint         n_param_values,
                                                   const GValue *param_values,
                                                   gpointer      invocation_hint,
                                                   gpointer      marshal_data);

/* VOID:POINTER (./clutter-marshal.list:17) */
#define _clutter_marshal_VOID__POINTER	g_cclosure_marshal_VOID__POINTER

/* VOID:STRING,BOOLEAN,BOOLEAN (./clutter-marshal.list:18) */
extern void _clutter_marshal_VOID__STRING_BOOLEAN_BOOLEAN (GClosure     *closure,
                                                           GValue       *return_value,
                                                           guint         n_param_values,
                                                           const GValue *param_values,
                                                           gpointer      invocation_hint,
                                                           gpointer      marshal_data);

/* VOID:STRING,INT (./clutter-marshal.list:19) */
extern void _clutter_marshal_VOID__STRING_INT (GClosure     *closure,
                                               GValue       *return_value,
                                               guint         n_param_values,
                                               const GValue *param_values,
                                               gpointer      invocation_hint,
                                               gpointer      marshal_data);

/* VOID:UINT (./clutter-marshal.list:20) */
#define _clutter_marshal_VOID__UINT	g_cclosure_marshal_VOID__UINT

/* VOID:VOID (./clutter-marshal.list:21) */
#define _clutter_marshal_VOID__VOID	g_cclosure_marshal_VOID__VOID

/* VOID:STRING,INT,POINTER (./clutter-marshal.list:22) */
extern void _clutter_marshal_VOID__STRING_INT_POINTER (GClosure     *closure,
                                                       GValue       *return_value,
                                                       guint         n_param_values,
                                                       const GValue *param_values,
                                                       gpointer      invocation_hint,
                                                       gpointer      marshal_data);

G_END_DECLS

#endif /* ___clutter_marshal_MARSHAL_H__ */

