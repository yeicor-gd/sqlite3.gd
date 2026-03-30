#include "Sqlite3Wrapper.h" // NOLINT(misc-include-cleaner)

#include <godot_cpp/classes/ref.hpp> // NOLINT(misc-include-cleaner)
#include <godot_cpp/core/class_db.hpp> // NOLINT(misc-include-cleaner)
#include <godot_cpp/variant/string.hpp> // NOLINT(misc-include-cleaner)
#include <cstddef> // NOLINT(misc-include-cleaner)
#include <cstdint> // NOLINT(misc-include-cleaner)
#include <cstdlib> // NOLINT(misc-include-cleaner)
#include <cstring> // NOLINT(misc-include-cleaner)
#include <mutex> // NOLINT(misc-include-cleaner)
#include <sqlite3.h> // NOLINT(misc-include-cleaner)
#include <unordered_map> // NOLINT(misc-include-cleaner)
#include <vector> // NOLINT(misc-include-cleaner)
#include "sqlite3.h" // NOLINT(misc-include-cleaner)

void Sqlite3Wrapper::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("version_string"), &Sqlite3Wrapper::version_string);
    godot::ClassDB::bind_method(godot::D_METHOD("version_number"), &Sqlite3Wrapper::version_number);
    godot::ClassDB::bind_method(godot::D_METHOD("source_id"), &Sqlite3Wrapper::source_id);
    godot::ClassDB::bind_method(godot::D_METHOD("scm_branch"), &Sqlite3Wrapper::scm_branch);
    godot::ClassDB::bind_method(godot::D_METHOD("scm_tags"), &Sqlite3Wrapper::scm_tags);
    godot::ClassDB::bind_method(godot::D_METHOD("scm_datetime"), &Sqlite3Wrapper::scm_datetime);
    godot::ClassDB::bind_method(godot::D_METHOD("libversion"), &Sqlite3Wrapper::libversion);
    godot::ClassDB::bind_method(godot::D_METHOD("sourceid"), &Sqlite3Wrapper::sourceid);
    godot::ClassDB::bind_method(godot::D_METHOD("libversion_number"), &Sqlite3Wrapper::libversion_number);
#ifndef SQLITE_OMIT_COMPILEOPTION_DIAGS
    godot::ClassDB::bind_method(godot::D_METHOD("compileoption_used", "option_name"), &Sqlite3Wrapper::compileoption_used);
#endif
#ifndef SQLITE_OMIT_COMPILEOPTION_DIAGS
    godot::ClassDB::bind_method(godot::D_METHOD("compileoption_get", "n"), &Sqlite3Wrapper::compileoption_get);
#endif
    godot::ClassDB::bind_method(godot::D_METHOD("threadsafe"), &Sqlite3Wrapper::threadsafe);
    godot::ClassDB::bind_method(godot::D_METHOD("close", "db"), &Sqlite3Wrapper::close);
    godot::ClassDB::bind_method(godot::D_METHOD("ok"), &Sqlite3Wrapper::ok);
    godot::ClassDB::bind_method(godot::D_METHOD("error"), &Sqlite3Wrapper::error);
    godot::ClassDB::bind_method(godot::D_METHOD("internal"), &Sqlite3Wrapper::internal);
    godot::ClassDB::bind_method(godot::D_METHOD("perm"), &Sqlite3Wrapper::perm);
    godot::ClassDB::bind_method(godot::D_METHOD("abort"), &Sqlite3Wrapper::abort);
    godot::ClassDB::bind_method(godot::D_METHOD("busy"), &Sqlite3Wrapper::busy);
    godot::ClassDB::bind_method(godot::D_METHOD("locked"), &Sqlite3Wrapper::locked);
    godot::ClassDB::bind_method(godot::D_METHOD("nomem"), &Sqlite3Wrapper::nomem);
    godot::ClassDB::bind_method(godot::D_METHOD("readonly"), &Sqlite3Wrapper::readonly);
    godot::ClassDB::bind_method(godot::D_METHOD("interrupt"), &Sqlite3Wrapper::interrupt);
    godot::ClassDB::bind_method(godot::D_METHOD("ioerr"), &Sqlite3Wrapper::ioerr);
    godot::ClassDB::bind_method(godot::D_METHOD("corrupt"), &Sqlite3Wrapper::corrupt);
    godot::ClassDB::bind_method(godot::D_METHOD("notfound"), &Sqlite3Wrapper::notfound);
    godot::ClassDB::bind_method(godot::D_METHOD("full"), &Sqlite3Wrapper::full);
    godot::ClassDB::bind_method(godot::D_METHOD("cantopen"), &Sqlite3Wrapper::cantopen);
    godot::ClassDB::bind_method(godot::D_METHOD("protocol"), &Sqlite3Wrapper::protocol);
    godot::ClassDB::bind_method(godot::D_METHOD("empty"), &Sqlite3Wrapper::empty);
    godot::ClassDB::bind_method(godot::D_METHOD("schema"), &Sqlite3Wrapper::schema);
    godot::ClassDB::bind_method(godot::D_METHOD("toobig"), &Sqlite3Wrapper::toobig);
    godot::ClassDB::bind_method(godot::D_METHOD("constraint"), &Sqlite3Wrapper::constraint);
    godot::ClassDB::bind_method(godot::D_METHOD("mismatch"), &Sqlite3Wrapper::mismatch);
    godot::ClassDB::bind_method(godot::D_METHOD("misuse"), &Sqlite3Wrapper::misuse);
    godot::ClassDB::bind_method(godot::D_METHOD("nolfs"), &Sqlite3Wrapper::nolfs);
    godot::ClassDB::bind_method(godot::D_METHOD("auth"), &Sqlite3Wrapper::auth);
    godot::ClassDB::bind_method(godot::D_METHOD("format"), &Sqlite3Wrapper::format);
    godot::ClassDB::bind_method(godot::D_METHOD("range"), &Sqlite3Wrapper::range);
    godot::ClassDB::bind_method(godot::D_METHOD("notadb"), &Sqlite3Wrapper::notadb);
    godot::ClassDB::bind_method(godot::D_METHOD("notice"), &Sqlite3Wrapper::notice);
    godot::ClassDB::bind_method(godot::D_METHOD("warning"), &Sqlite3Wrapper::warning);
    godot::ClassDB::bind_method(godot::D_METHOD("row"), &Sqlite3Wrapper::row);
    godot::ClassDB::bind_method(godot::D_METHOD("done"), &Sqlite3Wrapper::done);
    godot::ClassDB::bind_method(godot::D_METHOD("error_missing_collseq"), &Sqlite3Wrapper::error_missing_collseq);
    godot::ClassDB::bind_method(godot::D_METHOD("error_retry"), &Sqlite3Wrapper::error_retry);
    godot::ClassDB::bind_method(godot::D_METHOD("error_snapshot"), &Sqlite3Wrapper::error_snapshot);
    godot::ClassDB::bind_method(godot::D_METHOD("error_reservesize"), &Sqlite3Wrapper::error_reservesize);
    godot::ClassDB::bind_method(godot::D_METHOD("error_key"), &Sqlite3Wrapper::error_key);
    godot::ClassDB::bind_method(godot::D_METHOD("error_unable"), &Sqlite3Wrapper::error_unable);
    godot::ClassDB::bind_method(godot::D_METHOD("ioerr_read"), &Sqlite3Wrapper::ioerr_read);
    godot::ClassDB::bind_method(godot::D_METHOD("ioerr_short_read"), &Sqlite3Wrapper::ioerr_short_read);
    godot::ClassDB::bind_method(godot::D_METHOD("ioerr_write"), &Sqlite3Wrapper::ioerr_write);
    godot::ClassDB::bind_method(godot::D_METHOD("ioerr_fsync"), &Sqlite3Wrapper::ioerr_fsync);
    godot::ClassDB::bind_method(godot::D_METHOD("ioerr_dir_fsync"), &Sqlite3Wrapper::ioerr_dir_fsync);
    godot::ClassDB::bind_method(godot::D_METHOD("ioerr_truncate"), &Sqlite3Wrapper::ioerr_truncate);
    godot::ClassDB::bind_method(godot::D_METHOD("ioerr_fstat"), &Sqlite3Wrapper::ioerr_fstat);
    godot::ClassDB::bind_method(godot::D_METHOD("ioerr_unlock"), &Sqlite3Wrapper::ioerr_unlock);
    godot::ClassDB::bind_method(godot::D_METHOD("ioerr_rdlock"), &Sqlite3Wrapper::ioerr_rdlock);
    godot::ClassDB::bind_method(godot::D_METHOD("ioerr_delete"), &Sqlite3Wrapper::ioerr_delete);
    godot::ClassDB::bind_method(godot::D_METHOD("ioerr_blocked"), &Sqlite3Wrapper::ioerr_blocked);
    godot::ClassDB::bind_method(godot::D_METHOD("ioerr_nomem"), &Sqlite3Wrapper::ioerr_nomem);
    godot::ClassDB::bind_method(godot::D_METHOD("ioerr_access"), &Sqlite3Wrapper::ioerr_access);
    godot::ClassDB::bind_method(godot::D_METHOD("ioerr_checkreservedlock"), &Sqlite3Wrapper::ioerr_checkreservedlock);
    godot::ClassDB::bind_method(godot::D_METHOD("ioerr_lock"), &Sqlite3Wrapper::ioerr_lock);
    godot::ClassDB::bind_method(godot::D_METHOD("ioerr_close"), &Sqlite3Wrapper::ioerr_close);
    godot::ClassDB::bind_method(godot::D_METHOD("ioerr_dir_close"), &Sqlite3Wrapper::ioerr_dir_close);
    godot::ClassDB::bind_method(godot::D_METHOD("ioerr_shmopen"), &Sqlite3Wrapper::ioerr_shmopen);
    godot::ClassDB::bind_method(godot::D_METHOD("ioerr_shmsize"), &Sqlite3Wrapper::ioerr_shmsize);
    godot::ClassDB::bind_method(godot::D_METHOD("ioerr_shmlock"), &Sqlite3Wrapper::ioerr_shmlock);
    godot::ClassDB::bind_method(godot::D_METHOD("ioerr_shmmap"), &Sqlite3Wrapper::ioerr_shmmap);
    godot::ClassDB::bind_method(godot::D_METHOD("ioerr_seek"), &Sqlite3Wrapper::ioerr_seek);
    godot::ClassDB::bind_method(godot::D_METHOD("ioerr_delete_noent"), &Sqlite3Wrapper::ioerr_delete_noent);
    godot::ClassDB::bind_method(godot::D_METHOD("ioerr_mmap"), &Sqlite3Wrapper::ioerr_mmap);
    godot::ClassDB::bind_method(godot::D_METHOD("ioerr_gettemppath"), &Sqlite3Wrapper::ioerr_gettemppath);
    godot::ClassDB::bind_method(godot::D_METHOD("ioerr_convpath"), &Sqlite3Wrapper::ioerr_convpath);
    godot::ClassDB::bind_method(godot::D_METHOD("ioerr_vnode"), &Sqlite3Wrapper::ioerr_vnode);
    godot::ClassDB::bind_method(godot::D_METHOD("ioerr_auth"), &Sqlite3Wrapper::ioerr_auth);
    godot::ClassDB::bind_method(godot::D_METHOD("ioerr_begin_atomic"), &Sqlite3Wrapper::ioerr_begin_atomic);
    godot::ClassDB::bind_method(godot::D_METHOD("ioerr_commit_atomic"), &Sqlite3Wrapper::ioerr_commit_atomic);
    godot::ClassDB::bind_method(godot::D_METHOD("ioerr_rollback_atomic"), &Sqlite3Wrapper::ioerr_rollback_atomic);
    godot::ClassDB::bind_method(godot::D_METHOD("ioerr_data"), &Sqlite3Wrapper::ioerr_data);
    godot::ClassDB::bind_method(godot::D_METHOD("ioerr_corruptfs"), &Sqlite3Wrapper::ioerr_corruptfs);
    godot::ClassDB::bind_method(godot::D_METHOD("ioerr_in_page"), &Sqlite3Wrapper::ioerr_in_page);
    godot::ClassDB::bind_method(godot::D_METHOD("ioerr_badkey"), &Sqlite3Wrapper::ioerr_badkey);
    godot::ClassDB::bind_method(godot::D_METHOD("ioerr_codec"), &Sqlite3Wrapper::ioerr_codec);
    godot::ClassDB::bind_method(godot::D_METHOD("locked_sharedcache"), &Sqlite3Wrapper::locked_sharedcache);
    godot::ClassDB::bind_method(godot::D_METHOD("locked_vtab"), &Sqlite3Wrapper::locked_vtab);
    godot::ClassDB::bind_method(godot::D_METHOD("busy_recovery"), &Sqlite3Wrapper::busy_recovery);
    godot::ClassDB::bind_method(godot::D_METHOD("busy_snapshot"), &Sqlite3Wrapper::busy_snapshot);
    godot::ClassDB::bind_method(godot::D_METHOD("busy_timeout"), &Sqlite3Wrapper::busy_timeout);
    godot::ClassDB::bind_method(godot::D_METHOD("cantopen_notempdir"), &Sqlite3Wrapper::cantopen_notempdir);
    godot::ClassDB::bind_method(godot::D_METHOD("cantopen_isdir"), &Sqlite3Wrapper::cantopen_isdir);
    godot::ClassDB::bind_method(godot::D_METHOD("cantopen_fullpath"), &Sqlite3Wrapper::cantopen_fullpath);
    godot::ClassDB::bind_method(godot::D_METHOD("cantopen_convpath"), &Sqlite3Wrapper::cantopen_convpath);
    godot::ClassDB::bind_method(godot::D_METHOD("cantopen_dirtywal"), &Sqlite3Wrapper::cantopen_dirtywal);
    godot::ClassDB::bind_method(godot::D_METHOD("cantopen_symlink"), &Sqlite3Wrapper::cantopen_symlink);
    godot::ClassDB::bind_method(godot::D_METHOD("corrupt_vtab"), &Sqlite3Wrapper::corrupt_vtab);
    godot::ClassDB::bind_method(godot::D_METHOD("corrupt_sequence"), &Sqlite3Wrapper::corrupt_sequence);
    godot::ClassDB::bind_method(godot::D_METHOD("corrupt_index"), &Sqlite3Wrapper::corrupt_index);
    godot::ClassDB::bind_method(godot::D_METHOD("readonly_recovery"), &Sqlite3Wrapper::readonly_recovery);
    godot::ClassDB::bind_method(godot::D_METHOD("readonly_cantlock"), &Sqlite3Wrapper::readonly_cantlock);
    godot::ClassDB::bind_method(godot::D_METHOD("readonly_rollback"), &Sqlite3Wrapper::readonly_rollback);
    godot::ClassDB::bind_method(godot::D_METHOD("readonly_dbmoved"), &Sqlite3Wrapper::readonly_dbmoved);
    godot::ClassDB::bind_method(godot::D_METHOD("readonly_cantinit"), &Sqlite3Wrapper::readonly_cantinit);
    godot::ClassDB::bind_method(godot::D_METHOD("readonly_directory"), &Sqlite3Wrapper::readonly_directory);
    godot::ClassDB::bind_method(godot::D_METHOD("abort_rollback"), &Sqlite3Wrapper::abort_rollback);
    godot::ClassDB::bind_method(godot::D_METHOD("constraint_check"), &Sqlite3Wrapper::constraint_check);
    godot::ClassDB::bind_method(godot::D_METHOD("constraint_commithook"), &Sqlite3Wrapper::constraint_commithook);
    godot::ClassDB::bind_method(godot::D_METHOD("constraint_foreignkey"), &Sqlite3Wrapper::constraint_foreignkey);
    godot::ClassDB::bind_method(godot::D_METHOD("constraint_function"), &Sqlite3Wrapper::constraint_function);
    godot::ClassDB::bind_method(godot::D_METHOD("constraint_notnull"), &Sqlite3Wrapper::constraint_notnull);
    godot::ClassDB::bind_method(godot::D_METHOD("constraint_primarykey"), &Sqlite3Wrapper::constraint_primarykey);
    godot::ClassDB::bind_method(godot::D_METHOD("constraint_trigger"), &Sqlite3Wrapper::constraint_trigger);
    godot::ClassDB::bind_method(godot::D_METHOD("constraint_unique"), &Sqlite3Wrapper::constraint_unique);
    godot::ClassDB::bind_method(godot::D_METHOD("constraint_vtab"), &Sqlite3Wrapper::constraint_vtab);
    godot::ClassDB::bind_method(godot::D_METHOD("constraint_rowid"), &Sqlite3Wrapper::constraint_rowid);
    godot::ClassDB::bind_method(godot::D_METHOD("constraint_pinned"), &Sqlite3Wrapper::constraint_pinned);
    godot::ClassDB::bind_method(godot::D_METHOD("constraint_datatype"), &Sqlite3Wrapper::constraint_datatype);
    godot::ClassDB::bind_method(godot::D_METHOD("notice_recover_wal"), &Sqlite3Wrapper::notice_recover_wal);
    godot::ClassDB::bind_method(godot::D_METHOD("notice_recover_rollback"), &Sqlite3Wrapper::notice_recover_rollback);
    godot::ClassDB::bind_method(godot::D_METHOD("notice_rbu"), &Sqlite3Wrapper::notice_rbu);
    godot::ClassDB::bind_method(godot::D_METHOD("warning_autoindex"), &Sqlite3Wrapper::warning_autoindex);
    godot::ClassDB::bind_method(godot::D_METHOD("auth_user"), &Sqlite3Wrapper::auth_user);
    godot::ClassDB::bind_method(godot::D_METHOD("ok_load_permanently"), &Sqlite3Wrapper::ok_load_permanently);
    godot::ClassDB::bind_method(godot::D_METHOD("ok_symlink"), &Sqlite3Wrapper::ok_symlink);
    godot::ClassDB::bind_method(godot::D_METHOD("open_readonly"), &Sqlite3Wrapper::open_readonly);
    godot::ClassDB::bind_method(godot::D_METHOD("open_readwrite"), &Sqlite3Wrapper::open_readwrite);
    godot::ClassDB::bind_method(godot::D_METHOD("open_create"), &Sqlite3Wrapper::open_create);
    godot::ClassDB::bind_method(godot::D_METHOD("open_deleteonclose"), &Sqlite3Wrapper::open_deleteonclose);
    godot::ClassDB::bind_method(godot::D_METHOD("open_exclusive"), &Sqlite3Wrapper::open_exclusive);
    godot::ClassDB::bind_method(godot::D_METHOD("open_autoproxy"), &Sqlite3Wrapper::open_autoproxy);
    godot::ClassDB::bind_method(godot::D_METHOD("open_uri"), &Sqlite3Wrapper::open_uri);
    godot::ClassDB::bind_method(godot::D_METHOD("open_memory"), &Sqlite3Wrapper::open_memory);
    godot::ClassDB::bind_method(godot::D_METHOD("open_main_db"), &Sqlite3Wrapper::open_main_db);
    godot::ClassDB::bind_method(godot::D_METHOD("open_temp_db"), &Sqlite3Wrapper::open_temp_db);
    godot::ClassDB::bind_method(godot::D_METHOD("open_transient_db"), &Sqlite3Wrapper::open_transient_db);
    godot::ClassDB::bind_method(godot::D_METHOD("open_main_journal"), &Sqlite3Wrapper::open_main_journal);
    godot::ClassDB::bind_method(godot::D_METHOD("open_temp_journal"), &Sqlite3Wrapper::open_temp_journal);
    godot::ClassDB::bind_method(godot::D_METHOD("open_subjournal"), &Sqlite3Wrapper::open_subjournal);
    godot::ClassDB::bind_method(godot::D_METHOD("open_super_journal"), &Sqlite3Wrapper::open_super_journal);
    godot::ClassDB::bind_method(godot::D_METHOD("open_nomutex"), &Sqlite3Wrapper::open_nomutex);
    godot::ClassDB::bind_method(godot::D_METHOD("open_fullmutex"), &Sqlite3Wrapper::open_fullmutex);
    godot::ClassDB::bind_method(godot::D_METHOD("open_sharedcache"), &Sqlite3Wrapper::open_sharedcache);
    godot::ClassDB::bind_method(godot::D_METHOD("open_privatecache"), &Sqlite3Wrapper::open_privatecache);
    godot::ClassDB::bind_method(godot::D_METHOD("open_wal"), &Sqlite3Wrapper::open_wal);
    godot::ClassDB::bind_method(godot::D_METHOD("open_nofollow"), &Sqlite3Wrapper::open_nofollow);
    godot::ClassDB::bind_method(godot::D_METHOD("open_exrescode"), &Sqlite3Wrapper::open_exrescode);
    godot::ClassDB::bind_method(godot::D_METHOD("open_master_journal"), &Sqlite3Wrapper::open_master_journal);
    godot::ClassDB::bind_method(godot::D_METHOD("iocap_atomic"), &Sqlite3Wrapper::iocap_atomic);
    godot::ClassDB::bind_method(godot::D_METHOD("iocap_atomic512"), &Sqlite3Wrapper::iocap_atomic512);
    godot::ClassDB::bind_method(godot::D_METHOD("iocap_atomic1k"), &Sqlite3Wrapper::iocap_atomic1k);
    godot::ClassDB::bind_method(godot::D_METHOD("iocap_atomic2k"), &Sqlite3Wrapper::iocap_atomic2k);
    godot::ClassDB::bind_method(godot::D_METHOD("iocap_atomic4k"), &Sqlite3Wrapper::iocap_atomic4k);
    godot::ClassDB::bind_method(godot::D_METHOD("iocap_atomic8k"), &Sqlite3Wrapper::iocap_atomic8k);
    godot::ClassDB::bind_method(godot::D_METHOD("iocap_atomic16k"), &Sqlite3Wrapper::iocap_atomic16k);
    godot::ClassDB::bind_method(godot::D_METHOD("iocap_atomic32k"), &Sqlite3Wrapper::iocap_atomic32k);
    godot::ClassDB::bind_method(godot::D_METHOD("iocap_atomic64k"), &Sqlite3Wrapper::iocap_atomic64k);
    godot::ClassDB::bind_method(godot::D_METHOD("iocap_safe_append"), &Sqlite3Wrapper::iocap_safe_append);
    godot::ClassDB::bind_method(godot::D_METHOD("iocap_sequential"), &Sqlite3Wrapper::iocap_sequential);
    godot::ClassDB::bind_method(godot::D_METHOD("iocap_undeletable_when_open"), &Sqlite3Wrapper::iocap_undeletable_when_open);
    godot::ClassDB::bind_method(godot::D_METHOD("iocap_powersafe_overwrite"), &Sqlite3Wrapper::iocap_powersafe_overwrite);
    godot::ClassDB::bind_method(godot::D_METHOD("iocap_immutable"), &Sqlite3Wrapper::iocap_immutable);
    godot::ClassDB::bind_method(godot::D_METHOD("iocap_batch_atomic"), &Sqlite3Wrapper::iocap_batch_atomic);
    godot::ClassDB::bind_method(godot::D_METHOD("iocap_subpage_read"), &Sqlite3Wrapper::iocap_subpage_read);
    godot::ClassDB::bind_method(godot::D_METHOD("lock_none"), &Sqlite3Wrapper::lock_none);
    godot::ClassDB::bind_method(godot::D_METHOD("lock_shared"), &Sqlite3Wrapper::lock_shared);
    godot::ClassDB::bind_method(godot::D_METHOD("lock_reserved"), &Sqlite3Wrapper::lock_reserved);
    godot::ClassDB::bind_method(godot::D_METHOD("lock_pending"), &Sqlite3Wrapper::lock_pending);
    godot::ClassDB::bind_method(godot::D_METHOD("lock_exclusive"), &Sqlite3Wrapper::lock_exclusive);
    godot::ClassDB::bind_method(godot::D_METHOD("sync_normal"), &Sqlite3Wrapper::sync_normal);
    godot::ClassDB::bind_method(godot::D_METHOD("sync_full"), &Sqlite3Wrapper::sync_full);
    godot::ClassDB::bind_method(godot::D_METHOD("sync_dataonly"), &Sqlite3Wrapper::sync_dataonly);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_lockstate"), &Sqlite3Wrapper::fcntl_lockstate);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_get_lockproxyfile"), &Sqlite3Wrapper::fcntl_get_lockproxyfile);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_set_lockproxyfile"), &Sqlite3Wrapper::fcntl_set_lockproxyfile);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_last_errno"), &Sqlite3Wrapper::fcntl_last_errno);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_size_hint"), &Sqlite3Wrapper::fcntl_size_hint);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_chunk_size"), &Sqlite3Wrapper::fcntl_chunk_size);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_file_pointer"), &Sqlite3Wrapper::fcntl_file_pointer);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_sync_omitted"), &Sqlite3Wrapper::fcntl_sync_omitted);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_win32_av_retry"), &Sqlite3Wrapper::fcntl_win32_av_retry);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_persist_wal"), &Sqlite3Wrapper::fcntl_persist_wal);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_overwrite"), &Sqlite3Wrapper::fcntl_overwrite);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_vfsname"), &Sqlite3Wrapper::fcntl_vfsname);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_powersafe_overwrite"), &Sqlite3Wrapper::fcntl_powersafe_overwrite);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_pragma"), &Sqlite3Wrapper::fcntl_pragma);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_busyhandler"), &Sqlite3Wrapper::fcntl_busyhandler);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_tempfilename"), &Sqlite3Wrapper::fcntl_tempfilename);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_mmap_size"), &Sqlite3Wrapper::fcntl_mmap_size);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_trace"), &Sqlite3Wrapper::fcntl_trace);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_has_moved"), &Sqlite3Wrapper::fcntl_has_moved);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_sync"), &Sqlite3Wrapper::fcntl_sync);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_commit_phasetwo"), &Sqlite3Wrapper::fcntl_commit_phasetwo);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_win32_set_handle"), &Sqlite3Wrapper::fcntl_win32_set_handle);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_wal_block"), &Sqlite3Wrapper::fcntl_wal_block);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_zipvfs"), &Sqlite3Wrapper::fcntl_zipvfs);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_rbu"), &Sqlite3Wrapper::fcntl_rbu);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_vfs_pointer"), &Sqlite3Wrapper::fcntl_vfs_pointer);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_journal_pointer"), &Sqlite3Wrapper::fcntl_journal_pointer);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_win32_get_handle"), &Sqlite3Wrapper::fcntl_win32_get_handle);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_pdb"), &Sqlite3Wrapper::fcntl_pdb);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_begin_atomic_write"), &Sqlite3Wrapper::fcntl_begin_atomic_write);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_commit_atomic_write"), &Sqlite3Wrapper::fcntl_commit_atomic_write);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_rollback_atomic_write"), &Sqlite3Wrapper::fcntl_rollback_atomic_write);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_lock_timeout"), &Sqlite3Wrapper::fcntl_lock_timeout);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_data_version"), &Sqlite3Wrapper::fcntl_data_version);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_size_limit"), &Sqlite3Wrapper::fcntl_size_limit);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_ckpt_done"), &Sqlite3Wrapper::fcntl_ckpt_done);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_reserve_bytes"), &Sqlite3Wrapper::fcntl_reserve_bytes);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_ckpt_start"), &Sqlite3Wrapper::fcntl_ckpt_start);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_external_reader"), &Sqlite3Wrapper::fcntl_external_reader);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_cksm_file"), &Sqlite3Wrapper::fcntl_cksm_file);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_reset_cache"), &Sqlite3Wrapper::fcntl_reset_cache);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_null_io"), &Sqlite3Wrapper::fcntl_null_io);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_block_on_connect"), &Sqlite3Wrapper::fcntl_block_on_connect);
    godot::ClassDB::bind_method(godot::D_METHOD("fcntl_filestat"), &Sqlite3Wrapper::fcntl_filestat);
    godot::ClassDB::bind_method(godot::D_METHOD("get_lockproxyfile"), &Sqlite3Wrapper::get_lockproxyfile);
    godot::ClassDB::bind_method(godot::D_METHOD("set_lockproxyfile"), &Sqlite3Wrapper::set_lockproxyfile);
    godot::ClassDB::bind_method(godot::D_METHOD("last_errno"), &Sqlite3Wrapper::last_errno);
    godot::ClassDB::bind_method(godot::D_METHOD("access_exists"), &Sqlite3Wrapper::access_exists);
    godot::ClassDB::bind_method(godot::D_METHOD("access_readwrite"), &Sqlite3Wrapper::access_readwrite);
    godot::ClassDB::bind_method(godot::D_METHOD("access_read"), &Sqlite3Wrapper::access_read);
    godot::ClassDB::bind_method(godot::D_METHOD("shm_unlock"), &Sqlite3Wrapper::shm_unlock);
    godot::ClassDB::bind_method(godot::D_METHOD("shm_lock"), &Sqlite3Wrapper::shm_lock);
    godot::ClassDB::bind_method(godot::D_METHOD("shm_shared"), &Sqlite3Wrapper::shm_shared);
    godot::ClassDB::bind_method(godot::D_METHOD("shm_exclusive"), &Sqlite3Wrapper::shm_exclusive);
    godot::ClassDB::bind_method(godot::D_METHOD("shm_nlock"), &Sqlite3Wrapper::shm_nlock);
    godot::ClassDB::bind_method(godot::D_METHOD("initialize"), &Sqlite3Wrapper::initialize);
    godot::ClassDB::bind_method(godot::D_METHOD("shutdown"), &Sqlite3Wrapper::shutdown);
    godot::ClassDB::bind_method(godot::D_METHOD("os_init"), &Sqlite3Wrapper::os_init);
    godot::ClassDB::bind_method(godot::D_METHOD("os_end"), &Sqlite3Wrapper::os_end);
    godot::ClassDB::bind_method(godot::D_METHOD("config", "option"), &Sqlite3Wrapper::config);
    godot::ClassDB::bind_method(godot::D_METHOD("db_config", "db", "op", "args"), &Sqlite3Wrapper::db_config);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_config_singlethread"), &Sqlite3Wrapper::sqlite_config_singlethread);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_config_multithread"), &Sqlite3Wrapper::sqlite_config_multithread);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_config_serialized"), &Sqlite3Wrapper::sqlite_config_serialized);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_config_malloc"), &Sqlite3Wrapper::sqlite_config_malloc);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_config_getmalloc"), &Sqlite3Wrapper::sqlite_config_getmalloc);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_config_scratch"), &Sqlite3Wrapper::sqlite_config_scratch);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_config_pagecache"), &Sqlite3Wrapper::sqlite_config_pagecache);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_config_heap"), &Sqlite3Wrapper::sqlite_config_heap);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_config_memstatus"), &Sqlite3Wrapper::sqlite_config_memstatus);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_config_mutex"), &Sqlite3Wrapper::sqlite_config_mutex);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_config_getmutex"), &Sqlite3Wrapper::sqlite_config_getmutex);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_config_lookaside"), &Sqlite3Wrapper::sqlite_config_lookaside);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_config_pcache"), &Sqlite3Wrapper::sqlite_config_pcache);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_config_getpcache"), &Sqlite3Wrapper::sqlite_config_getpcache);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_config_log"), &Sqlite3Wrapper::sqlite_config_log);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_config_uri"), &Sqlite3Wrapper::sqlite_config_uri);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_config_pcache2"), &Sqlite3Wrapper::sqlite_config_pcache2);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_config_getpcache2"), &Sqlite3Wrapper::sqlite_config_getpcache2);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_config_covering_index_scan"), &Sqlite3Wrapper::sqlite_config_covering_index_scan);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_config_sqllog"), &Sqlite3Wrapper::sqlite_config_sqllog);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_config_mmap_size"), &Sqlite3Wrapper::sqlite_config_mmap_size);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_config_win32_heapsize"), &Sqlite3Wrapper::sqlite_config_win32_heapsize);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_config_pcache_hdrsz"), &Sqlite3Wrapper::sqlite_config_pcache_hdrsz);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_config_pmasz"), &Sqlite3Wrapper::sqlite_config_pmasz);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_config_stmtjrnl_spill"), &Sqlite3Wrapper::sqlite_config_stmtjrnl_spill);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_config_small_malloc"), &Sqlite3Wrapper::sqlite_config_small_malloc);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_config_sorterref_size"), &Sqlite3Wrapper::sqlite_config_sorterref_size);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_config_memdb_maxsize"), &Sqlite3Wrapper::sqlite_config_memdb_maxsize);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_config_rowid_in_view"), &Sqlite3Wrapper::sqlite_config_rowid_in_view);
    godot::ClassDB::bind_method(godot::D_METHOD("dbconfig_maindbname"), &Sqlite3Wrapper::dbconfig_maindbname);
    godot::ClassDB::bind_method(godot::D_METHOD("dbconfig_lookaside"), &Sqlite3Wrapper::dbconfig_lookaside);
    godot::ClassDB::bind_method(godot::D_METHOD("dbconfig_enable_fkey"), &Sqlite3Wrapper::dbconfig_enable_fkey);
    godot::ClassDB::bind_method(godot::D_METHOD("dbconfig_enable_trigger"), &Sqlite3Wrapper::dbconfig_enable_trigger);
    godot::ClassDB::bind_method(godot::D_METHOD("dbconfig_enable_fts3_tokenizer"), &Sqlite3Wrapper::dbconfig_enable_fts3_tokenizer);
    godot::ClassDB::bind_method(godot::D_METHOD("dbconfig_enable_load_extension"), &Sqlite3Wrapper::dbconfig_enable_load_extension);
    godot::ClassDB::bind_method(godot::D_METHOD("dbconfig_no_ckpt_on_close"), &Sqlite3Wrapper::dbconfig_no_ckpt_on_close);
    godot::ClassDB::bind_method(godot::D_METHOD("dbconfig_enable_qpsg"), &Sqlite3Wrapper::dbconfig_enable_qpsg);
    godot::ClassDB::bind_method(godot::D_METHOD("dbconfig_trigger_eqp"), &Sqlite3Wrapper::dbconfig_trigger_eqp);
    godot::ClassDB::bind_method(godot::D_METHOD("dbconfig_reset_database"), &Sqlite3Wrapper::dbconfig_reset_database);
    godot::ClassDB::bind_method(godot::D_METHOD("dbconfig_defensive"), &Sqlite3Wrapper::dbconfig_defensive);
    godot::ClassDB::bind_method(godot::D_METHOD("dbconfig_writable_schema"), &Sqlite3Wrapper::dbconfig_writable_schema);
    godot::ClassDB::bind_method(godot::D_METHOD("dbconfig_legacy_alter_table"), &Sqlite3Wrapper::dbconfig_legacy_alter_table);
    godot::ClassDB::bind_method(godot::D_METHOD("dbconfig_dqs_dml"), &Sqlite3Wrapper::dbconfig_dqs_dml);
    godot::ClassDB::bind_method(godot::D_METHOD("dqs_ddl"), &Sqlite3Wrapper::dqs_ddl);
    godot::ClassDB::bind_method(godot::D_METHOD("enable_view"), &Sqlite3Wrapper::enable_view);
    godot::ClassDB::bind_method(godot::D_METHOD("legacy_file_format"), &Sqlite3Wrapper::legacy_file_format);
    godot::ClassDB::bind_method(godot::D_METHOD("trusted_schema"), &Sqlite3Wrapper::trusted_schema);
    godot::ClassDB::bind_method(godot::D_METHOD("stmt_scanstatus"), &Sqlite3Wrapper::stmt_scanstatus);
    godot::ClassDB::bind_method(godot::D_METHOD("reverse_scanorder"), &Sqlite3Wrapper::reverse_scanorder);
    godot::ClassDB::bind_method(godot::D_METHOD("enable_attach_create"), &Sqlite3Wrapper::enable_attach_create);
    godot::ClassDB::bind_method(godot::D_METHOD("enable_attach_write"), &Sqlite3Wrapper::enable_attach_write);
    godot::ClassDB::bind_method(godot::D_METHOD("enable_comments"), &Sqlite3Wrapper::enable_comments);
    godot::ClassDB::bind_method(godot::D_METHOD("fp_digits"), &Sqlite3Wrapper::fp_digits);
    godot::ClassDB::bind_method(godot::D_METHOD("max"), &Sqlite3Wrapper::max);
    godot::ClassDB::bind_method(godot::D_METHOD("extended_result_codes", "db", "onoff"), &Sqlite3Wrapper::extended_result_codes);
    godot::ClassDB::bind_method(godot::D_METHOD("changes64", "db"), &Sqlite3Wrapper::changes64);
    godot::ClassDB::bind_method(godot::D_METHOD("total_changes64", "db"), &Sqlite3Wrapper::total_changes64);
    godot::ClassDB::bind_method(godot::D_METHOD("is_interrupted", "db"), &Sqlite3Wrapper::is_interrupted);
    godot::ClassDB::bind_method(godot::D_METHOD("complete16", "sql"), &Sqlite3Wrapper::complete16);
    godot::ClassDB::bind_method(godot::D_METHOD("busy_handler", "db", "handler"), &Sqlite3Wrapper::busy_handler);
    godot::ClassDB::bind_method(godot::D_METHOD("free_table", "result_ptr"), &Sqlite3Wrapper::free_table);
    godot::ClassDB::bind_method(godot::D_METHOD("mprintf", "format"), &Sqlite3Wrapper::mprintf);
    godot::ClassDB::bind_method(godot::D_METHOD("vmprintf", "format"), &Sqlite3Wrapper::vmprintf);
    godot::ClassDB::bind_method(godot::D_METHOD("malloc", "n_bytes"), &Sqlite3Wrapper::malloc);
    godot::ClassDB::bind_method(godot::D_METHOD("malloc64", "size"), &Sqlite3Wrapper::malloc64);
    godot::ClassDB::bind_method(godot::D_METHOD("realloc", "ptr", "size"), &Sqlite3Wrapper::realloc);
    godot::ClassDB::bind_method(godot::D_METHOD("realloc64", "ptr", "new_size"), &Sqlite3Wrapper::realloc64);
    godot::ClassDB::bind_method(godot::D_METHOD("msize", "ptr"), &Sqlite3Wrapper::msize);
    godot::ClassDB::bind_method(godot::D_METHOD("memory_used"), &Sqlite3Wrapper::memory_used);
    godot::ClassDB::bind_method(godot::D_METHOD("memory_highwater", "reset_flag"), &Sqlite3Wrapper::memory_highwater);
    godot::ClassDB::bind_method(godot::D_METHOD("randomness", "n"), &Sqlite3Wrapper::randomness);
    godot::ClassDB::bind_method(godot::D_METHOD("set_authorizer", "db", "x_auth"), &Sqlite3Wrapper::set_authorizer);
    godot::ClassDB::bind_method(godot::D_METHOD("trace", "db", "trace_callback"), &Sqlite3Wrapper::trace);
    godot::ClassDB::bind_method(godot::D_METHOD("trace_v2", "db", "mask", "callback"), &Sqlite3Wrapper::trace_v2);
    godot::ClassDB::bind_method(godot::D_METHOD("uri_parameter", "z", "z_param"), &Sqlite3Wrapper::uri_parameter);
    godot::ClassDB::bind_method(godot::D_METHOD("uri_boolean", "z", "z_param", "b_default"), &Sqlite3Wrapper::uri_boolean);
    godot::ClassDB::bind_method(godot::D_METHOD("uri_int64", "filename", "param", "default_value"), &Sqlite3Wrapper::uri_int64);
    godot::ClassDB::bind_method(godot::D_METHOD("uri_key", "z", "index"), &Sqlite3Wrapper::uri_key);
    godot::ClassDB::bind_method(godot::D_METHOD("filename_database", "filename"), &Sqlite3Wrapper::filename_database);
    godot::ClassDB::bind_method(godot::D_METHOD("filename_journal", "filename"), &Sqlite3Wrapper::filename_journal);
    godot::ClassDB::bind_method(godot::D_METHOD("filename_wal", "filename"), &Sqlite3Wrapper::filename_wal);
    godot::ClassDB::bind_method(godot::D_METHOD("database_file_object", "filename"), &Sqlite3Wrapper::database_file_object);
    godot::ClassDB::bind_method(godot::D_METHOD("create_filename", "database", "journal", "wal", "n_param", "az_param"), &Sqlite3Wrapper::create_filename);
    godot::ClassDB::bind_method(godot::D_METHOD("free_filename", "filename_ptr"), &Sqlite3Wrapper::free_filename);
    godot::ClassDB::bind_method(godot::D_METHOD("errcode", "db"), &Sqlite3Wrapper::errcode);
    godot::ClassDB::bind_method(godot::D_METHOD("extended_errcode", "db"), &Sqlite3Wrapper::extended_errcode);
    godot::ClassDB::bind_method(godot::D_METHOD("errmsg", "db"), &Sqlite3Wrapper::errmsg);
    godot::ClassDB::bind_method(godot::D_METHOD("errstr", "error_code"), &Sqlite3Wrapper::errstr);
    godot::ClassDB::bind_method(godot::D_METHOD("limit", "db", "id", "new_value"), &Sqlite3Wrapper::limit);
    godot::ClassDB::bind_method(godot::D_METHOD("expanded_sql", "p_stmt"), &Sqlite3Wrapper::expanded_sql);
    godot::ClassDB::bind_method(godot::D_METHOD("bind_blob", "stmt", "index", "data"), &Sqlite3Wrapper::bind_blob);
    godot::ClassDB::bind_method(godot::D_METHOD("bind_blob64", "stmt", "index", "blob", "destructor"), &Sqlite3Wrapper::bind_blob64);
    godot::ClassDB::bind_method(godot::D_METHOD("bind_int64", "stmt", "index", "value"), &Sqlite3Wrapper::bind_int64);
    godot::ClassDB::bind_method(godot::D_METHOD("bind_zeroblob", "stmt", "index", "n"), &Sqlite3Wrapper::bind_zeroblob);
    godot::ClassDB::bind_method(godot::D_METHOD("column_name16", "stmt", "n"), &Sqlite3Wrapper::column_name16);
    godot::ClassDB::bind_method(godot::D_METHOD("column_database_name16", "stmt", "col"), &Sqlite3Wrapper::column_database_name16);
    godot::ClassDB::bind_method(godot::D_METHOD("column_table_name", "stmt", "column"), &Sqlite3Wrapper::column_table_name);
    godot::ClassDB::bind_method(godot::D_METHOD("column_decltype16", "stmt", "col"), &Sqlite3Wrapper::column_decltype16);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_text"), &Sqlite3Wrapper::sqlite_text);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite3_text"), &Sqlite3Wrapper::sqlite3_text);
    godot::ClassDB::bind_method(godot::D_METHOD("column_blob", "stmt", "i_col"), &Sqlite3Wrapper::column_blob);
    godot::ClassDB::bind_method(godot::D_METHOD("column_double", "stmt", "i_col"), &Sqlite3Wrapper::column_double);
    godot::ClassDB::bind_method(godot::D_METHOD("column_int", "stmt", "i_col"), &Sqlite3Wrapper::column_int);
    godot::ClassDB::bind_method(godot::D_METHOD("column_int64", "stmt", "i_col"), &Sqlite3Wrapper::column_int64);
    godot::ClassDB::bind_method(godot::D_METHOD("value_blob", "value"), &Sqlite3Wrapper::value_blob);
    godot::ClassDB::bind_method(godot::D_METHOD("value_double", "value"), &Sqlite3Wrapper::value_double);
    godot::ClassDB::bind_method(godot::D_METHOD("value_int", "value"), &Sqlite3Wrapper::value_int);
    godot::ClassDB::bind_method(godot::D_METHOD("value_int64", "db_value"), &Sqlite3Wrapper::value_int64);
    godot::ClassDB::bind_method(godot::D_METHOD("value_pointer", "value", "type_name"), &Sqlite3Wrapper::value_pointer);
    godot::ClassDB::bind_method(godot::D_METHOD("value_bytes", "value"), &Sqlite3Wrapper::value_bytes);
    godot::ClassDB::bind_method(godot::D_METHOD("value_free", "value"), &Sqlite3Wrapper::value_free);
    godot::ClassDB::bind_method(godot::D_METHOD("set_auxdata", "context", "n", "auxdata", "destructor"), &Sqlite3Wrapper::set_auxdata);
    godot::ClassDB::bind_method(godot::D_METHOD("set_clientdata", "db", "key", "client_data_ptr", "cleanup_callback_ptr"), &Sqlite3Wrapper::set_clientdata);
    godot::ClassDB::bind_method(godot::D_METHOD("static_destructor_type"), &Sqlite3Wrapper::static_destructor_type);
    godot::ClassDB::bind_method(godot::D_METHOD("transient_destructor_type"), &Sqlite3Wrapper::transient_destructor_type);
    godot::ClassDB::bind_method(godot::D_METHOD("result_blob", "context", "data", "is_transient"), &Sqlite3Wrapper::result_blob);
    godot::ClassDB::bind_method(godot::D_METHOD("result_blob64", "ctx", "blob", "destructor"), &Sqlite3Wrapper::result_blob64);
    godot::ClassDB::bind_method(godot::D_METHOD("result_double", "ctx", "value"), &Sqlite3Wrapper::result_double);
    godot::ClassDB::bind_method(godot::D_METHOD("result_error16", "context", "error_message", "nbytes"), &Sqlite3Wrapper::result_error16);
    godot::ClassDB::bind_method(godot::D_METHOD("result_error_nomem", "ctx"), &Sqlite3Wrapper::result_error_nomem);
    godot::ClassDB::bind_method(godot::D_METHOD("result_value", "context", "value"), &Sqlite3Wrapper::result_value);
    godot::ClassDB::bind_method(godot::D_METHOD("create_collation_v2", "db", "name", "text_rep", "compare", "destroy"), &Sqlite3Wrapper::create_collation_v2);
    godot::ClassDB::bind_method(godot::D_METHOD("collation_needed16", "db", "callback"), &Sqlite3Wrapper::collation_needed16);
    godot::ClassDB::bind_method(godot::D_METHOD("get_temp_directory"), &Sqlite3Wrapper::get_temp_directory);
    godot::ClassDB::bind_method(godot::D_METHOD("set_temp_directory", "path"), &Sqlite3Wrapper::set_temp_directory);
    godot::ClassDB::bind_method(godot::D_METHOD("get_data_directory"), &Sqlite3Wrapper::get_data_directory);
    godot::ClassDB::bind_method(godot::D_METHOD("set_data_directory", "dir"), &Sqlite3Wrapper::set_data_directory);
#ifdef _WIN32
    godot::ClassDB::bind_method(godot::D_METHOD("win32_set_directory", "type", "z_value"), &Sqlite3Wrapper::win32_set_directory);
#endif
#ifdef _WIN32
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite3_win32_set_directory8", "type", "z_value"), &Sqlite3Wrapper::sqlite3_win32_set_directory8);
#endif
#ifdef _WIN32
    godot::ClassDB::bind_method(godot::D_METHOD("win32_set_directory16", "type", "value"), &Sqlite3Wrapper::win32_set_directory16);
#endif
#ifdef _WIN32
    godot::ClassDB::bind_method(godot::D_METHOD("win32_data_directory_type"), &Sqlite3Wrapper::win32_data_directory_type);
#endif
#ifdef _WIN32
    godot::ClassDB::bind_method(godot::D_METHOD("win32_temp_directory_type"), &Sqlite3Wrapper::win32_temp_directory_type);
#endif
    godot::ClassDB::bind_method(godot::D_METHOD("get_autocommit", "db"), &Sqlite3Wrapper::get_autocommit);
    godot::ClassDB::bind_method(godot::D_METHOD("next_stmt", "db", "stmt"), &Sqlite3Wrapper::next_stmt);
    godot::ClassDB::bind_method(godot::D_METHOD("rollback_hook", "db", "callback"), &Sqlite3Wrapper::rollback_hook);
    godot::ClassDB::bind_method(godot::D_METHOD("release_memory", "n"), &Sqlite3Wrapper::release_memory);
    godot::ClassDB::bind_method(godot::D_METHOD("db_release_memory", "db"), &Sqlite3Wrapper::db_release_memory);
    godot::ClassDB::bind_method(godot::D_METHOD("hard_heap_limit64", "n"), &Sqlite3Wrapper::hard_heap_limit64);
    godot::ClassDB::bind_method(godot::D_METHOD("soft_heap_limit", "n"), &Sqlite3Wrapper::soft_heap_limit);
    godot::ClassDB::bind_method(godot::D_METHOD("load_extension", "db", "file", "proc"), &Sqlite3Wrapper::load_extension);
    godot::ClassDB::bind_method(godot::D_METHOD("cancel_auto_extension", "x_entry_point"), &Sqlite3Wrapper::cancel_auto_extension);
    godot::ClassDB::bind_method(godot::D_METHOD("reset_auto_extension"), &Sqlite3Wrapper::reset_auto_extension);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_index_scan_unique"), &Sqlite3Wrapper::sqlite_index_scan_unique);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_index_scan_hex"), &Sqlite3Wrapper::sqlite_index_scan_hex);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_index_constraint_eq"), &Sqlite3Wrapper::sqlite_index_constraint_eq);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_index_constraint_gt"), &Sqlite3Wrapper::sqlite_index_constraint_gt);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_index_constraint_le"), &Sqlite3Wrapper::sqlite_index_constraint_le);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_index_constraint_lt"), &Sqlite3Wrapper::sqlite_index_constraint_lt);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_index_constraint_ge"), &Sqlite3Wrapper::sqlite_index_constraint_ge);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_index_constraint_match"), &Sqlite3Wrapper::sqlite_index_constraint_match);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_index_constraint_like"), &Sqlite3Wrapper::sqlite_index_constraint_like);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_index_constraint_glob"), &Sqlite3Wrapper::sqlite_index_constraint_glob);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_index_constraint_regexp"), &Sqlite3Wrapper::sqlite_index_constraint_regexp);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_index_constraint_ne"), &Sqlite3Wrapper::sqlite_index_constraint_ne);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_index_constraint_isnot"), &Sqlite3Wrapper::sqlite_index_constraint_isnot);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_index_constraint_isnotnull"), &Sqlite3Wrapper::sqlite_index_constraint_isnotnull);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_index_constraint_isnull"), &Sqlite3Wrapper::sqlite_index_constraint_isnull);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_index_constraint_is"), &Sqlite3Wrapper::sqlite_index_constraint_is);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_index_constraint_limit"), &Sqlite3Wrapper::sqlite_index_constraint_limit);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_index_constraint_offset"), &Sqlite3Wrapper::sqlite_index_constraint_offset);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_index_constraint_function"), &Sqlite3Wrapper::sqlite_index_constraint_function);
    godot::ClassDB::bind_method(godot::D_METHOD("create_module", "db", "z_name", "module", "client_data"), &Sqlite3Wrapper::create_module);
    godot::ClassDB::bind_method(godot::D_METHOD("blob_open", "db", "db_name", "table_name", "column_name", "row", "flags", "out_blob"), &Sqlite3Wrapper::blob_open);
    godot::ClassDB::bind_method(godot::D_METHOD("vfs_register", "vfs", "make_dflt"), &Sqlite3Wrapper::vfs_register);
    godot::ClassDB::bind_method(godot::D_METHOD("vfs_unregister", "vfs"), &Sqlite3Wrapper::vfs_unregister);
    godot::ClassDB::bind_method(godot::D_METHOD("mutex_free", "mutex"), &Sqlite3Wrapper::mutex_free);
    godot::ClassDB::bind_method(godot::D_METHOD("mutex_enter", "mutex"), &Sqlite3Wrapper::mutex_enter);
    godot::ClassDB::bind_method(godot::D_METHOD("mutex_try", "mutex"), &Sqlite3Wrapper::mutex_try);
    godot::ClassDB::bind_method(godot::D_METHOD("mutex_leave", "mutex"), &Sqlite3Wrapper::mutex_leave);
    godot::ClassDB::bind_method(godot::D_METHOD("db_mutex", "db"), &Sqlite3Wrapper::db_mutex);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_testctrl_first"), &Sqlite3Wrapper::sqlite_testctrl_first);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_testctrl_prng_save"), &Sqlite3Wrapper::sqlite_testctrl_prng_save);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_testctrl_prng_restore"), &Sqlite3Wrapper::sqlite_testctrl_prng_restore);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_testctrl_prng_reset"), &Sqlite3Wrapper::sqlite_testctrl_prng_reset);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_testctrl_fk_no_action"), &Sqlite3Wrapper::sqlite_testctrl_fk_no_action);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_testctrl_bitvec_test"), &Sqlite3Wrapper::sqlite_testctrl_bitvec_test);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_testctrl_fault_install"), &Sqlite3Wrapper::sqlite_testctrl_fault_install);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_testctrl_benign_malloc_hooks"), &Sqlite3Wrapper::sqlite_testctrl_benign_malloc_hooks);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_testctrl_pending_byte"), &Sqlite3Wrapper::sqlite_testctrl_pending_byte);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_testctrl_assert"), &Sqlite3Wrapper::sqlite_testctrl_assert);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_testctrl_always"), &Sqlite3Wrapper::sqlite_testctrl_always);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_testctrl_reserve"), &Sqlite3Wrapper::sqlite_testctrl_reserve);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_testctrl_json_selfcheck"), &Sqlite3Wrapper::sqlite_testctrl_json_selfcheck);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_testctrl_optimizations"), &Sqlite3Wrapper::sqlite_testctrl_optimizations);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_testctrl_iskeyword"), &Sqlite3Wrapper::sqlite_testctrl_iskeyword);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_testctrl_getopt"), &Sqlite3Wrapper::sqlite_testctrl_getopt);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_testctrl_scratchmalloc"), &Sqlite3Wrapper::sqlite_testctrl_scratchmalloc);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_testctrl_internal_functions"), &Sqlite3Wrapper::sqlite_testctrl_internal_functions);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_testctrl_localtime_fault"), &Sqlite3Wrapper::sqlite_testctrl_localtime_fault);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_testctrl_explain_stmt"), &Sqlite3Wrapper::sqlite_testctrl_explain_stmt);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_testctrl_once_reset_threshold"), &Sqlite3Wrapper::sqlite_testctrl_once_reset_threshold);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_testctrl_never_corrupt"), &Sqlite3Wrapper::sqlite_testctrl_never_corrupt);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_testctrl_vdbe_coverage"), &Sqlite3Wrapper::sqlite_testctrl_vdbe_coverage);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_testctrl_byteorder"), &Sqlite3Wrapper::sqlite_testctrl_byteorder);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_testctrl_isinit"), &Sqlite3Wrapper::sqlite_testctrl_isinit);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_testctrl_sorter_mmap"), &Sqlite3Wrapper::sqlite_testctrl_sorter_mmap);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_testctrl_imposter"), &Sqlite3Wrapper::sqlite_testctrl_imposter);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_testctrl_parser_coverage"), &Sqlite3Wrapper::sqlite_testctrl_parser_coverage);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_testctrl_result_intreal"), &Sqlite3Wrapper::sqlite_testctrl_result_intreal);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_testctrl_prng_seed"), &Sqlite3Wrapper::sqlite_testctrl_prng_seed);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_testctrl_extra_schema_checks"), &Sqlite3Wrapper::sqlite_testctrl_extra_schema_checks);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_testctrl_seek_count"), &Sqlite3Wrapper::sqlite_testctrl_seek_count);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_testctrl_traceflags"), &Sqlite3Wrapper::sqlite_testctrl_traceflags);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_testctrl_tune"), &Sqlite3Wrapper::sqlite_testctrl_tune);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_testctrl_logest"), &Sqlite3Wrapper::sqlite_testctrl_logest);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_testctrl_uselongdouble"), &Sqlite3Wrapper::sqlite_testctrl_uselongdouble);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_testctrl_last"), &Sqlite3Wrapper::sqlite_testctrl_last);
    godot::ClassDB::bind_method(godot::D_METHOD("keyword_count"), &Sqlite3Wrapper::keyword_count);
    godot::ClassDB::bind_method(godot::D_METHOD("keyword_name", "index"), &Sqlite3Wrapper::keyword_name);
    godot::ClassDB::bind_method(godot::D_METHOD("keyword_check", "word", "length"), &Sqlite3Wrapper::keyword_check);
    godot::ClassDB::bind_method(godot::D_METHOD("str_new", "db"), &Sqlite3Wrapper::str_new);
    godot::ClassDB::bind_method(godot::D_METHOD("str_free", "str"), &Sqlite3Wrapper::str_free);
    godot::ClassDB::bind_method(godot::D_METHOD("str_append", "str", "in", "n"), &Sqlite3Wrapper::str_append);
    godot::ClassDB::bind_method(godot::D_METHOD("str_appendall", "str", "z_in"), &Sqlite3Wrapper::str_appendall);
    godot::ClassDB::bind_method(godot::D_METHOD("str_appendchar", "str", "n", "c"), &Sqlite3Wrapper::str_appendchar);
    godot::ClassDB::bind_method(godot::D_METHOD("str_reset", "str"), &Sqlite3Wrapper::str_reset);
    godot::ClassDB::bind_method(godot::D_METHOD("str_truncate", "str", "n"), &Sqlite3Wrapper::str_truncate);
    godot::ClassDB::bind_method(godot::D_METHOD("str_length", "str"), &Sqlite3Wrapper::str_length);
    godot::ClassDB::bind_method(godot::D_METHOD("str_value", "str"), &Sqlite3Wrapper::str_value);
    godot::ClassDB::bind_method(godot::D_METHOD("status64", "op", "reset_highwater"), &Sqlite3Wrapper::status64);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_status_memory_used"), &Sqlite3Wrapper::sqlite_status_memory_used);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_status_pagecache_used"), &Sqlite3Wrapper::sqlite_status_pagecache_used);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_status_pagecache_overflow"), &Sqlite3Wrapper::sqlite_status_pagecache_overflow);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_status_scratch_used"), &Sqlite3Wrapper::sqlite_status_scratch_used);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_status_scratch_overflow"), &Sqlite3Wrapper::sqlite_status_scratch_overflow);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_status_malloc_size"), &Sqlite3Wrapper::sqlite_status_malloc_size);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_status_parser_stack"), &Sqlite3Wrapper::sqlite_status_parser_stack);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_status_pagecache_size"), &Sqlite3Wrapper::sqlite_status_pagecache_size);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_status_scratch_size"), &Sqlite3Wrapper::sqlite_status_scratch_size);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_status_malloc_count"), &Sqlite3Wrapper::sqlite_status_malloc_count);
    godot::ClassDB::bind_method(godot::D_METHOD("db_status", "db", "op", "reset_flg"), &Sqlite3Wrapper::db_status);
    godot::ClassDB::bind_method(godot::D_METHOD("db_status64", "db", "op", "reset_highwater"), &Sqlite3Wrapper::db_status64);
    godot::ClassDB::bind_method(godot::D_METHOD("stmt_status", "stmt", "op", "reset_flag"), &Sqlite3Wrapper::stmt_status);
    godot::ClassDB::bind_method(godot::D_METHOD("backup_step", "db_backup", "n_page"), &Sqlite3Wrapper::backup_step);
    godot::ClassDB::bind_method(godot::D_METHOD("backup_finish", "p"), &Sqlite3Wrapper::backup_finish);
    godot::ClassDB::bind_method(godot::D_METHOD("backup_remaining", "p"), &Sqlite3Wrapper::backup_remaining);
    godot::ClassDB::bind_method(godot::D_METHOD("strnicmp", "s1", "s2", "n"), &Sqlite3Wrapper::strnicmp);
    godot::ClassDB::bind_method(godot::D_METHOD("strglob", "glob", "str"), &Sqlite3Wrapper::strglob);
    godot::ClassDB::bind_method(godot::D_METHOD("strlike", "pattern", "input", "escape_char"), &Sqlite3Wrapper::strlike);
    godot::ClassDB::bind_method(godot::D_METHOD("log", "i_err_code", "format", "args"), &Sqlite3Wrapper::log);
    godot::ClassDB::bind_method(godot::D_METHOD("wal_hook", "db", "callback", "user_data"), &Sqlite3Wrapper::wal_hook);
    godot::ClassDB::bind_method(godot::D_METHOD("vtab_config", "db", "op", "args"), &Sqlite3Wrapper::vtab_config);
    godot::ClassDB::bind_method(godot::D_METHOD("vtab_on_conflict", "db"), &Sqlite3Wrapper::vtab_on_conflict);
    godot::ClassDB::bind_method(godot::D_METHOD("vtab_in_next", "p_val", "out_pp_out"), &Sqlite3Wrapper::vtab_in_next);
#ifdef SQLITE_ENABLE_STMT_SCANSTATUS
    godot::ClassDB::bind_method(godot::D_METHOD("stmt_scanstatus_int", "stmt", "idx", "scan_status_op"), &Sqlite3Wrapper::stmt_scanstatus_int);
#endif
#ifdef SQLITE_ENABLE_STMT_SCANSTATUS
    godot::ClassDB::bind_method(godot::D_METHOD("stmt_scanstatus_double", "stmt", "idx", "scan_status_op"), &Sqlite3Wrapper::stmt_scanstatus_double);
#endif
#ifdef SQLITE_ENABLE_STMT_SCANSTATUS
    godot::ClassDB::bind_method(godot::D_METHOD("stmt_scanstatus_string", "stmt", "idx", "scan_status_op"), &Sqlite3Wrapper::stmt_scanstatus_string);
#endif
    godot::ClassDB::bind_method(godot::D_METHOD("scanstat_complex"), &Sqlite3Wrapper::scanstat_complex);
#ifdef SQLITE_ENABLE_SNAPSHOT
    godot::ClassDB::bind_method(godot::D_METHOD("snapshot_get", "db", "schema", "out_snapshot"), &Sqlite3Wrapper::snapshot_get);
#endif
#ifdef SQLITE_ENABLE_SNAPSHOT
    godot::ClassDB::bind_method(godot::D_METHOD("snapshot_free", "snapshot"), &Sqlite3Wrapper::snapshot_free);
#endif
#ifndef SQLITE_OMIT_DESERIALIZE
    godot::ClassDB::bind_method(godot::D_METHOD("deserialize", "db", "schema", "p_data", "sz_db", "sz_buf", "flags"), &Sqlite3Wrapper::deserialize);
#endif
    godot::ClassDB::bind_method(godot::D_METHOD("carray_bind_v2", "stmt", "index", "data", "n_elements", "flags", "x_del", "p_del"), &Sqlite3Wrapper::carray_bind_v2);
    godot::ClassDB::bind_method(godot::D_METHOD("rtree_geometry_callback", "db", "z_geom", "x_geom"), &Sqlite3Wrapper::rtree_geometry_callback);
    godot::ClassDB::bind_method(godot::D_METHOD("rtree_query_callback", "db", "z_query_func", "x_query_func", "p_context", "x_destructor"), &Sqlite3Wrapper::rtree_query_callback);
    godot::ClassDB::bind_method(godot::D_METHOD("not_within"), &Sqlite3Wrapper::not_within);
    godot::ClassDB::bind_method(godot::D_METHOD("partly_within"), &Sqlite3Wrapper::partly_within);
    godot::ClassDB::bind_method(godot::D_METHOD("fully_within"), &Sqlite3Wrapper::fully_within);
    godot::ClassDB::bind_method(godot::D_METHOD("session_create", "db", "z_db", "out_session"), &Sqlite3Wrapper::session_create);
    godot::ClassDB::bind_method(godot::D_METHOD("session_enable", "session", "enable"), &Sqlite3Wrapper::session_enable);
    godot::ClassDB::bind_method(godot::D_METHOD("session_memory_used", "p_session"), &Sqlite3Wrapper::session_memory_used);
    godot::ClassDB::bind_method(godot::D_METHOD("changeset_start_v2", "changeset", "flags", "out_iter"), &Sqlite3Wrapper::changeset_start_v2);
    godot::ClassDB::bind_method(godot::D_METHOD("next", "p_iter"), &Sqlite3Wrapper::next);
    godot::ClassDB::bind_method(godot::D_METHOD("changeset_concat", "a", "b"), &Sqlite3Wrapper::changeset_concat);
    godot::ClassDB::bind_method(godot::D_METHOD("create"), &Sqlite3Wrapper::create);
    godot::ClassDB::bind_method(godot::D_METHOD("changegroup_delete", "changegroup"), &Sqlite3Wrapper::changegroup_delete);
    godot::ClassDB::bind_method(godot::D_METHOD("rebaser_create", "out_handle"), &Sqlite3Wrapper::rebaser_create);
    godot::ClassDB::bind_method(godot::D_METHOD("configure", "rebaser", "rebase_buffer"), &Sqlite3Wrapper::configure);
    godot::ClassDB::bind_method(godot::D_METHOD("rebaser_delete", "p_rebaser"), &Sqlite3Wrapper::rebaser_delete);
    godot::ClassDB::bind_method(godot::D_METHOD("changeset_concat_strm", "x_input_a", "in_a", "x_input_b", "in_b", "x_output", "out"), &Sqlite3Wrapper::changeset_concat_strm);
    godot::ClassDB::bind_method(godot::D_METHOD("changeset_start_v2_strm", "out_iter", "x_input", "flags"), &Sqlite3Wrapper::changeset_start_v2_strm);
    godot::ClassDB::bind_method(godot::D_METHOD("changeset_strm", "session", "x_output"), &Sqlite3Wrapper::changeset_strm);
    godot::ClassDB::bind_method(godot::D_METHOD("patchset_strm", "session", "x_output", "p_out"), &Sqlite3Wrapper::patchset_strm);
    godot::ClassDB::bind_method(godot::D_METHOD("changegroup_add_strm", "changegroup", "x_input"), &Sqlite3Wrapper::changegroup_add_strm);
    godot::ClassDB::bind_method(godot::D_METHOD("session_config_strmsize"), &Sqlite3Wrapper::session_config_strmsize);
    godot::ClassDB::bind_method(godot::D_METHOD("close_v2", "db"), &Sqlite3Wrapper::close_v2);
    godot::ClassDB::bind_method(godot::D_METHOD("exec", "db", "sql", "callback"), &Sqlite3Wrapper::exec);
    godot::ClassDB::bind_method(godot::D_METHOD("last_insert_rowid", "db"), &Sqlite3Wrapper::last_insert_rowid);
    godot::ClassDB::bind_method(godot::D_METHOD("set_last_insert_rowid", "db", "rowid"), &Sqlite3Wrapper::set_last_insert_rowid);
    godot::ClassDB::bind_method(godot::D_METHOD("changes", "db"), &Sqlite3Wrapper::changes);
    godot::ClassDB::bind_method(godot::D_METHOD("total_changes", "db"), &Sqlite3Wrapper::total_changes);
    godot::ClassDB::bind_method(godot::D_METHOD("complete", "sql"), &Sqlite3Wrapper::complete);
#ifdef SQLITE_ENABLE_SETLK_TIMEOUT
    godot::ClassDB::bind_method(godot::D_METHOD("setlk_timeout", "db", "ms", "flags"), &Sqlite3Wrapper::setlk_timeout);
#endif
    godot::ClassDB::bind_method(godot::D_METHOD("setlk_block_on_connect"), &Sqlite3Wrapper::setlk_block_on_connect);
    godot::ClassDB::bind_method(godot::D_METHOD("get_table", "db", "sql"), &Sqlite3Wrapper::get_table);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_deny"), &Sqlite3Wrapper::sqlite_deny);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_ignore"), &Sqlite3Wrapper::sqlite_ignore);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_create_index"), &Sqlite3Wrapper::sqlite_create_index);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_create_table"), &Sqlite3Wrapper::sqlite_create_table);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_create_temp_index"), &Sqlite3Wrapper::sqlite_create_temp_index);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_create_temp_table"), &Sqlite3Wrapper::sqlite_create_temp_table);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_create_temp_trigger"), &Sqlite3Wrapper::sqlite_create_temp_trigger);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_create_temp_view"), &Sqlite3Wrapper::sqlite_create_temp_view);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_create_trigger"), &Sqlite3Wrapper::sqlite_create_trigger);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_create_view"), &Sqlite3Wrapper::sqlite_create_view);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_delete"), &Sqlite3Wrapper::sqlite_delete);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_drop_index"), &Sqlite3Wrapper::sqlite_drop_index);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_drop_table"), &Sqlite3Wrapper::sqlite_drop_table);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_drop_temp_index"), &Sqlite3Wrapper::sqlite_drop_temp_index);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_drop_temp_table"), &Sqlite3Wrapper::sqlite_drop_temp_table);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_drop_temp_trigger"), &Sqlite3Wrapper::sqlite_drop_temp_trigger);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_drop_temp_view"), &Sqlite3Wrapper::sqlite_drop_temp_view);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_drop_trigger"), &Sqlite3Wrapper::sqlite_drop_trigger);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_drop_view"), &Sqlite3Wrapper::sqlite_drop_view);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_insert"), &Sqlite3Wrapper::sqlite_insert);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_pragma"), &Sqlite3Wrapper::sqlite_pragma);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_read"), &Sqlite3Wrapper::sqlite_read);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_select"), &Sqlite3Wrapper::sqlite_select);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_transaction"), &Sqlite3Wrapper::sqlite_transaction);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_update"), &Sqlite3Wrapper::sqlite_update);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_attach"), &Sqlite3Wrapper::sqlite_attach);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_detach"), &Sqlite3Wrapper::sqlite_detach);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_alter_table"), &Sqlite3Wrapper::sqlite_alter_table);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_reindex"), &Sqlite3Wrapper::sqlite_reindex);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_analyze"), &Sqlite3Wrapper::sqlite_analyze);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_create_vtable"), &Sqlite3Wrapper::sqlite_create_vtable);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_drop_vtable"), &Sqlite3Wrapper::sqlite_drop_vtable);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_function"), &Sqlite3Wrapper::sqlite_function);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_savepoint"), &Sqlite3Wrapper::sqlite_savepoint);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_copy"), &Sqlite3Wrapper::sqlite_copy);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_recursive"), &Sqlite3Wrapper::sqlite_recursive);
    godot::ClassDB::bind_method(godot::D_METHOD("profile", "db", "x_profile"), &Sqlite3Wrapper::profile);
    godot::ClassDB::bind_method(godot::D_METHOD("trace_stmt"), &Sqlite3Wrapper::trace_stmt);
    godot::ClassDB::bind_method(godot::D_METHOD("trace_profile"), &Sqlite3Wrapper::trace_profile);
    godot::ClassDB::bind_method(godot::D_METHOD("trace_row"), &Sqlite3Wrapper::trace_row);
    godot::ClassDB::bind_method(godot::D_METHOD("trace_close"), &Sqlite3Wrapper::trace_close);
    godot::ClassDB::bind_method(godot::D_METHOD("progress_handler_disable", "db", "n_instructions"), &Sqlite3Wrapper::progress_handler_disable);
    godot::ClassDB::bind_method(godot::D_METHOD("open", "filename", "out_db"), &Sqlite3Wrapper::open);
    godot::ClassDB::bind_method(godot::D_METHOD("open16", "filename", "out_db"), &Sqlite3Wrapper::open16);
    godot::ClassDB::bind_method(godot::D_METHOD("open_v2", "filename", "out_db", "flags", "z_vfs"), &Sqlite3Wrapper::open_v2);
    godot::ClassDB::bind_method(godot::D_METHOD("errmsg16", "db"), &Sqlite3Wrapper::errmsg16);
    godot::ClassDB::bind_method(godot::D_METHOD("error_offset", "db"), &Sqlite3Wrapper::error_offset);
    godot::ClassDB::bind_method(godot::D_METHOD("set_errmsg", "db", "errcode", "z_err_msg"), &Sqlite3Wrapper::set_errmsg);
    godot::ClassDB::bind_method(godot::D_METHOD("limit_length"), &Sqlite3Wrapper::limit_length);
    godot::ClassDB::bind_method(godot::D_METHOD("limit_sql_length"), &Sqlite3Wrapper::limit_sql_length);
    godot::ClassDB::bind_method(godot::D_METHOD("limit_column"), &Sqlite3Wrapper::limit_column);
    godot::ClassDB::bind_method(godot::D_METHOD("limit_expr_depth"), &Sqlite3Wrapper::limit_expr_depth);
    godot::ClassDB::bind_method(godot::D_METHOD("limit_compound_select"), &Sqlite3Wrapper::limit_compound_select);
    godot::ClassDB::bind_method(godot::D_METHOD("limit_vdbe_op"), &Sqlite3Wrapper::limit_vdbe_op);
    godot::ClassDB::bind_method(godot::D_METHOD("limit_function_arg"), &Sqlite3Wrapper::limit_function_arg);
    godot::ClassDB::bind_method(godot::D_METHOD("limit_attached"), &Sqlite3Wrapper::limit_attached);
    godot::ClassDB::bind_method(godot::D_METHOD("limit_like_pattern_length"), &Sqlite3Wrapper::limit_like_pattern_length);
    godot::ClassDB::bind_method(godot::D_METHOD("limit_variable_number"), &Sqlite3Wrapper::limit_variable_number);
    godot::ClassDB::bind_method(godot::D_METHOD("limit_trigger_depth"), &Sqlite3Wrapper::limit_trigger_depth);
    godot::ClassDB::bind_method(godot::D_METHOD("limit_worker_threads"), &Sqlite3Wrapper::limit_worker_threads);
    godot::ClassDB::bind_method(godot::D_METHOD("limit_parser_depth"), &Sqlite3Wrapper::limit_parser_depth);
    godot::ClassDB::bind_method(godot::D_METHOD("prepare_persistent"), &Sqlite3Wrapper::prepare_persistent);
    godot::ClassDB::bind_method(godot::D_METHOD("prepare_normalize"), &Sqlite3Wrapper::prepare_normalize);
    godot::ClassDB::bind_method(godot::D_METHOD("prepare_no_vtab"), &Sqlite3Wrapper::prepare_no_vtab);
    godot::ClassDB::bind_method(godot::D_METHOD("prepare_dont_log"), &Sqlite3Wrapper::prepare_dont_log);
    godot::ClassDB::bind_method(godot::D_METHOD("prepare_from_ddl"), &Sqlite3Wrapper::prepare_from_ddl);
    godot::ClassDB::bind_method(godot::D_METHOD("prepare", "db", "sql", "n_byte", "out_stmt"), &Sqlite3Wrapper::prepare);
    godot::ClassDB::bind_method(godot::D_METHOD("prepare_v2", "db", "sql", "n_byte"), &Sqlite3Wrapper::prepare_v2);
    godot::ClassDB::bind_method(godot::D_METHOD("prepare_v3", "db", "sql", "n_byte", "prep_flags", "out_stmt"), &Sqlite3Wrapper::prepare_v3);
    godot::ClassDB::bind_method(godot::D_METHOD("prepare16", "db", "z_sql", "n_byte", "out_stmt"), &Sqlite3Wrapper::prepare16);
    godot::ClassDB::bind_method(godot::D_METHOD("prepare16_v2", "db", "sql_utf16", "n_byte", "out_stmt"), &Sqlite3Wrapper::prepare16_v2);
    godot::ClassDB::bind_method(godot::D_METHOD("prepare16_v3", "db", "sql", "n_byte", "prep_flags"), &Sqlite3Wrapper::prepare16_v3);
    godot::ClassDB::bind_method(godot::D_METHOD("sql", "stmt"), &Sqlite3Wrapper::sql);
#ifdef SQLITE_ENABLE_NORMALIZE
    godot::ClassDB::bind_method(godot::D_METHOD("normalized_sql", "p_stmt"), &Sqlite3Wrapper::normalized_sql);
#endif
    godot::ClassDB::bind_method(godot::D_METHOD("stmt_readonly", "stmt"), &Sqlite3Wrapper::stmt_readonly);
    godot::ClassDB::bind_method(godot::D_METHOD("stmt_isexplain", "p_stmt"), &Sqlite3Wrapper::stmt_isexplain);
    godot::ClassDB::bind_method(godot::D_METHOD("stmt_explain", "stmt", "e_mode"), &Sqlite3Wrapper::stmt_explain);
    godot::ClassDB::bind_method(godot::D_METHOD("stmt_busy", "stmt"), &Sqlite3Wrapper::stmt_busy);
    godot::ClassDB::bind_method(godot::D_METHOD("bind_double", "stmt", "index", "value"), &Sqlite3Wrapper::bind_double);
    godot::ClassDB::bind_method(godot::D_METHOD("bind_int", "stmt", "index", "value"), &Sqlite3Wrapper::bind_int);
    godot::ClassDB::bind_method(godot::D_METHOD("bind_null", "stmt", "index"), &Sqlite3Wrapper::bind_null);
    godot::ClassDB::bind_method(godot::D_METHOD("bind_text", "stmt", "index", "value", "length", "destructor_flag"), &Sqlite3Wrapper::bind_text);
    godot::ClassDB::bind_method(godot::D_METHOD("bind_text16", "stmt", "index", "value", "length"), &Sqlite3Wrapper::bind_text16);
    godot::ClassDB::bind_method(godot::D_METHOD("bind_text64", "stmt", "index", "text", "nbytes", "destructor", "encoding"), &Sqlite3Wrapper::bind_text64);
    godot::ClassDB::bind_method(godot::D_METHOD("bind_value", "stmt", "index", "value"), &Sqlite3Wrapper::bind_value);
    godot::ClassDB::bind_method(godot::D_METHOD("bind_pointer", "stmt", "index", "pointer", "type"), &Sqlite3Wrapper::bind_pointer);
    godot::ClassDB::bind_method(godot::D_METHOD("bind_zeroblob64", "stmt", "index", "size"), &Sqlite3Wrapper::bind_zeroblob64);
    godot::ClassDB::bind_method(godot::D_METHOD("bind_parameter_count", "stmt"), &Sqlite3Wrapper::bind_parameter_count);
    godot::ClassDB::bind_method(godot::D_METHOD("bind_parameter_name", "stmt", "index"), &Sqlite3Wrapper::bind_parameter_name);
    godot::ClassDB::bind_method(godot::D_METHOD("bind_parameter_index", "stmt", "name"), &Sqlite3Wrapper::bind_parameter_index);
    godot::ClassDB::bind_method(godot::D_METHOD("clear_bindings", "stmt"), &Sqlite3Wrapper::clear_bindings);
    godot::ClassDB::bind_method(godot::D_METHOD("column_count", "p_stmt"), &Sqlite3Wrapper::column_count);
    godot::ClassDB::bind_method(godot::D_METHOD("column_name", "stmt", "column"), &Sqlite3Wrapper::column_name);
#ifdef SQLITE_ENABLE_COLUMN_METADATA
    godot::ClassDB::bind_method(godot::D_METHOD("column_database_name", "stmt", "column"), &Sqlite3Wrapper::column_database_name);
#endif
    godot::ClassDB::bind_method(godot::D_METHOD("column_table_name16", "stmt", "col"), &Sqlite3Wrapper::column_table_name16);
    godot::ClassDB::bind_method(godot::D_METHOD("column_origin_name", "stmt", "col"), &Sqlite3Wrapper::column_origin_name);
    godot::ClassDB::bind_method(godot::D_METHOD("column_origin_name16", "stmt", "column"), &Sqlite3Wrapper::column_origin_name16);
    godot::ClassDB::bind_method(godot::D_METHOD("column_decltype", "stmt", "i"), &Sqlite3Wrapper::column_decltype);
    godot::ClassDB::bind_method(godot::D_METHOD("step", "stmt"), &Sqlite3Wrapper::step);
    godot::ClassDB::bind_method(godot::D_METHOD("data_count", "p_stmt"), &Sqlite3Wrapper::data_count);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_integer"), &Sqlite3Wrapper::sqlite_integer);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_float"), &Sqlite3Wrapper::sqlite_float);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_blob"), &Sqlite3Wrapper::sqlite_blob);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_null"), &Sqlite3Wrapper::sqlite_null);
    godot::ClassDB::bind_method(godot::D_METHOD("column_text", "stmt", "i_col"), &Sqlite3Wrapper::column_text);
    godot::ClassDB::bind_method(godot::D_METHOD("column_text16", "stmt", "i_col"), &Sqlite3Wrapper::column_text16);
    godot::ClassDB::bind_method(godot::D_METHOD("column_value", "stmt", "i_col"), &Sqlite3Wrapper::column_value);
    godot::ClassDB::bind_method(godot::D_METHOD("column_bytes", "stmt", "i_col"), &Sqlite3Wrapper::column_bytes);
    godot::ClassDB::bind_method(godot::D_METHOD("column_bytes16", "stmt", "i_col"), &Sqlite3Wrapper::column_bytes16);
    godot::ClassDB::bind_method(godot::D_METHOD("column_type", "stmt", "i_col"), &Sqlite3Wrapper::column_type);
    godot::ClassDB::bind_method(godot::D_METHOD("finalize", "p_stmt"), &Sqlite3Wrapper::finalize);
    godot::ClassDB::bind_method(godot::D_METHOD("reset", "p_stmt"), &Sqlite3Wrapper::reset);
    godot::ClassDB::bind_method(godot::D_METHOD("create_function", "db", "function_name", "n_arg", "text_rep", "app_data", "x_func", "x_step", "x_final"), &Sqlite3Wrapper::create_function);
    godot::ClassDB::bind_method(godot::D_METHOD("create_function16", "db", "function_name", "n_arg", "e_text_rep", "x_func", "x_step", "x_final"), &Sqlite3Wrapper::create_function16);
    godot::ClassDB::bind_method(godot::D_METHOD("create_function_v2", "db", "function_name", "n_arg", "e_text_rep", "x_func", "x_step", "x_final"), &Sqlite3Wrapper::create_function_v2);
    godot::ClassDB::bind_method(godot::D_METHOD("create_window_function", "db", "function_name", "n_arg", "e_text_rep", "step", "final", "value", "inverse", "destroy"), &Sqlite3Wrapper::create_window_function);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_utf8"), &Sqlite3Wrapper::sqlite_utf8);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_utf16le"), &Sqlite3Wrapper::sqlite_utf16le);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_utf16be"), &Sqlite3Wrapper::sqlite_utf16be);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_utf16"), &Sqlite3Wrapper::sqlite_utf16);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_any"), &Sqlite3Wrapper::sqlite_any);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_utf16_aligned"), &Sqlite3Wrapper::sqlite_utf16_aligned);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_utf8_zt"), &Sqlite3Wrapper::sqlite_utf8_zt);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_deterministic"), &Sqlite3Wrapper::sqlite_deterministic);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_directonly"), &Sqlite3Wrapper::sqlite_directonly);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_subtype"), &Sqlite3Wrapper::sqlite_subtype);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_innocuous"), &Sqlite3Wrapper::sqlite_innocuous);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_result_subtype"), &Sqlite3Wrapper::sqlite_result_subtype);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_selforder1"), &Sqlite3Wrapper::sqlite_selforder1);
#ifndef SQLITE_OMIT_DEPRECATED
    godot::ClassDB::bind_method(godot::D_METHOD("aggregate_count", "ctx"), &Sqlite3Wrapper::aggregate_count);
#endif
#ifndef SQLITE_OMIT_DEPRECATED
    godot::ClassDB::bind_method(godot::D_METHOD("expired", "stmt"), &Sqlite3Wrapper::expired);
#endif
#ifndef SQLITE_OMIT_DEPRECATED
    godot::ClassDB::bind_method(godot::D_METHOD("transfer_bindings", "from", "to"), &Sqlite3Wrapper::transfer_bindings);
#endif
#ifndef SQLITE_OMIT_DEPRECATED
    godot::ClassDB::bind_method(godot::D_METHOD("global_recover"), &Sqlite3Wrapper::global_recover);
#endif
#ifndef SQLITE_OMIT_DEPRECATED
    godot::ClassDB::bind_method(godot::D_METHOD("thread_cleanup"), &Sqlite3Wrapper::thread_cleanup);
#endif
#ifndef SQLITE_OMIT_DEPRECATED
    godot::ClassDB::bind_method(godot::D_METHOD("memory_alarm", "callback", "user_data", "threshold"), &Sqlite3Wrapper::memory_alarm);
#endif
    godot::ClassDB::bind_method(godot::D_METHOD("value_text", "value"), &Sqlite3Wrapper::value_text);
    godot::ClassDB::bind_method(godot::D_METHOD("value_text16", "value"), &Sqlite3Wrapper::value_text16);
    godot::ClassDB::bind_method(godot::D_METHOD("value_text16le", "value"), &Sqlite3Wrapper::value_text16le);
    godot::ClassDB::bind_method(godot::D_METHOD("value_text16be", "value"), &Sqlite3Wrapper::value_text16be);
    godot::ClassDB::bind_method(godot::D_METHOD("value_bytes16", "value"), &Sqlite3Wrapper::value_bytes16);
    godot::ClassDB::bind_method(godot::D_METHOD("value_type", "value"), &Sqlite3Wrapper::value_type);
    godot::ClassDB::bind_method(godot::D_METHOD("value_numeric_type", "value"), &Sqlite3Wrapper::value_numeric_type);
    godot::ClassDB::bind_method(godot::D_METHOD("value_nochange", "value"), &Sqlite3Wrapper::value_nochange);
    godot::ClassDB::bind_method(godot::D_METHOD("value_frombind", "value"), &Sqlite3Wrapper::value_frombind);
    godot::ClassDB::bind_method(godot::D_METHOD("value_encoding", "value"), &Sqlite3Wrapper::value_encoding);
    godot::ClassDB::bind_method(godot::D_METHOD("value_subtype", "value"), &Sqlite3Wrapper::value_subtype);
    godot::ClassDB::bind_method(godot::D_METHOD("value_dup", "value"), &Sqlite3Wrapper::value_dup);
    godot::ClassDB::bind_method(godot::D_METHOD("aggregate_context", "ctx", "n_bytes"), &Sqlite3Wrapper::aggregate_context);
    godot::ClassDB::bind_method(godot::D_METHOD("user_data", "ctx"), &Sqlite3Wrapper::user_data);
    godot::ClassDB::bind_method(godot::D_METHOD("context_db_handle", "ctx"), &Sqlite3Wrapper::context_db_handle);
    godot::ClassDB::bind_method(godot::D_METHOD("get_auxdata", "context", "n"), &Sqlite3Wrapper::get_auxdata);
    godot::ClassDB::bind_method(godot::D_METHOD("get_clientdata", "db", "name"), &Sqlite3Wrapper::get_clientdata);
    godot::ClassDB::bind_method(godot::D_METHOD("result_error", "ctx", "error_message", "length"), &Sqlite3Wrapper::result_error);
    godot::ClassDB::bind_method(godot::D_METHOD("result_error_toobig", "ctx"), &Sqlite3Wrapper::result_error_toobig);
    godot::ClassDB::bind_method(godot::D_METHOD("result_error_code", "context", "error_code"), &Sqlite3Wrapper::result_error_code);
    godot::ClassDB::bind_method(godot::D_METHOD("result_int", "context", "value"), &Sqlite3Wrapper::result_int);
    godot::ClassDB::bind_method(godot::D_METHOD("result_int64", "ctx", "value"), &Sqlite3Wrapper::result_int64);
    godot::ClassDB::bind_method(godot::D_METHOD("result_null", "ctx"), &Sqlite3Wrapper::result_null);
    godot::ClassDB::bind_method(godot::D_METHOD("result_text", "context", "text", "length", "destructor"), &Sqlite3Wrapper::result_text);
    godot::ClassDB::bind_method(godot::D_METHOD("result_text64", "ctx", "text", "n", "encoding"), &Sqlite3Wrapper::result_text64);
    godot::ClassDB::bind_method(godot::D_METHOD("result_text16", "ctx", "text", "length", "destructor"), &Sqlite3Wrapper::result_text16);
    godot::ClassDB::bind_method(godot::D_METHOD("result_text16le", "ctx", "data", "destructor"), &Sqlite3Wrapper::result_text16le);
    godot::ClassDB::bind_method(godot::D_METHOD("result_text16be", "context", "text", "length", "destructor"), &Sqlite3Wrapper::result_text16be);
    godot::ClassDB::bind_method(godot::D_METHOD("result_pointer", "ctx", "data_ptr", "type", "destructor_ptr"), &Sqlite3Wrapper::result_pointer);
    godot::ClassDB::bind_method(godot::D_METHOD("result_zeroblob", "ctx", "n"), &Sqlite3Wrapper::result_zeroblob);
    godot::ClassDB::bind_method(godot::D_METHOD("result_zeroblob64", "context", "n"), &Sqlite3Wrapper::result_zeroblob64);
    godot::ClassDB::bind_method(godot::D_METHOD("result_subtype", "context", "subtype"), &Sqlite3Wrapper::result_subtype);
    godot::ClassDB::bind_method(godot::D_METHOD("create_collation", "db", "name", "e_text_rep", "user_data", "compare"), &Sqlite3Wrapper::create_collation);
    godot::ClassDB::bind_method(godot::D_METHOD("create_collation16", "db", "z_name", "e_text_rep", "user_data", "x_compare"), &Sqlite3Wrapper::create_collation16);
    godot::ClassDB::bind_method(godot::D_METHOD("collation_needed", "db", "callback"), &Sqlite3Wrapper::collation_needed);
#ifdef SQLITE_ENABLE_CEROD
    godot::ClassDB::bind_method(godot::D_METHOD("activate_cerod", "pass_phrase"), &Sqlite3Wrapper::activate_cerod);
#endif
    godot::ClassDB::bind_method(godot::D_METHOD("sleep", "milliseconds"), &Sqlite3Wrapper::sleep);
    godot::ClassDB::bind_method(godot::D_METHOD("db_handle", "stmt"), &Sqlite3Wrapper::db_handle);
    godot::ClassDB::bind_method(godot::D_METHOD("db_name", "db", "N"), &Sqlite3Wrapper::db_name);
    godot::ClassDB::bind_method(godot::D_METHOD("db_filename", "db", "z_db_name"), &Sqlite3Wrapper::db_filename);
    godot::ClassDB::bind_method(godot::D_METHOD("db_readonly", "db", "db_name"), &Sqlite3Wrapper::db_readonly);
    godot::ClassDB::bind_method(godot::D_METHOD("txn_state", "db", "z_schema"), &Sqlite3Wrapper::txn_state);
    godot::ClassDB::bind_method(godot::D_METHOD("txn_none"), &Sqlite3Wrapper::txn_none);
    godot::ClassDB::bind_method(godot::D_METHOD("txn_read"), &Sqlite3Wrapper::txn_read);
    godot::ClassDB::bind_method(godot::D_METHOD("txn_write"), &Sqlite3Wrapper::txn_write);
    godot::ClassDB::bind_method(godot::D_METHOD("commit_hook", "db", "callback"), &Sqlite3Wrapper::commit_hook);
    godot::ClassDB::bind_method(godot::D_METHOD("autovacuum_pages", "db", "on_autovacuum", "on_userdata_destroy"), &Sqlite3Wrapper::autovacuum_pages);
    godot::ClassDB::bind_method(godot::D_METHOD("update_hook", "db", "callback"), &Sqlite3Wrapper::update_hook);
#ifndef SQLITE_OMIT_SHARED_CACHE
    godot::ClassDB::bind_method(godot::D_METHOD("enable_shared_cache", "enable"), &Sqlite3Wrapper::enable_shared_cache);
#endif
    godot::ClassDB::bind_method(godot::D_METHOD("soft_heap_limit64", "n"), &Sqlite3Wrapper::soft_heap_limit64);
    godot::ClassDB::bind_method(godot::D_METHOD("table_column_metadata", "db", "db_name", "table_name", "column_name"), &Sqlite3Wrapper::table_column_metadata);
    godot::ClassDB::bind_method(godot::D_METHOD("enable_load_extension", "db", "onoff"), &Sqlite3Wrapper::enable_load_extension);
    godot::ClassDB::bind_method(godot::D_METHOD("auto_extension", "x_entry_point"), &Sqlite3Wrapper::auto_extension);
    godot::ClassDB::bind_method(godot::D_METHOD("overload_function", "db", "func_name", "n_arg"), &Sqlite3Wrapper::overload_function);
    godot::ClassDB::bind_method(godot::D_METHOD("blob_reopen", "db_blob", "rowid"), &Sqlite3Wrapper::blob_reopen);
    godot::ClassDB::bind_method(godot::D_METHOD("blob_close", "blob_handle"), &Sqlite3Wrapper::blob_close);
    godot::ClassDB::bind_method(godot::D_METHOD("blob_bytes", "blob"), &Sqlite3Wrapper::blob_bytes);
    godot::ClassDB::bind_method(godot::D_METHOD("blob_read", "blob", "n", "offset"), &Sqlite3Wrapper::blob_read);
    godot::ClassDB::bind_method(godot::D_METHOD("blob_write", "blob", "buffer", "offset"), &Sqlite3Wrapper::blob_write);
    godot::ClassDB::bind_method(godot::D_METHOD("vfs_find", "vfs_name"), &Sqlite3Wrapper::vfs_find);
#ifndef NDEBUG
    godot::ClassDB::bind_method(godot::D_METHOD("mutex_held", "handle"), &Sqlite3Wrapper::mutex_held);
#endif
#ifndef NDEBUG
    godot::ClassDB::bind_method(godot::D_METHOD("mutex_notheld", "handle"), &Sqlite3Wrapper::mutex_notheld);
#endif
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_mutex_fast"), &Sqlite3Wrapper::sqlite_mutex_fast);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_mutex_recursive"), &Sqlite3Wrapper::sqlite_mutex_recursive);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_mutex_static_main"), &Sqlite3Wrapper::sqlite_mutex_static_main);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_mutex_static_mem"), &Sqlite3Wrapper::sqlite_mutex_static_mem);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_mutex_static_mem2"), &Sqlite3Wrapper::sqlite_mutex_static_mem2);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_mutex_static_open"), &Sqlite3Wrapper::sqlite_mutex_static_open);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_mutex_static_prng"), &Sqlite3Wrapper::sqlite_mutex_static_prng);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_mutex_static_lru"), &Sqlite3Wrapper::sqlite_mutex_static_lru);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_mutex_static_lru2"), &Sqlite3Wrapper::sqlite_mutex_static_lru2);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_mutex_static_pmem"), &Sqlite3Wrapper::sqlite_mutex_static_pmem);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_mutex_static_app1"), &Sqlite3Wrapper::sqlite_mutex_static_app1);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_mutex_static_app2"), &Sqlite3Wrapper::sqlite_mutex_static_app2);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_mutex_static_app3"), &Sqlite3Wrapper::sqlite_mutex_static_app3);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_mutex_static_vfs1"), &Sqlite3Wrapper::sqlite_mutex_static_vfs1);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_mutex_static_vfs2"), &Sqlite3Wrapper::sqlite_mutex_static_vfs2);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_mutex_static_vfs3"), &Sqlite3Wrapper::sqlite_mutex_static_vfs3);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_mutex_static_master"), &Sqlite3Wrapper::sqlite_mutex_static_master);
    godot::ClassDB::bind_method(godot::D_METHOD("file_control", "db", "db_name", "op", "data"), &Sqlite3Wrapper::file_control);
    godot::ClassDB::bind_method(godot::D_METHOD("test_control", "op", "args"), &Sqlite3Wrapper::test_control);
    godot::ClassDB::bind_method(godot::D_METHOD("str_finish", "str_handle"), &Sqlite3Wrapper::str_finish);
    godot::ClassDB::bind_method(godot::D_METHOD("dbstatus_lookaside_used"), &Sqlite3Wrapper::dbstatus_lookaside_used);
    godot::ClassDB::bind_method(godot::D_METHOD("dbstatus_cache_used"), &Sqlite3Wrapper::dbstatus_cache_used);
    godot::ClassDB::bind_method(godot::D_METHOD("dbstatus_schema_used"), &Sqlite3Wrapper::dbstatus_schema_used);
    godot::ClassDB::bind_method(godot::D_METHOD("dbstatus_stmt_used"), &Sqlite3Wrapper::dbstatus_stmt_used);
    godot::ClassDB::bind_method(godot::D_METHOD("dbstatus_lookaside_hit"), &Sqlite3Wrapper::dbstatus_lookaside_hit);
    godot::ClassDB::bind_method(godot::D_METHOD("dbstatus_lookaside_miss_size"), &Sqlite3Wrapper::dbstatus_lookaside_miss_size);
    godot::ClassDB::bind_method(godot::D_METHOD("dbstatus_lookaside_miss_full"), &Sqlite3Wrapper::dbstatus_lookaside_miss_full);
    godot::ClassDB::bind_method(godot::D_METHOD("dbstatus_cache_hit"), &Sqlite3Wrapper::dbstatus_cache_hit);
    godot::ClassDB::bind_method(godot::D_METHOD("dbstatus_cache_miss"), &Sqlite3Wrapper::dbstatus_cache_miss);
    godot::ClassDB::bind_method(godot::D_METHOD("dbstatus_cache_write"), &Sqlite3Wrapper::dbstatus_cache_write);
    godot::ClassDB::bind_method(godot::D_METHOD("dbstatus_deferred_fks"), &Sqlite3Wrapper::dbstatus_deferred_fks);
    godot::ClassDB::bind_method(godot::D_METHOD("dbstatus_cache_used_shared"), &Sqlite3Wrapper::dbstatus_cache_used_shared);
    godot::ClassDB::bind_method(godot::D_METHOD("dbstatus_cache_spill"), &Sqlite3Wrapper::dbstatus_cache_spill);
    godot::ClassDB::bind_method(godot::D_METHOD("dbstatus_tempbuf_spill"), &Sqlite3Wrapper::dbstatus_tempbuf_spill);
    godot::ClassDB::bind_method(godot::D_METHOD("dbstatus_max"), &Sqlite3Wrapper::dbstatus_max);
    godot::ClassDB::bind_method(godot::D_METHOD("stmtstatus_fullscan_step"), &Sqlite3Wrapper::stmtstatus_fullscan_step);
    godot::ClassDB::bind_method(godot::D_METHOD("stmtstatus_sort"), &Sqlite3Wrapper::stmtstatus_sort);
    godot::ClassDB::bind_method(godot::D_METHOD("stmtstatus_autoindex"), &Sqlite3Wrapper::stmtstatus_autoindex);
    godot::ClassDB::bind_method(godot::D_METHOD("stmtstatus_vm_step"), &Sqlite3Wrapper::stmtstatus_vm_step);
    godot::ClassDB::bind_method(godot::D_METHOD("stmtstatus_reprepare"), &Sqlite3Wrapper::stmtstatus_reprepare);
    godot::ClassDB::bind_method(godot::D_METHOD("stmtstatus_run"), &Sqlite3Wrapper::stmtstatus_run);
    godot::ClassDB::bind_method(godot::D_METHOD("stmtstatus_filter_miss"), &Sqlite3Wrapper::stmtstatus_filter_miss);
    godot::ClassDB::bind_method(godot::D_METHOD("stmtstatus_filter_hit"), &Sqlite3Wrapper::stmtstatus_filter_hit);
    godot::ClassDB::bind_method(godot::D_METHOD("stmtstatus_memused"), &Sqlite3Wrapper::stmtstatus_memused);
    godot::ClassDB::bind_method(godot::D_METHOD("backup_pagecount", "p"), &Sqlite3Wrapper::backup_pagecount);
    godot::ClassDB::bind_method(godot::D_METHOD("stricmp", "a", "b"), &Sqlite3Wrapper::stricmp);
    godot::ClassDB::bind_method(godot::D_METHOD("wal_autocheckpoint", "db", "N"), &Sqlite3Wrapper::wal_autocheckpoint);
    godot::ClassDB::bind_method(godot::D_METHOD("wal_checkpoint", "db", "db_name"), &Sqlite3Wrapper::wal_checkpoint);
    godot::ClassDB::bind_method(godot::D_METHOD("wal_checkpoint_v2", "db", "z_db", "e_mode"), &Sqlite3Wrapper::wal_checkpoint_v2);
    godot::ClassDB::bind_method(godot::D_METHOD("checkpoint_noop"), &Sqlite3Wrapper::checkpoint_noop);
    godot::ClassDB::bind_method(godot::D_METHOD("checkpoint_passive"), &Sqlite3Wrapper::checkpoint_passive);
    godot::ClassDB::bind_method(godot::D_METHOD("checkpoint_full"), &Sqlite3Wrapper::checkpoint_full);
    godot::ClassDB::bind_method(godot::D_METHOD("checkpoint_restart"), &Sqlite3Wrapper::checkpoint_restart);
    godot::ClassDB::bind_method(godot::D_METHOD("checkpoint_truncate"), &Sqlite3Wrapper::checkpoint_truncate);
    godot::ClassDB::bind_method(godot::D_METHOD("vtab_constraint_support"), &Sqlite3Wrapper::vtab_constraint_support);
    godot::ClassDB::bind_method(godot::D_METHOD("vtab_innocuous"), &Sqlite3Wrapper::vtab_innocuous);
    godot::ClassDB::bind_method(godot::D_METHOD("vtab_directonly"), &Sqlite3Wrapper::vtab_directonly);
    godot::ClassDB::bind_method(godot::D_METHOD("vtab_uses_all_schemas"), &Sqlite3Wrapper::vtab_uses_all_schemas);
    godot::ClassDB::bind_method(godot::D_METHOD("vtab_nochange", "context"), &Sqlite3Wrapper::vtab_nochange);
    godot::ClassDB::bind_method(godot::D_METHOD("vtab_collation", "index_info", "idx"), &Sqlite3Wrapper::vtab_collation);
    godot::ClassDB::bind_method(godot::D_METHOD("vtab_rhs_value", "info", "idx", "out_val"), &Sqlite3Wrapper::vtab_rhs_value);
#ifdef SQLITE_ENABLE_STMT_SCANSTATUS
    godot::ClassDB::bind_method(godot::D_METHOD("stmt_scanstatus_v2", "stmt", "idx", "scan_status_op", "flags"), &Sqlite3Wrapper::stmt_scanstatus_v2);
#endif
#ifdef SQLITE_ENABLE_STMT_SCANSTATUS
    godot::ClassDB::bind_method(godot::D_METHOD("stmt_scanstatus_reset", "stmt"), &Sqlite3Wrapper::stmt_scanstatus_reset);
#endif
    godot::ClassDB::bind_method(godot::D_METHOD("db_cacheflush", "db"), &Sqlite3Wrapper::db_cacheflush);
#if defined(SQLITE_ENABLE_PREUPDATE_HOOK)
    godot::ClassDB::bind_method(godot::D_METHOD("preupdate_hook", "db", "on_preupdate"), &Sqlite3Wrapper::preupdate_hook);
#endif
#if defined(SQLITE_ENABLE_PREUPDATE_HOOK)
    godot::ClassDB::bind_method(godot::D_METHOD("preupdate_old", "db", "n", "out_value"), &Sqlite3Wrapper::preupdate_old);
#endif
#if defined(SQLITE_ENABLE_PREUPDATE_HOOK)
    godot::ClassDB::bind_method(godot::D_METHOD("preupdate_count", "db"), &Sqlite3Wrapper::preupdate_count);
#endif
#if defined(SQLITE_ENABLE_PREUPDATE_HOOK)
    godot::ClassDB::bind_method(godot::D_METHOD("preupdate_depth", "db"), &Sqlite3Wrapper::preupdate_depth);
#endif
#if defined(SQLITE_ENABLE_PREUPDATE_HOOK)
    godot::ClassDB::bind_method(godot::D_METHOD("preupdate_new", "db", "n", "out_value"), &Sqlite3Wrapper::preupdate_new);
#endif
#if defined(SQLITE_ENABLE_PREUPDATE_HOOK)
    godot::ClassDB::bind_method(godot::D_METHOD("preupdate_blobwrite", "db"), &Sqlite3Wrapper::preupdate_blobwrite);
#endif
    godot::ClassDB::bind_method(godot::D_METHOD("system_errno", "db"), &Sqlite3Wrapper::system_errno);
#ifndef SQLITE_OMIT_DESERIALIZE
    godot::ClassDB::bind_method(godot::D_METHOD("serialize", "db", "schema", "flags"), &Sqlite3Wrapper::serialize);
#endif
    godot::ClassDB::bind_method(godot::D_METHOD("serialize_nocopy"), &Sqlite3Wrapper::serialize_nocopy);
    godot::ClassDB::bind_method(godot::D_METHOD("deserialize_freeonclose"), &Sqlite3Wrapper::deserialize_freeonclose);
    godot::ClassDB::bind_method(godot::D_METHOD("deserialize_resizeable"), &Sqlite3Wrapper::deserialize_resizeable);
    godot::ClassDB::bind_method(godot::D_METHOD("deserialize_readonly"), &Sqlite3Wrapper::deserialize_readonly);
    godot::ClassDB::bind_method(godot::D_METHOD("carray_bind", "stmt", "index", "data", "n_data", "flags"), &Sqlite3Wrapper::carray_bind);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_carray_int32"), &Sqlite3Wrapper::sqlite_carray_int32);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_carray_int64"), &Sqlite3Wrapper::sqlite_carray_int64);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_carray_double"), &Sqlite3Wrapper::sqlite_carray_double);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_carray_text"), &Sqlite3Wrapper::sqlite_carray_text);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_carray_blob"), &Sqlite3Wrapper::sqlite_carray_blob);
    godot::ClassDB::bind_method(godot::D_METHOD("carray_int32"), &Sqlite3Wrapper::carray_int32);
    godot::ClassDB::bind_method(godot::D_METHOD("carray_int64"), &Sqlite3Wrapper::carray_int64);
    godot::ClassDB::bind_method(godot::D_METHOD("carray_double"), &Sqlite3Wrapper::carray_double);
    godot::ClassDB::bind_method(godot::D_METHOD("carray_text"), &Sqlite3Wrapper::carray_text);
    godot::ClassDB::bind_method(godot::D_METHOD("carray_blob"), &Sqlite3Wrapper::carray_blob);
    godot::ClassDB::bind_method(godot::D_METHOD("session_delete", "p_session"), &Sqlite3Wrapper::session_delete);
    godot::ClassDB::bind_method(godot::D_METHOD("mutex_alloc", "mutex_type"), &Sqlite3Wrapper::mutex_alloc);
    godot::ClassDB::bind_method(godot::D_METHOD("str_appendf", "str", "format", "args"), &Sqlite3Wrapper::str_appendf);
    godot::ClassDB::bind_method(godot::D_METHOD("str_errcode", "x"), &Sqlite3Wrapper::str_errcode);
    godot::ClassDB::bind_method(godot::D_METHOD("status", "op", "reset_flag"), &Sqlite3Wrapper::status);
    godot::ClassDB::bind_method(godot::D_METHOD("backup_init", "p_dest", "z_dest_name", "p_source", "z_source_name"), &Sqlite3Wrapper::backup_init);
#ifdef SQLITE_ENABLE_SNAPSHOT
    godot::ClassDB::bind_method(godot::D_METHOD("snapshot_open", "db", "schema", "snapshot"), &Sqlite3Wrapper::snapshot_open);
#endif
#ifdef SQLITE_ENABLE_SNAPSHOT
    godot::ClassDB::bind_method(godot::D_METHOD("snapshot_cmp", "p1", "p2"), &Sqlite3Wrapper::snapshot_cmp);
#endif
#ifdef SQLITE_ENABLE_SNAPSHOT
    godot::ClassDB::bind_method(godot::D_METHOD("snapshot_recover", "db", "z_db"), &Sqlite3Wrapper::snapshot_recover);
#endif
    godot::ClassDB::bind_method(godot::D_METHOD("session_object_config", "session", "op", "p_arg"), &Sqlite3Wrapper::session_object_config);
    godot::ClassDB::bind_method(godot::D_METHOD("session_objconfig_size"), &Sqlite3Wrapper::session_objconfig_size);
    godot::ClassDB::bind_method(godot::D_METHOD("session_objconfig_rowid"), &Sqlite3Wrapper::session_objconfig_rowid);
    godot::ClassDB::bind_method(godot::D_METHOD("session_indirect", "session", "b_indirect"), &Sqlite3Wrapper::session_indirect);
    godot::ClassDB::bind_method(godot::D_METHOD("session_attach", "p_session", "z_tab"), &Sqlite3Wrapper::session_attach);
    godot::ClassDB::bind_method(godot::D_METHOD("session_table_filter", "session", "filter"), &Sqlite3Wrapper::session_table_filter);
    godot::ClassDB::bind_method(godot::D_METHOD("session_changeset", "session"), &Sqlite3Wrapper::session_changeset);
    godot::ClassDB::bind_method(godot::D_METHOD("changeset_size", "session"), &Sqlite3Wrapper::changeset_size);
    godot::ClassDB::bind_method(godot::D_METHOD("session_diff", "p_session", "from_db", "table"), &Sqlite3Wrapper::session_diff);
    godot::ClassDB::bind_method(godot::D_METHOD("session_patchset", "session"), &Sqlite3Wrapper::session_patchset);
    godot::ClassDB::bind_method(godot::D_METHOD("is_empty", "p_session"), &Sqlite3Wrapper::is_empty);
    godot::ClassDB::bind_method(godot::D_METHOD("changeset_start", "out_iter", "changeset_blob"), &Sqlite3Wrapper::changeset_start);
    godot::ClassDB::bind_method(godot::D_METHOD("changesetstart_invert"), &Sqlite3Wrapper::changesetstart_invert);
    godot::ClassDB::bind_method(godot::D_METHOD("changeset_op", "iter", "request_indirect"), &Sqlite3Wrapper::changeset_op);
    godot::ClassDB::bind_method(godot::D_METHOD("pk", "iter"), &Sqlite3Wrapper::pk);
    godot::ClassDB::bind_method(godot::D_METHOD("changeset_old", "p_iter", "i_val", "out_value"), &Sqlite3Wrapper::changeset_old);
    godot::ClassDB::bind_method(godot::D_METHOD("changeset_new", "p_iter", "i_val", "out_value"), &Sqlite3Wrapper::changeset_new);
    godot::ClassDB::bind_method(godot::D_METHOD("changeset_conflict", "p_iter", "i_val", "out_value"), &Sqlite3Wrapper::changeset_conflict);
    godot::ClassDB::bind_method(godot::D_METHOD("fk_conflicts", "iter"), &Sqlite3Wrapper::fk_conflicts);
    godot::ClassDB::bind_method(godot::D_METHOD("changeset_invert", "input"), &Sqlite3Wrapper::changeset_invert);
    godot::ClassDB::bind_method(godot::D_METHOD("changegroup_schema", "changegroup", "db", "db_name"), &Sqlite3Wrapper::changegroup_schema);
    godot::ClassDB::bind_method(godot::D_METHOD("changegroup_add", "changegroup", "data"), &Sqlite3Wrapper::changegroup_add);
    godot::ClassDB::bind_method(godot::D_METHOD("add_change", "changegroup", "iter"), &Sqlite3Wrapper::add_change);
    godot::ClassDB::bind_method(godot::D_METHOD("changegroup_output", "group"), &Sqlite3Wrapper::changegroup_output);
    godot::ClassDB::bind_method(godot::D_METHOD("changeset_apply", "db", "changeset", "filter", "conflict"), &Sqlite3Wrapper::changeset_apply);
    godot::ClassDB::bind_method(godot::D_METHOD("changeset_apply_v2", "db", "changeset_blob", "x_filter", "x_conflict", "flags"), &Sqlite3Wrapper::changeset_apply_v2);
    godot::ClassDB::bind_method(godot::D_METHOD("changeset_apply_v3", "db", "changeset", "x_filter", "x_conflict", "flags"), &Sqlite3Wrapper::changeset_apply_v3);
    godot::ClassDB::bind_method(godot::D_METHOD("changesetapply_nosavepoint_flag"), &Sqlite3Wrapper::changesetapply_nosavepoint_flag);
    godot::ClassDB::bind_method(godot::D_METHOD("changesetapply_invert_flag"), &Sqlite3Wrapper::changesetapply_invert_flag);
    godot::ClassDB::bind_method(godot::D_METHOD("changesetapply_ignorenoop_flag"), &Sqlite3Wrapper::changesetapply_ignorenoop_flag);
    godot::ClassDB::bind_method(godot::D_METHOD("changesetapply_fknoaction_flag"), &Sqlite3Wrapper::changesetapply_fknoaction_flag);
    godot::ClassDB::bind_method(godot::D_METHOD("changeset_data_type"), &Sqlite3Wrapper::changeset_data_type);
    godot::ClassDB::bind_method(godot::D_METHOD("changeset_notfound_type"), &Sqlite3Wrapper::changeset_notfound_type);
    godot::ClassDB::bind_method(godot::D_METHOD("changeset_conflict_type"), &Sqlite3Wrapper::changeset_conflict_type);
    godot::ClassDB::bind_method(godot::D_METHOD("changeset_constraint_type"), &Sqlite3Wrapper::changeset_constraint_type);
    godot::ClassDB::bind_method(godot::D_METHOD("changeset_foreign_key_type"), &Sqlite3Wrapper::changeset_foreign_key_type);
    godot::ClassDB::bind_method(godot::D_METHOD("changeset_omit_result"), &Sqlite3Wrapper::changeset_omit_result);
    godot::ClassDB::bind_method(godot::D_METHOD("changeset_replace_result"), &Sqlite3Wrapper::changeset_replace_result);
    godot::ClassDB::bind_method(godot::D_METHOD("changeset_abort_result"), &Sqlite3Wrapper::changeset_abort_result);
    godot::ClassDB::bind_method(godot::D_METHOD("rebase", "rebaser", "input"), &Sqlite3Wrapper::rebase);
    godot::ClassDB::bind_method(godot::D_METHOD("changeset_apply_strm", "db", "x_input", "input_ctx", "x_filter", "x_conflict", "conflict_ctx"), &Sqlite3Wrapper::changeset_apply_strm);
    godot::ClassDB::bind_method(godot::D_METHOD("changeset_apply_v2_strm", "db", "x_input", "x_filter", "x_conflict", "flags"), &Sqlite3Wrapper::changeset_apply_v2_strm);
    godot::ClassDB::bind_method(godot::D_METHOD("changeset_apply_v3_strm", "db", "x_input", "x_filter", "x_conflict", "flags"), &Sqlite3Wrapper::changeset_apply_v3_strm);
    godot::ClassDB::bind_method(godot::D_METHOD("changeset_invert_strm", "x_input", "x_output"), &Sqlite3Wrapper::changeset_invert_strm);
    godot::ClassDB::bind_method(godot::D_METHOD("changeset_start_strm", "x_input", "out_iter"), &Sqlite3Wrapper::changeset_start_strm);
    godot::ClassDB::bind_method(godot::D_METHOD("changegroup_output_strm", "changegroup", "x_output"), &Sqlite3Wrapper::changegroup_output_strm);
    godot::ClassDB::bind_method(godot::D_METHOD("rebase_strm", "p_rebaser", "x_input", "x_output"), &Sqlite3Wrapper::rebase_strm);
    godot::ClassDB::bind_method(godot::D_METHOD("session_config", "op", "chunk_size"), &Sqlite3Wrapper::session_config);
    godot::ClassDB::bind_method(godot::D_METHOD("tokenize_query"), &Sqlite3Wrapper::tokenize_query);
    godot::ClassDB::bind_method(godot::D_METHOD("tokenize_prefix"), &Sqlite3Wrapper::tokenize_prefix);
    godot::ClassDB::bind_method(godot::D_METHOD("tokenize_document"), &Sqlite3Wrapper::tokenize_document);
    godot::ClassDB::bind_method(godot::D_METHOD("tokenize_aux"), &Sqlite3Wrapper::tokenize_aux);
    godot::ClassDB::bind_method(godot::D_METHOD("token_colocated"), &Sqlite3Wrapper::token_colocated);
    godot::ClassDB::bind_method(godot::D_METHOD("create_module_v2", "db", "z_name", "module", "client_data", "on_destroy"), &Sqlite3Wrapper::create_module_v2);
    godot::ClassDB::bind_method(godot::D_METHOD("drop_modules", "db", "keep_list"), &Sqlite3Wrapper::drop_modules);
    godot::ClassDB::bind_method(godot::D_METHOD("declare_vtab", "db", "z_sql"), &Sqlite3Wrapper::declare_vtab);
#ifdef SQLITE_ENABLE_UNLOCK_NOTIFY
    godot::ClassDB::bind_method(godot::D_METHOD("unlock_notify", "blocked", "notify", "notify_arg"), &Sqlite3Wrapper::unlock_notify);
#endif
    godot::ClassDB::bind_method(godot::D_METHOD("vtab_distinct", "info"), &Sqlite3Wrapper::vtab_distinct);
    godot::ClassDB::bind_method(godot::D_METHOD("vtab_in", "index_info", "i_cons", "b_handle"), &Sqlite3Wrapper::vtab_in);
    godot::ClassDB::bind_method(godot::D_METHOD("vtab_in_first", "p_val", "out_val"), &Sqlite3Wrapper::vtab_in_first);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_rollback"), &Sqlite3Wrapper::sqlite_rollback);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_fail"), &Sqlite3Wrapper::sqlite_fail);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_replace"), &Sqlite3Wrapper::sqlite_replace);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_scanstat_nloop"), &Sqlite3Wrapper::sqlite_scanstat_nloop);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_scanstat_nvisit"), &Sqlite3Wrapper::sqlite_scanstat_nvisit);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_scanstat_est"), &Sqlite3Wrapper::sqlite_scanstat_est);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_scanstat_name"), &Sqlite3Wrapper::sqlite_scanstat_name);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_scanstat_explain"), &Sqlite3Wrapper::sqlite_scanstat_explain);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_scanstat_selectid"), &Sqlite3Wrapper::sqlite_scanstat_selectid);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_scanstat_parentid"), &Sqlite3Wrapper::sqlite_scanstat_parentid);
    godot::ClassDB::bind_method(godot::D_METHOD("sqlite_scanstat_ncycle"), &Sqlite3Wrapper::sqlite_scanstat_ncycle);
}

String Sqlite3Wrapper::version_string(void) { // NOLINT(readability-convert-member-functions-to-static)
    return String(SQLITE_VERSION);
}

int Sqlite3Wrapper::version_number(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_VERSION_NUMBER;
}

String Sqlite3Wrapper::source_id(void) { // NOLINT(readability-convert-member-functions-to-static)
    return String(SQLITE_SOURCE_ID);
}

String Sqlite3Wrapper::scm_branch(void) { // NOLINT(readability-convert-member-functions-to-static)
    return String(SQLITE_SCM_BRANCH);
}

String Sqlite3Wrapper::scm_tags(void) { // NOLINT(readability-convert-member-functions-to-static)
    return String(SQLITE_SCM_TAGS);
}

String Sqlite3Wrapper::scm_datetime(void) { // NOLINT(readability-convert-member-functions-to-static)
    return String(SQLITE_SCM_DATETIME);
}

String Sqlite3Wrapper::libversion(void) { // NOLINT(readability-convert-member-functions-to-static)
    return String(::sqlite3_libversion());
}

String Sqlite3Wrapper::sourceid(void) { // NOLINT(readability-convert-member-functions-to-static)
    return String::utf8(::sqlite3_sourceid());
}

int Sqlite3Wrapper::libversion_number(void) { // NOLINT(readability-convert-member-functions-to-static)
    return ::sqlite3_libversion_number();
}

#ifndef SQLITE_OMIT_COMPILEOPTION_DIAGS
int Sqlite3Wrapper::compileoption_used(const String& option_name) { // NOLINT(readability-convert-member-functions-to-static)
    CharString cs = option_name.utf8();
    return sqlite3_compileoption_used(cs.get_data());
}
#endif

#ifndef SQLITE_OMIT_COMPILEOPTION_DIAGS
String Sqlite3Wrapper::compileoption_get(int n) { // NOLINT(readability-convert-member-functions-to-static)
    const char *opt = sqlite3_compileoption_get(n);
    return opt ? String(opt) : String();
}
#endif

int Sqlite3Wrapper::threadsafe(void) { // NOLINT(readability-convert-member-functions-to-static)
    return ::sqlite3_threadsafe();
}

int Sqlite3Wrapper::close(const Ref<Sqlite3Handle>& db) { // NOLINT(readability-convert-member-functions-to-static)
    if (db.is_null() || !db->is_valid()) {
        return SQLITE_OK;
    }
    int result = ::sqlite3_close(db->handle);
    if (result == SQLITE_OK) {
        db->set_handle(0);
    }
    return result;
}

int Sqlite3Wrapper::ok(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_OK;
}

int Sqlite3Wrapper::error(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_ERROR;
}

int Sqlite3Wrapper::internal(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_INTERNAL;
}

int Sqlite3Wrapper::perm(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_PERM;
}

int Sqlite3Wrapper::abort(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_ABORT;
}

int Sqlite3Wrapper::busy(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_BUSY;
}

int Sqlite3Wrapper::locked(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_LOCKED;
}

int Sqlite3Wrapper::nomem(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_NOMEM;
}

int Sqlite3Wrapper::readonly(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_READONLY;
}

int Sqlite3Wrapper::interrupt(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_INTERRUPT;
}

int Sqlite3Wrapper::ioerr(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOERR;
}

int Sqlite3Wrapper::corrupt(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CORRUPT;
}

int Sqlite3Wrapper::notfound(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_NOTFOUND;
}

int Sqlite3Wrapper::full(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FULL;
}

int Sqlite3Wrapper::cantopen(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CANTOPEN;
}

int Sqlite3Wrapper::protocol(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_PROTOCOL;
}

int Sqlite3Wrapper::empty(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_EMPTY;
}

int Sqlite3Wrapper::schema(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_SCHEMA;
}

int Sqlite3Wrapper::toobig(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TOOBIG;
}

int Sqlite3Wrapper::constraint(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CONSTRAINT;
}

int Sqlite3Wrapper::mismatch(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_MISMATCH;
}

int Sqlite3Wrapper::misuse(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_MISUSE;
}

int Sqlite3Wrapper::nolfs(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_NOLFS;
}

int Sqlite3Wrapper::auth(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_AUTH;
}

int Sqlite3Wrapper::format(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FORMAT;
}

int Sqlite3Wrapper::range(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_RANGE;
}

int Sqlite3Wrapper::notadb(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_NOTADB;
}

int Sqlite3Wrapper::notice(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_NOTICE;
}

int Sqlite3Wrapper::warning(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_WARNING;
}

int Sqlite3Wrapper::row(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_ROW;
}

int Sqlite3Wrapper::done(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DONE;
}

int Sqlite3Wrapper::error_missing_collseq(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_ERROR_MISSING_COLLSEQ;
}

int Sqlite3Wrapper::error_retry(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_ERROR_RETRY;
}

int Sqlite3Wrapper::error_snapshot(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_ERROR_SNAPSHOT;
}

int Sqlite3Wrapper::error_reservesize(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_ERROR_RESERVESIZE;
}

int Sqlite3Wrapper::error_key(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_ERROR_KEY;
}

int Sqlite3Wrapper::error_unable(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_ERROR_UNABLE;
}

int Sqlite3Wrapper::ioerr_read(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOERR_READ;
}

int Sqlite3Wrapper::ioerr_short_read(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOERR_SHORT_READ;
}

int Sqlite3Wrapper::ioerr_write(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOERR_WRITE;
}

int Sqlite3Wrapper::ioerr_fsync(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOERR_FSYNC;
}

int Sqlite3Wrapper::ioerr_dir_fsync(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOERR_DIR_FSYNC;
}

int Sqlite3Wrapper::ioerr_truncate(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOERR_TRUNCATE;
}

int Sqlite3Wrapper::ioerr_fstat(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOERR_FSTAT;
}

int Sqlite3Wrapper::ioerr_unlock(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOERR_UNLOCK;
}

int Sqlite3Wrapper::ioerr_rdlock(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOERR_RDLOCK;
}

int Sqlite3Wrapper::ioerr_delete(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOERR_DELETE;
}

int Sqlite3Wrapper::ioerr_blocked(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOERR_BLOCKED;
}

int Sqlite3Wrapper::ioerr_nomem(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOERR_NOMEM;
}

int Sqlite3Wrapper::ioerr_access(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOERR_ACCESS;
}

int Sqlite3Wrapper::ioerr_checkreservedlock(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOERR_CHECKRESERVEDLOCK;
}

int Sqlite3Wrapper::ioerr_lock(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOERR_LOCK;
}

int Sqlite3Wrapper::ioerr_close(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOERR_CLOSE;
}

int Sqlite3Wrapper::ioerr_dir_close(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOERR_DIR_CLOSE;
}

int Sqlite3Wrapper::ioerr_shmopen(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOERR_SHMOPEN;
}

int Sqlite3Wrapper::ioerr_shmsize(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOERR_SHMSIZE;
}

int Sqlite3Wrapper::ioerr_shmlock(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOERR_SHMLOCK;
}

int Sqlite3Wrapper::ioerr_shmmap(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOERR_SHMMAP;
}

int Sqlite3Wrapper::ioerr_seek(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOERR_SEEK;
}

int Sqlite3Wrapper::ioerr_delete_noent(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOERR_DELETE_NOENT;
}

int Sqlite3Wrapper::ioerr_mmap(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOERR_MMAP;
}

int Sqlite3Wrapper::ioerr_gettemppath(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOERR_GETTEMPPATH;
}

int Sqlite3Wrapper::ioerr_convpath(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOERR_CONVPATH;
}

int Sqlite3Wrapper::ioerr_vnode(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOERR_VNODE;
}

int Sqlite3Wrapper::ioerr_auth(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOERR_AUTH;
}

int Sqlite3Wrapper::ioerr_begin_atomic(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOERR_BEGIN_ATOMIC;
}

int Sqlite3Wrapper::ioerr_commit_atomic(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOERR_COMMIT_ATOMIC;
}

int Sqlite3Wrapper::ioerr_rollback_atomic(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOERR_ROLLBACK_ATOMIC;
}

int Sqlite3Wrapper::ioerr_data(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOERR_DATA;
}

int Sqlite3Wrapper::ioerr_corruptfs(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOERR_CORRUPTFS;
}

int Sqlite3Wrapper::ioerr_in_page(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOERR_IN_PAGE;
}

int Sqlite3Wrapper::ioerr_badkey(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOERR_BADKEY;
}

int Sqlite3Wrapper::ioerr_codec(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOERR_CODEC;
}

int Sqlite3Wrapper::locked_sharedcache(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_LOCKED_SHAREDCACHE;
}

int Sqlite3Wrapper::locked_vtab(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_LOCKED_VTAB;
}

int Sqlite3Wrapper::busy_recovery(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_BUSY_RECOVERY;
}

int Sqlite3Wrapper::busy_snapshot(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_BUSY_SNAPSHOT;
}

int Sqlite3Wrapper::busy_timeout(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_BUSY_TIMEOUT;
}

int Sqlite3Wrapper::cantopen_notempdir(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CANTOPEN_NOTEMPDIR;
}

int Sqlite3Wrapper::cantopen_isdir(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CANTOPEN_ISDIR;
}

int Sqlite3Wrapper::cantopen_fullpath(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CANTOPEN_FULLPATH;
}

int Sqlite3Wrapper::cantopen_convpath(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CANTOPEN_CONVPATH;
}

int Sqlite3Wrapper::cantopen_dirtywal(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CANTOPEN_DIRTYWAL;
}

int Sqlite3Wrapper::cantopen_symlink(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CANTOPEN_SYMLINK;
}

int Sqlite3Wrapper::corrupt_vtab(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CORRUPT_VTAB;
}

int Sqlite3Wrapper::corrupt_sequence(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CORRUPT_SEQUENCE;
}

int Sqlite3Wrapper::corrupt_index(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CORRUPT_INDEX;
}

int Sqlite3Wrapper::readonly_recovery(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_READONLY_RECOVERY;
}

int Sqlite3Wrapper::readonly_cantlock(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_READONLY_CANTLOCK;
}

int Sqlite3Wrapper::readonly_rollback(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_READONLY_ROLLBACK;
}

int Sqlite3Wrapper::readonly_dbmoved(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_READONLY_DBMOVED;
}

int Sqlite3Wrapper::readonly_cantinit(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_READONLY_CANTINIT;
}

int Sqlite3Wrapper::readonly_directory(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_READONLY_DIRECTORY;
}

int Sqlite3Wrapper::abort_rollback(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_ABORT_ROLLBACK;
}

int Sqlite3Wrapper::constraint_check(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CONSTRAINT_CHECK;
}

int Sqlite3Wrapper::constraint_commithook(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CONSTRAINT_COMMITHOOK;
}

int Sqlite3Wrapper::constraint_foreignkey(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CONSTRAINT_FOREIGNKEY;
}

int Sqlite3Wrapper::constraint_function(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CONSTRAINT_FUNCTION;
}

int Sqlite3Wrapper::constraint_notnull(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CONSTRAINT_NOTNULL;
}

int Sqlite3Wrapper::constraint_primarykey(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CONSTRAINT_PRIMARYKEY;
}

int Sqlite3Wrapper::constraint_trigger(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CONSTRAINT_TRIGGER;
}

int Sqlite3Wrapper::constraint_unique(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CONSTRAINT_UNIQUE;
}

int Sqlite3Wrapper::constraint_vtab(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CONSTRAINT_VTAB;
}

int Sqlite3Wrapper::constraint_rowid(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CONSTRAINT_ROWID;
}

int Sqlite3Wrapper::constraint_pinned(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CONSTRAINT_PINNED;
}

int Sqlite3Wrapper::constraint_datatype(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CONSTRAINT_DATATYPE;
}

int Sqlite3Wrapper::notice_recover_wal(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_NOTICE_RECOVER_WAL;
}

int Sqlite3Wrapper::notice_recover_rollback(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_NOTICE_RECOVER_ROLLBACK;
}

int Sqlite3Wrapper::notice_rbu(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_NOTICE_RBU;
}

int Sqlite3Wrapper::warning_autoindex(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_WARNING_AUTOINDEX;
}

int Sqlite3Wrapper::auth_user(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_AUTH_USER;
}

int Sqlite3Wrapper::ok_load_permanently(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_OK_LOAD_PERMANENTLY;
}

int Sqlite3Wrapper::ok_symlink(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_OK_SYMLINK;
}

int Sqlite3Wrapper::open_readonly(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_OPEN_READONLY;
}

int Sqlite3Wrapper::open_readwrite(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_OPEN_READWRITE;
}

int Sqlite3Wrapper::open_create(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_OPEN_CREATE;
}

int Sqlite3Wrapper::open_deleteonclose(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_OPEN_DELETEONCLOSE;
}

int Sqlite3Wrapper::open_exclusive(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_OPEN_EXCLUSIVE;
}

int Sqlite3Wrapper::open_autoproxy(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_OPEN_AUTOPROXY;
}

int Sqlite3Wrapper::open_uri(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_OPEN_URI;
}

int Sqlite3Wrapper::open_memory(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_OPEN_MEMORY;
}

int Sqlite3Wrapper::open_main_db(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_OPEN_MAIN_DB;
}

int Sqlite3Wrapper::open_temp_db(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_OPEN_TEMP_DB;
}

int Sqlite3Wrapper::open_transient_db(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_OPEN_TRANSIENT_DB;
}

int Sqlite3Wrapper::open_main_journal(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_OPEN_MAIN_JOURNAL;
}

int Sqlite3Wrapper::open_temp_journal(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_OPEN_TEMP_JOURNAL;
}

int Sqlite3Wrapper::open_subjournal(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_OPEN_SUBJOURNAL;
}

int Sqlite3Wrapper::open_super_journal(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_OPEN_SUPER_JOURNAL;
}

int Sqlite3Wrapper::open_nomutex(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_OPEN_NOMUTEX;
}

int Sqlite3Wrapper::open_fullmutex(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_OPEN_FULLMUTEX;
}

int Sqlite3Wrapper::open_sharedcache(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_OPEN_SHAREDCACHE;
}

int Sqlite3Wrapper::open_privatecache(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_OPEN_PRIVATECACHE;
}

int Sqlite3Wrapper::open_wal(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_OPEN_WAL;
}

int Sqlite3Wrapper::open_nofollow(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_OPEN_NOFOLLOW;
}

int Sqlite3Wrapper::open_exrescode(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_OPEN_EXRESCODE;
}

int Sqlite3Wrapper::open_master_journal(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_OPEN_MASTER_JOURNAL;
}

int Sqlite3Wrapper::iocap_atomic(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOCAP_ATOMIC;
}

int Sqlite3Wrapper::iocap_atomic512(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOCAP_ATOMIC512;
}

int Sqlite3Wrapper::iocap_atomic1k(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOCAP_ATOMIC1K;
}

int Sqlite3Wrapper::iocap_atomic2k(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOCAP_ATOMIC2K;
}

int Sqlite3Wrapper::iocap_atomic4k(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOCAP_ATOMIC4K;
}

int Sqlite3Wrapper::iocap_atomic8k(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOCAP_ATOMIC8K;
}

int Sqlite3Wrapper::iocap_atomic16k(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOCAP_ATOMIC16K;
}

int Sqlite3Wrapper::iocap_atomic32k(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOCAP_ATOMIC32K;
}

int Sqlite3Wrapper::iocap_atomic64k(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOCAP_ATOMIC64K;
}

int Sqlite3Wrapper::iocap_safe_append(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOCAP_SAFE_APPEND;
}

int Sqlite3Wrapper::iocap_sequential(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOCAP_SEQUENTIAL;
}

int Sqlite3Wrapper::iocap_undeletable_when_open(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOCAP_UNDELETABLE_WHEN_OPEN;
}

int Sqlite3Wrapper::iocap_powersafe_overwrite(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOCAP_POWERSAFE_OVERWRITE;
}

int Sqlite3Wrapper::iocap_immutable(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOCAP_IMMUTABLE;
}

int Sqlite3Wrapper::iocap_batch_atomic(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOCAP_BATCH_ATOMIC;
}

int Sqlite3Wrapper::iocap_subpage_read(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IOCAP_SUBPAGE_READ;
}

int Sqlite3Wrapper::lock_none(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_LOCK_NONE;
}

int Sqlite3Wrapper::lock_shared(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_LOCK_SHARED;
}

int Sqlite3Wrapper::lock_reserved(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_LOCK_RESERVED;
}

int Sqlite3Wrapper::lock_pending(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_LOCK_PENDING;
}

int Sqlite3Wrapper::lock_exclusive(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_LOCK_EXCLUSIVE;
}

int Sqlite3Wrapper::sync_normal(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_SYNC_NORMAL;
}

int Sqlite3Wrapper::sync_full(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_SYNC_FULL;
}

int Sqlite3Wrapper::sync_dataonly(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_SYNC_DATAONLY;
}

int Sqlite3Wrapper::fcntl_lockstate(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_LOCKSTATE;
}

int Sqlite3Wrapper::fcntl_get_lockproxyfile(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_GET_LOCKPROXYFILE;
}

int Sqlite3Wrapper::fcntl_set_lockproxyfile(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_SET_LOCKPROXYFILE;
}

int Sqlite3Wrapper::fcntl_last_errno(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_LAST_ERRNO;
}

int Sqlite3Wrapper::fcntl_size_hint(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_SIZE_HINT;
}

int Sqlite3Wrapper::fcntl_chunk_size(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_CHUNK_SIZE;
}

int Sqlite3Wrapper::fcntl_file_pointer(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_FILE_POINTER;
}

int Sqlite3Wrapper::fcntl_sync_omitted(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_SYNC_OMITTED;
}

int Sqlite3Wrapper::fcntl_win32_av_retry(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_WIN32_AV_RETRY;
}

int Sqlite3Wrapper::fcntl_persist_wal(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_PERSIST_WAL;
}

int Sqlite3Wrapper::fcntl_overwrite(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_OVERWRITE;
}

int Sqlite3Wrapper::fcntl_vfsname(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_VFSNAME;
}

int Sqlite3Wrapper::fcntl_powersafe_overwrite(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_POWERSAFE_OVERWRITE;
}

int Sqlite3Wrapper::fcntl_pragma(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_PRAGMA;
}

int Sqlite3Wrapper::fcntl_busyhandler(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_BUSYHANDLER;
}

int Sqlite3Wrapper::fcntl_tempfilename(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_TEMPFILENAME;
}

int Sqlite3Wrapper::fcntl_mmap_size(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_MMAP_SIZE;
}

int Sqlite3Wrapper::fcntl_trace(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_TRACE;
}

int Sqlite3Wrapper::fcntl_has_moved(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_HAS_MOVED;
}

int Sqlite3Wrapper::fcntl_sync(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_SYNC;
}

int Sqlite3Wrapper::fcntl_commit_phasetwo(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_COMMIT_PHASETWO;
}

int Sqlite3Wrapper::fcntl_win32_set_handle(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_WIN32_SET_HANDLE;
}

int Sqlite3Wrapper::fcntl_wal_block(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_WAL_BLOCK;
}

int Sqlite3Wrapper::fcntl_zipvfs(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_ZIPVFS;
}

int Sqlite3Wrapper::fcntl_rbu(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_RBU;
}

int Sqlite3Wrapper::fcntl_vfs_pointer(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_VFS_POINTER;
}

int Sqlite3Wrapper::fcntl_journal_pointer(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_JOURNAL_POINTER;
}

int Sqlite3Wrapper::fcntl_win32_get_handle(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_WIN32_GET_HANDLE;
}

int Sqlite3Wrapper::fcntl_pdb(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_PDB;
}

int Sqlite3Wrapper::fcntl_begin_atomic_write(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_BEGIN_ATOMIC_WRITE;
}

int Sqlite3Wrapper::fcntl_commit_atomic_write(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_COMMIT_ATOMIC_WRITE;
}

int Sqlite3Wrapper::fcntl_rollback_atomic_write(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_ROLLBACK_ATOMIC_WRITE;
}

int Sqlite3Wrapper::fcntl_lock_timeout(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_LOCK_TIMEOUT;
}

int Sqlite3Wrapper::fcntl_data_version(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_DATA_VERSION;
}

int Sqlite3Wrapper::fcntl_size_limit(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_SIZE_LIMIT;
}

int Sqlite3Wrapper::fcntl_ckpt_done(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_CKPT_DONE;
}

int Sqlite3Wrapper::fcntl_reserve_bytes(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_RESERVE_BYTES;
}

int Sqlite3Wrapper::fcntl_ckpt_start(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_CKPT_START;
}

int Sqlite3Wrapper::fcntl_external_reader(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_EXTERNAL_READER;
}

int Sqlite3Wrapper::fcntl_cksm_file(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_CKSM_FILE;
}

int Sqlite3Wrapper::fcntl_reset_cache(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_RESET_CACHE;
}

int Sqlite3Wrapper::fcntl_null_io(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_NULL_IO;
}

int Sqlite3Wrapper::fcntl_block_on_connect(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_BLOCK_ON_CONNECT;
}

int Sqlite3Wrapper::fcntl_filestat(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FCNTL_FILESTAT;
}

int Sqlite3Wrapper::get_lockproxyfile(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_GET_LOCKPROXYFILE;
}

int Sqlite3Wrapper::set_lockproxyfile(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_SET_LOCKPROXYFILE;
}

int Sqlite3Wrapper::last_errno(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_LAST_ERRNO;
}

int Sqlite3Wrapper::access_exists(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_ACCESS_EXISTS;
}

int Sqlite3Wrapper::access_readwrite(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_ACCESS_READWRITE;
}

int Sqlite3Wrapper::access_read(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_ACCESS_READ;
}

int Sqlite3Wrapper::shm_unlock(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_SHM_UNLOCK;
}

int Sqlite3Wrapper::shm_lock(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_SHM_LOCK;
}

int Sqlite3Wrapper::shm_shared(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_SHM_SHARED;
}

int Sqlite3Wrapper::shm_exclusive(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_SHM_EXCLUSIVE;
}

int Sqlite3Wrapper::shm_nlock(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_SHM_NLOCK;
}

int Sqlite3Wrapper::initialize(void) { // NOLINT(readability-convert-member-functions-to-static)
    return ::sqlite3_initialize();
}

int Sqlite3Wrapper::shutdown(void) { // NOLINT(readability-convert-member-functions-to-static)
    return ::sqlite3_shutdown();
}

int Sqlite3Wrapper::os_init(void) { // NOLINT(readability-convert-member-functions-to-static)
    return ::sqlite3_os_init();
}

int Sqlite3Wrapper::os_end(void) { // NOLINT(readability-convert-member-functions-to-static)
    return ::sqlite3_os_end();
}

int Sqlite3Wrapper::config(int64_t option) { // NOLINT(readability-convert-member-functions-to-static)
    (void)option;
    ERR_PRINT("sqlite3_config is not supported via Godot due to variadic arguments and safety concerns.");
    return -1;
}

int Sqlite3Wrapper::db_config(const Ref<Sqlite3Handle>& db, int op, const Array& args) { // NOLINT(readability-convert-member-functions-to-static)
    // Validate handle
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_MISUSE);

    // The sqlite3_db_config function is variadic, so we need to handle possible argument types.
    // We'll support up to 3 optional arguments (expand as needed for common use-cases).
    int result = SQLITE_MISUSE;

    switch (args.size()) {
        case 0:
            result = ::sqlite3_db_config(db->handle, op);
            break;
        case 1:
            result = ::sqlite3_db_config(db->handle, op, (int)args[0]);
            break;
        case 2:
            result = ::sqlite3_db_config(db->handle, op, (int)args[0], (int)args[1]);
            break;
        case 3:
            result = ::sqlite3_db_config(db->handle, op, (int)args[0], (int)args[1], (int)args[2]);
            break;
        default:
            ERR_PRINT("sqlite3_db_config: Too many arguments in 'args' Array (max 3 supported)");
            return SQLITE_MISUSE;
    }

    return result;
}

int Sqlite3Wrapper::sqlite_config_singlethread(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CONFIG_SINGLETHREAD;
}

int Sqlite3Wrapper::sqlite_config_multithread(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CONFIG_MULTITHREAD;
}

int Sqlite3Wrapper::sqlite_config_serialized(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CONFIG_SERIALIZED;
}

int Sqlite3Wrapper::sqlite_config_malloc(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CONFIG_MALLOC;
}

int Sqlite3Wrapper::sqlite_config_getmalloc(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CONFIG_GETMALLOC;
}

int Sqlite3Wrapper::sqlite_config_scratch(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CONFIG_SCRATCH;
}

int Sqlite3Wrapper::sqlite_config_pagecache(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CONFIG_PAGECACHE;
}

int Sqlite3Wrapper::sqlite_config_heap(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CONFIG_HEAP;
}

int Sqlite3Wrapper::sqlite_config_memstatus(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CONFIG_MEMSTATUS;
}

int Sqlite3Wrapper::sqlite_config_mutex(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CONFIG_MUTEX;
}

int Sqlite3Wrapper::sqlite_config_getmutex(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CONFIG_GETMUTEX;
}

int Sqlite3Wrapper::sqlite_config_lookaside(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CONFIG_LOOKASIDE;
}

int Sqlite3Wrapper::sqlite_config_pcache(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CONFIG_PCACHE;
}

int Sqlite3Wrapper::sqlite_config_getpcache(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CONFIG_GETPCACHE;
}

int Sqlite3Wrapper::sqlite_config_log(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CONFIG_LOG;
}

int Sqlite3Wrapper::sqlite_config_uri(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CONFIG_URI;
}

int Sqlite3Wrapper::sqlite_config_pcache2(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CONFIG_PCACHE2;
}

int Sqlite3Wrapper::sqlite_config_getpcache2(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CONFIG_GETPCACHE2;
}

int Sqlite3Wrapper::sqlite_config_covering_index_scan(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CONFIG_COVERING_INDEX_SCAN;
}

int Sqlite3Wrapper::sqlite_config_sqllog(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CONFIG_SQLLOG;
}

int Sqlite3Wrapper::sqlite_config_mmap_size(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CONFIG_MMAP_SIZE;
}

int Sqlite3Wrapper::sqlite_config_win32_heapsize(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CONFIG_WIN32_HEAPSIZE;
}

int Sqlite3Wrapper::sqlite_config_pcache_hdrsz(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CONFIG_PCACHE_HDRSZ;
}

int Sqlite3Wrapper::sqlite_config_pmasz(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CONFIG_PMASZ;
}

int Sqlite3Wrapper::sqlite_config_stmtjrnl_spill(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CONFIG_STMTJRNL_SPILL;
}

int Sqlite3Wrapper::sqlite_config_small_malloc(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CONFIG_SMALL_MALLOC;
}

int Sqlite3Wrapper::sqlite_config_sorterref_size(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CONFIG_SORTERREF_SIZE;
}

int Sqlite3Wrapper::sqlite_config_memdb_maxsize(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CONFIG_MEMDB_MAXSIZE;
}

int Sqlite3Wrapper::sqlite_config_rowid_in_view(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CONFIG_ROWID_IN_VIEW;
}

int Sqlite3Wrapper::dbconfig_maindbname(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DBCONFIG_MAINDBNAME;
}

int Sqlite3Wrapper::dbconfig_lookaside(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DBCONFIG_LOOKASIDE;
}

int Sqlite3Wrapper::dbconfig_enable_fkey(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DBCONFIG_ENABLE_FKEY;
}

int Sqlite3Wrapper::dbconfig_enable_trigger(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DBCONFIG_ENABLE_TRIGGER;
}

int Sqlite3Wrapper::dbconfig_enable_fts3_tokenizer(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DBCONFIG_ENABLE_FTS3_TOKENIZER;
}

int Sqlite3Wrapper::dbconfig_enable_load_extension(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DBCONFIG_ENABLE_LOAD_EXTENSION;
}

int Sqlite3Wrapper::dbconfig_no_ckpt_on_close(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DBCONFIG_NO_CKPT_ON_CLOSE;
}

int Sqlite3Wrapper::dbconfig_enable_qpsg(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DBCONFIG_ENABLE_QPSG;
}

int Sqlite3Wrapper::dbconfig_trigger_eqp(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DBCONFIG_TRIGGER_EQP;
}

int Sqlite3Wrapper::dbconfig_reset_database(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DBCONFIG_RESET_DATABASE;
}

int Sqlite3Wrapper::dbconfig_defensive(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DBCONFIG_DEFENSIVE;
}

int Sqlite3Wrapper::dbconfig_writable_schema(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DBCONFIG_WRITABLE_SCHEMA;
}

int Sqlite3Wrapper::dbconfig_legacy_alter_table(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DBCONFIG_LEGACY_ALTER_TABLE;
}

int Sqlite3Wrapper::dbconfig_dqs_dml(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DBCONFIG_DQS_DML;
}

int Sqlite3Wrapper::dqs_ddl(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DBCONFIG_DQS_DDL;
}

int Sqlite3Wrapper::enable_view(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DBCONFIG_ENABLE_VIEW;
}

int Sqlite3Wrapper::legacy_file_format(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DBCONFIG_LEGACY_FILE_FORMAT;
}

int Sqlite3Wrapper::trusted_schema(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DBCONFIG_TRUSTED_SCHEMA;
}

int Sqlite3Wrapper::stmt_scanstatus(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DBCONFIG_STMT_SCANSTATUS;
}

int Sqlite3Wrapper::reverse_scanorder(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DBCONFIG_REVERSE_SCANORDER;
}

int Sqlite3Wrapper::enable_attach_create(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DBCONFIG_ENABLE_ATTACH_CREATE;
}

int Sqlite3Wrapper::enable_attach_write(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DBCONFIG_ENABLE_ATTACH_WRITE;
}

int Sqlite3Wrapper::enable_comments(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DBCONFIG_ENABLE_COMMENTS;
}

int Sqlite3Wrapper::fp_digits(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DBCONFIG_FP_DIGITS;
}

int Sqlite3Wrapper::max(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DBCONFIG_MAX;
}

int Sqlite3Wrapper::extended_result_codes(const Ref<Sqlite3Handle>& db, int onoff) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_MISUSE);
    return ::sqlite3_extended_result_codes(db->handle, int(onoff));
}

int64_t Sqlite3Wrapper::changes64(const Ref<Sqlite3Handle>& db) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), 0);
    return ::sqlite3_changes64(db->handle);
}

int Sqlite3Wrapper::total_changes64(const Ref<Sqlite3Handle>& db) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), 0);
    return (int)::sqlite3_total_changes64(db->handle);
}

int Sqlite3Wrapper::is_interrupted(const Ref<Sqlite3Handle>& db) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    return ::sqlite3_is_interrupted(db->handle);
}

int Sqlite3Wrapper::complete16(const String& sql) { // NOLINT(readability-convert-member-functions-to-static)
    Char16String utf16 = sql.utf16();
    int result = ::sqlite3_complete16((const void *)utf16.ptr());
    return result;
}

int Sqlite3Wrapper::busy_handler(const Ref<Sqlite3Handle>& db, Callable handler) { // NOLINT(readability-convert-member-functions-to-static)
    // Static registry for handler contexts
    static std::unordered_map<sqlite3*, void*> _busy_handler_contexts;
    static std::mutex _busy_handler_mutex;

    struct _BusyHandlerContext {
        Callable cb;
    };

    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_MISUSE);
    sqlite3* raw_db = db->handle;

    {
        std::lock_guard<std::mutex> lock(_busy_handler_mutex);
        // If a handler is already set for this db, free it
        auto it = _busy_handler_contexts.find(raw_db);
        if (it != _busy_handler_contexts.end()) {
            memdelete(reinterpret_cast<_BusyHandlerContext*>(it->second));
            _busy_handler_contexts.erase(it);
        }
    }

    if (!handler.is_valid()) {
        // Remove busy handler and free context
        return ::sqlite3_busy_handler(raw_db, nullptr, nullptr);
    }

    // Allocate new context
    _BusyHandlerContext* ctx = memnew(_BusyHandlerContext);
    ctx->cb = handler;
    {
        std::lock_guard<std::mutex> lock(_busy_handler_mutex);
        _busy_handler_contexts[raw_db] = ctx;
    }

    // Trampoline function
    auto trampoline = [](void* ud, int count) -> int {
        sqlite3* db_ptr = reinterpret_cast<sqlite3*>(ud);
        _BusyHandlerContext* ctx = nullptr;
        {
            std::lock_guard<std::mutex> lock(_busy_handler_mutex);
            auto it = _busy_handler_contexts.find(db_ptr);
            if (it != _busy_handler_contexts.end()) {
                ctx = reinterpret_cast<_BusyHandlerContext*>(it->second);
            }
        }
        if (!ctx || !ctx->cb.is_valid()) {
            return 0;
        }
        Array args;
        args.push_back(count);
        Variant ret = ctx->cb.callv(args);
        if (ret.get_type() != Variant::INT) {
            ERR_PRINT("Busy handler must return int. Returning 0.");
            return 0;
        }
        return int(ret);
    };

    // Note: pass raw_db as user data so we can look up the context by db pointer
    return ::sqlite3_busy_handler(raw_db, trampoline, raw_db);
}

void Sqlite3Wrapper::free_table(int64_t result_ptr) { // NOLINT(readability-convert-member-functions-to-static)
    ::sqlite3_free_table(reinterpret_cast<char **>(result_ptr));
}

String Sqlite3Wrapper::mprintf(const String& format) { // NOLINT(readability-convert-member-functions-to-static)
    CharString fmt_cs = format.utf8();
    char *res = ::sqlite3_mprintf(fmt_cs.get_data());
    String gd_str = res ? String::utf8(res) : String();
    if (res) {
        ::sqlite3_free(res);
    }
    return gd_str;
}

String Sqlite3Wrapper::vmprintf(const String& format) { // NOLINT(readability-convert-member-functions-to-static)
    (void)format;
    ERR_PRINT("sqlite3_vmprintf cannot be used from Godot: va_list arguments are unsupported in this context.");
    return String();
}

int64_t Sqlite3Wrapper::malloc(int64_t n_bytes) { // NOLINT(readability-convert-member-functions-to-static)
    void *ptr = ::sqlite3_malloc((int)n_bytes);
    return reinterpret_cast<int64_t>(ptr);
}

int64_t Sqlite3Wrapper::malloc64(int64_t size) { // NOLINT(readability-convert-member-functions-to-static)
    if (size < 0) return 0;
    void *ptr = ::sqlite3_malloc64((sqlite3_uint64)size);
    return reinterpret_cast<int64_t>(ptr);
}

int64_t Sqlite3Wrapper::realloc(int64_t ptr, int size) { // NOLINT(readability-convert-member-functions-to-static)
    void *result = ::sqlite3_realloc(reinterpret_cast<void *>(ptr), size);
    return reinterpret_cast<int64_t>(result);
}

int64_t Sqlite3Wrapper::realloc64(int64_t ptr, int64_t new_size) { // NOLINT(readability-convert-member-functions-to-static)
    void *result = ::sqlite3_realloc64(reinterpret_cast<void*>(ptr), (sqlite3_uint64)new_size);
    return reinterpret_cast<int64_t>(result);
}

int64_t Sqlite3Wrapper::msize(int64_t ptr) { // NOLINT(readability-convert-member-functions-to-static)
    return (int64_t)::sqlite3_msize(reinterpret_cast<void*>(ptr));
}

int Sqlite3Wrapper::memory_used(void) { // NOLINT(readability-convert-member-functions-to-static)
    return ::sqlite3_memory_used();
}

int64_t Sqlite3Wrapper::memory_highwater(int64_t reset_flag) { // NOLINT(readability-convert-member-functions-to-static)
    return ::sqlite3_memory_highwater((int)reset_flag);
}

PackedByteArray Sqlite3Wrapper::randomness(int64_t n) { // NOLINT(readability-convert-member-functions-to-static)
    PackedByteArray arr;
    if (n > 0) {
        arr.resize(n);
        sqlite3_randomness((int)n, arr.ptrw());
    } else {
        sqlite3_randomness(0, nullptr);
    }
    return arr;
}

int Sqlite3Wrapper::set_authorizer(const Ref<Sqlite3Handle>& db, Callable x_auth) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_MISUSE);
    ERR_FAIL_COND_V(!x_auth.is_valid(), SQLITE_MISUSE);

    struct _AuthorizerCtx {
        Callable cb;
    } ctx { x_auth };

    auto trampoline = [](void *ud, int action_code, const char *param1, const char *param2, const char *param3, const char *param4) -> int {
        _AuthorizerCtx *ctx = reinterpret_cast<_AuthorizerCtx *>(ud);
        Array args;
        args.push_back((int64_t)action_code);
        args.push_back(param1 ? String::utf8(param1) : String());
        args.push_back(param2 ? String::utf8(param2) : String());
        args.push_back(param3 ? String::utf8(param3) : String());
        args.push_back(param4 ? String::utf8(param4) : String());
        Variant ret = ctx->cb.callv(args);
        if (ret.get_type() != Variant::INT) {
            ERR_PRINT("sqlite3_set_authorizer Callable must return int, got: " + ret.stringify() + " (" + Variant::get_type_name(ret.get_type()) + ")");
            return SQLITE_DENY;
        }
        return (int)ret;
    };
    return ::sqlite3_set_authorizer(db->handle, trampoline, &ctx);
}

int64_t Sqlite3Wrapper::trace(const Ref<Sqlite3Handle>& db, Callable trace_callback) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), 0);

    struct _TraceCtx {
        Callable cb;
    };

    _TraceCtx *ctx = nullptr;
    void (*trampoline)(void *, const char *) = nullptr;

    if (trace_callback.is_valid()) {
        ctx = memnew(_TraceCtx);
        ctx->cb = trace_callback;
        trampoline = [](void *ud, const char *sql) {
            _TraceCtx *ctx = reinterpret_cast<_TraceCtx *>(ud);
            if (!ctx->cb.is_valid()) return;
            Array args;
            args.push_back(sql ? String::utf8(sql) : String());
            ctx->cb.callv(args);
        };
    }

    void *ret = ::sqlite3_trace(db->handle, trampoline, ctx);
    return reinterpret_cast<int64_t>(ret);
}

int Sqlite3Wrapper::trace_v2(const Ref<Sqlite3Handle>& db, int64_t mask, Callable callback) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);

    // Context struct for the callback.
    struct _TraceContext {
        Callable cb;
    };
    _TraceContext *ctx = nullptr;
    if (callback.is_valid()) {
        ctx = memnew(_TraceContext);
        ctx->cb = callback;
    }

    // Trampoline function for C callback.
    auto trampoline = [](unsigned type, void *user_ctx, void *p1, void *p2) -> int {
        _TraceContext *ctx = reinterpret_cast<_TraceContext *>(user_ctx);
        if (!ctx || !ctx->cb.is_valid()) {
            return 0;
        }
        Array args;
        args.push_back((int64_t)type);
        args.push_back(p1 ? Variant((int64_t)(intptr_t)p1) : Variant());
        args.push_back(p2 ? Variant((int64_t)(intptr_t)p2) : Variant());
        Variant ret = ctx->cb.callv(args);
        if (ret.get_type() == Variant::INT) {
            return int(ret);
        }
        return 0;
    };

    // If callback is invalid or mask is zero, tracing is disabled.
    int result = ::sqlite3_trace_v2(db->handle, int(mask), callback.is_valid() ? +trampoline : nullptr, ctx);
    return result;
}

String Sqlite3Wrapper::uri_parameter(const String& z, const String& z_param) { // NOLINT(readability-convert-member-functions-to-static)
    godot::CharString z_cs = z.utf8();
    godot::CharString param_cs = z_param.utf8();
    const char *ret = ::sqlite3_uri_parameter(z_cs.get_data(), param_cs.get_data());
    if (ret == nullptr) {
        return String();
    }
    return String::utf8(ret);
}

int Sqlite3Wrapper::uri_boolean(const String& z, const String& z_param, int b_default) { // NOLINT(readability-convert-member-functions-to-static)
    CharString z_utf8 = z.utf8();
    CharString z_param_utf8 = z_param.utf8();
    int result = ::sqlite3_uri_boolean(z_utf8.get_data(), z_param_utf8.get_data(), b_default);
    return result;
}

int64_t Sqlite3Wrapper::uri_int64(const String& filename, const String& param, int64_t default_value) { // NOLINT(readability-convert-member-functions-to-static)
    CharString filename_cs = filename.utf8();
    CharString param_cs = param.utf8();
    return ::sqlite3_uri_int64(filename_cs.get_data(), param_cs.get_data(), default_value);
}

String Sqlite3Wrapper::uri_key(const String& z, int index) { // NOLINT(readability-convert-member-functions-to-static)
    CharString z_cs = z.utf8();
    const char *ret = ::sqlite3_uri_key(z_cs.get_data(), index);
    return ret ? String::utf8(ret) : String();
}

String Sqlite3Wrapper::filename_database(const String& filename) { // NOLINT(readability-convert-member-functions-to-static)
    CharString cs = filename.utf8();
    const char *result = ::sqlite3_filename_database(cs.get_data());
    return result ? String(result) : String();
}

String Sqlite3Wrapper::filename_journal(const String& filename) { // NOLINT(readability-convert-member-functions-to-static)
    CharString cs = filename.utf8();
    const char *result = ::sqlite3_filename_journal(cs.get_data());
    return result ? String(result) : String();
}

String Sqlite3Wrapper::filename_wal(const String& filename) { // NOLINT(readability-convert-member-functions-to-static)
    CharString cs_filename = filename.utf8();
    const char *result = ::sqlite3_filename_wal(cs_filename.get_data());
    if (!result) {
        return String();
    }
    return String(result);
}

Ref<Sqlite3FileHandle> Sqlite3Wrapper::database_file_object(const String& filename) { // NOLINT(readability-convert-member-functions-to-static)
    CharString cs = filename.utf8();
    sqlite3_file *result = ::sqlite3_database_file_object(cs.get_data());
    if (result) {
        Ref<Sqlite3FileHandle> ref;
        ref.instantiate();
        ref->set_handle(reinterpret_cast<intptr_t>(result));
        return ref;
    }
    return Ref<Sqlite3FileHandle>();
}

Ref<Sqlite3FilenameHandle> Sqlite3Wrapper::create_filename(const String& database, const String& journal, const String& wal, int64_t n_param, PackedStringArray az_param) { // NOLINT(readability-convert-member-functions-to-static)
    // Validate that database, journal, and wal are not null (they may be empty strings).
    ERR_FAIL_COND_V(database.is_empty(), Ref<Sqlite3FilenameHandle>());
    ERR_FAIL_COND_V(journal.is_empty(), Ref<Sqlite3FilenameHandle>());
    ERR_FAIL_COND_V(wal.is_empty(), Ref<Sqlite3FilenameHandle>());
    if (n_param > 0) {
        ERR_FAIL_COND_V(az_param.size() != n_param * 2, Ref<Sqlite3FilenameHandle>());
    }

    // Prepare C string arrays
    CharString db_cs = database.utf8();
    CharString journal_cs = journal.utf8();
    CharString wal_cs = wal.utf8();
    std::vector<CharString> param_cs;
    std::vector<const char *> param_ptrs;
    if (n_param > 0) {
        param_cs.reserve(az_param.size());
        param_ptrs.reserve(az_param.size());
        for (int i = 0; i < az_param.size(); ++i) {
            param_cs.push_back(az_param[i].utf8());
            param_ptrs.push_back(param_cs.back().get_data());
        }
    }
    const char **c_param_ptr = (n_param > 0) ? param_ptrs.data() : nullptr;

    // Call SQLite
    sqlite3_filename handle = ::sqlite3_create_filename(db_cs.get_data(), journal_cs.get_data(), wal_cs.get_data(), (int)n_param, c_param_ptr);
    if (!handle) {
        return Ref<Sqlite3FilenameHandle>();
    }
    Ref<Sqlite3FilenameHandle> ref;
    ref.instantiate();
    ref->set_handle(reinterpret_cast<intptr_t>(handle));
    return ref;
}

void Sqlite3Wrapper::free_filename(int64_t filename_ptr) { // NOLINT(readability-convert-member-functions-to-static)
    ::sqlite3_free_filename(reinterpret_cast<sqlite3_filename>(filename_ptr));
}

int Sqlite3Wrapper::errcode(const Ref<Sqlite3Handle>& db) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    return ::sqlite3_errcode(db->handle);
}

int Sqlite3Wrapper::extended_errcode(const Ref<Sqlite3Handle>& db) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    return ::sqlite3_extended_errcode(db->handle);
}

String Sqlite3Wrapper::errmsg(const Ref<Sqlite3Handle>& db) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), String());
    const char *msg = ::sqlite3_errmsg(db->handle);
    return String::utf8(msg);
}

String Sqlite3Wrapper::errstr(int error_code) { // NOLINT(readability-convert-member-functions-to-static)
    return String(::sqlite3_errstr(error_code));
}

int Sqlite3Wrapper::limit(const Ref<Sqlite3Handle>& db, int id, int new_value) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    return ::sqlite3_limit(db->handle, id, new_value);
}

String Sqlite3Wrapper::expanded_sql(const Ref<Sqlite3StmtHandle>& p_stmt) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(p_stmt.is_null() || !p_stmt->is_valid(), String());
    char *expanded = ::sqlite3_expanded_sql(p_stmt->handle);
    if (expanded) {
        String result = String::utf8(expanded);
        ::sqlite3_free(expanded);
        return result;
    } else {
        return String();
    }
}

int Sqlite3Wrapper::bind_blob(const Ref<Sqlite3StmtHandle>& stmt, int64_t index, const PackedByteArray& data) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), SQLITE_MISUSE);
    const void *blob_ptr = nullptr;
    int blob_size = 0;
    if (data.size() > 0) {
        blob_ptr = data.ptr();
        blob_size = data.size();
    }
    return ::sqlite3_bind_blob(stmt->handle, (int)index, blob_ptr, blob_size, SQLITE_TRANSIENT);
}

int Sqlite3Wrapper::bind_blob64(const Ref<Sqlite3StmtHandle>& stmt, int64_t index, const PackedByteArray& blob, int64_t destructor) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), SQLITE_MISUSE);
    const void *data_ptr = blob.size() > 0 ? blob.ptr() : nullptr;
    sqlite3_uint64 size = (sqlite3_uint64)blob.size();
    void (*dtor)(void*) = nullptr;
    if (destructor == -1) {
        dtor = (void(*)(void*))-1; // SQLITE_TRANSIENT
    } else if (destructor == 0) {
        dtor = nullptr; // SQLITE_STATIC
    } else {
        dtor = (void(*)(void*))destructor;
    }
    return ::sqlite3_bind_blob64(stmt->handle, (int)index, data_ptr, size, dtor);
}

int Sqlite3Wrapper::bind_int64(const Ref<Sqlite3StmtHandle>& stmt, int index, int value) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), -1);
    return ::sqlite3_bind_int64(stmt->handle, index, value);
}

int Sqlite3Wrapper::bind_zeroblob(const Ref<Sqlite3StmtHandle>& stmt, int index, int n) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), -1);
    return ::sqlite3_bind_zeroblob(stmt->handle, index, n);
}

String Sqlite3Wrapper::column_name16(const Ref<Sqlite3StmtHandle>& stmt, int n) { // NOLINT(readability-convert-member-functions-to-static)
    if (stmt.is_null() || !stmt->is_valid()) {
        return String();
    }
    const void *ptr = ::sqlite3_column_name16(stmt->handle, n);
    if (!ptr) {
        return String();
    }
    const char16_t *u16str = reinterpret_cast<const char16_t *>(ptr);
    int len = 0;
    while (u16str[len] != 0) {
        len++;
    }
    return String::utf16(u16str, len);
}

String Sqlite3Wrapper::column_database_name16(const Ref<Sqlite3StmtHandle>& stmt, int col) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), String());
    const void *ptr = ::sqlite3_column_database_name16(stmt->handle, col);
    if (!ptr) {
        return String();
    }
    const char16_t *utf16_str = reinterpret_cast<const char16_t *>(ptr);
    size_t len = 0;
    while (utf16_str[len] != 0) {
        len++;
    }
    return String::utf16(utf16_str, len);
}

String Sqlite3Wrapper::column_table_name(const Ref<Sqlite3StmtHandle>& stmt, int column) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), String());
    const char *result = ::sqlite3_column_table_name(stmt->handle, column);
    return result ? String(result) : String();
}

String Sqlite3Wrapper::column_decltype16(const Ref<Sqlite3StmtHandle>& stmt, int col) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), String());
    const void *result = ::sqlite3_column_decltype16(stmt->handle, col);
    if (!result) {
        return String();
    }
    const char16_t *utf16_str = reinterpret_cast<const char16_t *>(result);
    int length = 0;
    while (utf16_str[length] != 0) {
        ++length;
    }
    return String::utf16(utf16_str, length);
}

int Sqlite3Wrapper::sqlite_text(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TEXT;
}

int Sqlite3Wrapper::sqlite3_text(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE3_TEXT;
}

PackedByteArray Sqlite3Wrapper::column_blob(const Ref<Sqlite3StmtHandle>& stmt, int i_col) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), PackedByteArray());
    const void *blob_ptr = ::sqlite3_column_blob(stmt->handle, i_col);
    int size = ::sqlite3_column_bytes(stmt->handle, i_col);
    if (!blob_ptr || size <= 0) {
        return PackedByteArray();
    }
    PackedByteArray arr;
    arr.resize(size);
    std::memcpy(arr.ptrw(), blob_ptr, size);
    return arr;
}

double Sqlite3Wrapper::column_double(const Ref<Sqlite3StmtHandle>& stmt, int64_t i_col) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), 0.0);
    return ::sqlite3_column_double(stmt->handle, (int)i_col);
}

int Sqlite3Wrapper::column_int(const Ref<Sqlite3StmtHandle>& stmt, int i_col) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), 0);
    return ::sqlite3_column_int(stmt->handle, i_col);
}

int64_t Sqlite3Wrapper::column_int64(const Ref<Sqlite3StmtHandle>& stmt, int64_t i_col) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), 0);
    return (int64_t)::sqlite3_column_int64(stmt->handle, (int)i_col);
}

PackedByteArray Sqlite3Wrapper::value_blob(const Ref<Sqlite3ValueHandle>& value) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(value.is_null() || !value->is_valid(), PackedByteArray());
    const void *ptr = ::sqlite3_value_blob(value->handle);
    int size = ::sqlite3_value_bytes(value->handle);
    if (!ptr || size <= 0) {
        return PackedByteArray();
    }
    PackedByteArray arr;
    arr.resize(size);
    memcpy(arr.ptrw(), ptr, size);
    return arr;
}

double Sqlite3Wrapper::value_double(const Ref<Sqlite3ValueHandle>& value) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(value.is_null() || !value->is_valid(), 0.0);
    return ::sqlite3_value_double(value->handle);
}

int Sqlite3Wrapper::value_int(const Ref<Sqlite3ValueHandle>& value) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(value.is_null() || !value->is_valid(), 0);
    return ::sqlite3_value_int(value->handle);
}

int64_t Sqlite3Wrapper::value_int64(const Ref<Sqlite3ValueHandle>& db_value) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db_value.is_null() || !db_value->is_valid(), 0);
    return ::sqlite3_value_int64(db_value->handle);
}

int Sqlite3Wrapper::value_pointer(const Ref<Sqlite3ValueHandle>& value, const String& type_name) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(value.is_null() || !value->is_valid(), 0);
    CharString type_name_utf8 = type_name.utf8();
    void *ptr = ::sqlite3_value_pointer(value->handle, type_name_utf8.get_data());
    return reinterpret_cast<intptr_t>(ptr);
}

int Sqlite3Wrapper::value_bytes(const Ref<Sqlite3ValueHandle>& value) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(value.is_null() || !value->is_valid(), 0);
    return ::sqlite3_value_bytes(value->handle);
}

void Sqlite3Wrapper::value_free(const Ref<Sqlite3ValueHandle>& value) { // NOLINT(readability-convert-member-functions-to-static)
    if (value.is_null() || !value->is_valid()) {
        return;
    }
    ::sqlite3_value_free(reinterpret_cast<sqlite3_value*>(value->get_handle()));
    value->set_handle(0);
}

void Sqlite3Wrapper::set_auxdata(const Ref<Sqlite3ContextHandle>& context, int n, const Variant& auxdata, Callable destructor) { // NOLINT(readability-convert-member-functions-to-static)
    // We need to allocate both the Variant and the Callable context for the destructor to use.
    struct _AuxCtx {
        Variant *auxdata;
        Callable destructor;
    };

    _AuxCtx *ctx = memnew(_AuxCtx);
    ctx->auxdata = memnew(Variant(auxdata));
    ctx->destructor = destructor;

    // The trampoline to be called by SQLite when auxdata is destroyed.
    auto trampoline = [](void *ptr) {
        _AuxCtx *ctx = reinterpret_cast<_AuxCtx *>(ptr);
        if (ctx && ctx->destructor.is_valid()) {
            Array args;
            args.push_back(*(ctx->auxdata));
            ctx->destructor.callv(args);
        }
        memdelete(ctx->auxdata);
        memdelete(ctx);
    };

    ::sqlite3_set_auxdata(context->handle, n, ctx, trampoline);
}

int Sqlite3Wrapper::set_clientdata(const Ref<Sqlite3Handle>& db, const String& key, int64_t client_data_ptr, int64_t cleanup_callback_ptr) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    CharString key_utf8 = key.utf8();
    return ::sqlite3_set_clientdata(db->handle, key_utf8.get_data(), reinterpret_cast<void *>(client_data_ptr), reinterpret_cast<void(*)(void*)>(cleanup_callback_ptr));
}

int64_t Sqlite3Wrapper::static_destructor_type(void) { // NOLINT(readability-convert-member-functions-to-static)
    return 0;
}

int64_t Sqlite3Wrapper::transient_destructor_type(void) { // NOLINT(readability-convert-member-functions-to-static)
    return -1;
}

void Sqlite3Wrapper::result_blob(const Ref<Sqlite3ContextHandle>& context, const PackedByteArray& data, bool is_transient) { // NOLINT(readability-convert-member-functions-to-static)
    #include <sqlite3.h>
    ERR_FAIL_COND(context.is_null() || !context->is_valid());
    const uint8_t *ptr = data.ptr();
    int len = data.size();
    void (*destructor)(void*) = is_transient ? SQLITE_TRANSIENT : SQLITE_STATIC;
    ::sqlite3_result_blob(context->handle, ptr, len, destructor);
}

void Sqlite3Wrapper::result_blob64(const Ref<Sqlite3ContextHandle>& ctx, const PackedByteArray& blob, int64_t destructor) { // NOLINT(readability-convert-member-functions-to-static)
    ::sqlite3_result_blob64(ctx->handle, blob.ptr(), blob.size(), (void(*)(void *))destructor);
}

void Sqlite3Wrapper::result_double(const Ref<Sqlite3ContextHandle>& ctx, double value) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND(ctx.is_null() || !ctx->is_valid());
    ::sqlite3_result_double(ctx->handle, value);
}

void Sqlite3Wrapper::result_error16(const Ref<Sqlite3ContextHandle>& context, const String& error_message, int nbytes) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND(context.is_null() || !context->is_valid());
    Char16String utf16 = error_message.utf16();
    const void *ptr = utf16.ptr();
    ::sqlite3_result_error16(context->handle, ptr, nbytes);
}

void Sqlite3Wrapper::result_error_nomem(const Ref<Sqlite3ContextHandle>& ctx) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND(ctx.is_null() || !ctx->is_valid());
    ::sqlite3_result_error_nomem(ctx->handle);
}

void Sqlite3Wrapper::result_value(const Ref<Sqlite3ContextHandle>& context, const Ref<Sqlite3ValueHandle>& value) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND(context.is_null() || !context->is_valid());
    ERR_FAIL_COND(value.is_null() || !value->is_valid());
    ::sqlite3_result_value(context->handle, value->handle);
}

int Sqlite3Wrapper::create_collation_v2(const Ref<Sqlite3Handle>& db, const String& name, int text_rep, Callable compare, Callable destroy) { // NOLINT(readability-convert-member-functions-to-static)
    // Validate inputs
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_MISUSE);
    ERR_FAIL_COND_V(!compare.is_valid(), SQLITE_MISUSE);

    struct _CollationCtx {
        Callable compare_cb;
        Callable destroy_cb;
    };

    _CollationCtx *ctx = memnew(_CollationCtx);
    ctx->compare_cb = compare;
    ctx->destroy_cb = destroy;

    auto xCompare = [](void *pArg, int n1, const void *p1, int n2, const void *p2) -> int {
        _CollationCtx *ctx = reinterpret_cast<_CollationCtx *>(pArg);
        PackedByteArray arg1;
        PackedByteArray arg2;
        if (p1 && n1 > 0) arg1.resize(n1);
        if (p2 && n2 > 0) arg2.resize(n2);
        if (n1 > 0 && p1) {
            memcpy(arg1.ptrw(), p1, n1);
        }
        if (n2 > 0 && p2) {
            memcpy(arg2.ptrw(), p2, n2);
        }
        Array args;
        args.push_back(arg1);
        args.push_back(arg2);
        Variant ret = ctx->compare_cb.callv(args);
        if (ret.get_type() != Variant::INT) {
            ERR_PRINT("Collation compare callback must return int");
            return 0;
        }
        return int(ret);
    };

    auto xDestroy = [](void *pArg) {
        _CollationCtx *ctx = reinterpret_cast<_CollationCtx *>(pArg);
        if (ctx->destroy_cb.is_valid()) {
            ctx->destroy_cb.call();
        }
        memdelete(ctx);
    };

    CharString name_utf8 = name.utf8();
    int result = ::sqlite3_create_collation_v2(
        db->handle,
        name_utf8.get_data(),
        text_rep,
        ctx,
        xCompare,
        xDestroy
    );
    return result;
}

int Sqlite3Wrapper::collation_needed16(const Ref<Sqlite3Handle>& db, Callable callback) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    ERR_FAIL_COND_V(!callback.is_valid(), -1);

    struct _CollationNeeded16Ctx {
        Callable cb;
    };
    static auto trampoline = [](void *user_data, sqlite3 *sqlite, int eTextRep, const void *collation_name_void) {
        _CollationNeeded16Ctx *ctx = reinterpret_cast<_CollationNeeded16Ctx *>(user_data);

        // Wrap sqlite3* as Ref<Sqlite3Handle>
        Ref<Sqlite3Handle> db_ref;
        db_ref.instantiate();
        db_ref->set_handle(reinterpret_cast<intptr_t>(sqlite));

        // Convert UTF-16 null-terminated collation_name to Godot String
        const char16_t *name16 = static_cast<const char16_t *>(collation_name_void);
        size_t len = 0;
        while (name16[len] != 0) {
            len++;
        }
        String collation_name = String::utf16((const char16_t *)name16, (int)len);

        Array args;
        args.push_back(db_ref);
        args.push_back(eTextRep);
        args.push_back(collation_name);
        ctx->cb.callv(args);
    };

    // Allocate context on heap to persist for the DB lifetime
    _CollationNeeded16Ctx *ctx = memnew(_CollationNeeded16Ctx);
    ctx->cb = callback;

    int result = ::sqlite3_collation_needed16(db->handle, ctx, trampoline);
    return result;
}

String Sqlite3Wrapper::get_temp_directory(void) { // NOLINT(readability-convert-member-functions-to-static)
    if (sqlite3_temp_directory != nullptr) {
        return String::utf8(sqlite3_temp_directory);
    } else {
        return String();
    }
}

void Sqlite3Wrapper::set_temp_directory(const String& path) { // NOLINT(readability-convert-member-functions-to-static)
    // Free previous directory if set
    if (sqlite3_temp_directory != nullptr) {
        sqlite3_free(sqlite3_temp_directory);
        sqlite3_temp_directory = nullptr;
    }
    if (!path.is_empty()) {
        CharString cs = path.utf8();
        size_t len = strlen(cs.get_data());
        // +1 for null terminator
        char *copy = (char *)sqlite3_malloc(len + 1);
        if (copy) {
            memcpy(copy, cs.get_data(), len + 1);
            sqlite3_temp_directory = copy;
        } else {
            ERR_PRINT("Failed to allocate memory for sqlite3_temp_directory");
        }
    }
}

String Sqlite3Wrapper::get_data_directory(void) { // NOLINT(readability-convert-member-functions-to-static)
    if (sqlite3_data_directory == nullptr) {
        return String();
    }
    return String::utf8(sqlite3_data_directory);
}

void Sqlite3Wrapper::set_data_directory(const String& dir) { // NOLINT(readability-convert-member-functions-to-static)
    if (sqlite3_data_directory != nullptr) {
        // DO NOT free here; the SQLite library may own this pointer (see docs)
        // User must ensure memory management is safe per SQLite documentation.
    }
    if (dir.is_empty()) {
        sqlite3_data_directory = nullptr;
        return;
    }
    CharString cs = dir.utf8();
    // Allocate a heap copy for SQLite to own (as per documentation)
    char *heap_copy = (char *)malloc(cs.length() + 1);
    memcpy(heap_copy, cs.get_data(), cs.length() + 1);
    sqlite3_data_directory = heap_copy;
}

#ifdef _WIN32
int Sqlite3Wrapper::win32_set_directory(int64_t type, const String& z_value) { // NOLINT(readability-convert-member-functions-to-static)
    if (z_value.is_empty()) {
        return ::sqlite3_win32_set_directory((unsigned long)type, nullptr);
    } else {
        CharString cs = z_value.utf8();
        return ::sqlite3_win32_set_directory((unsigned long)type, (void *)cs.get_data());
    }
}
#endif

#ifdef _WIN32
int Sqlite3Wrapper::sqlite3_win32_set_directory8(int64_t type, const String& z_value) { // NOLINT(readability-convert-member-functions-to-static)
    CharString z_value_utf8 = z_value.utf8();
    int result = ::sqlite3_win32_set_directory8((unsigned long)type, z_value_utf8.get_data());
    return result;
}
#endif

#ifdef _WIN32
int Sqlite3Wrapper::win32_set_directory16(int type, const String& value) { // NOLINT(readability-convert-member-functions-to-static)
    Char16String utf16 = value.utf16();
    std::vector<char16_t> buffer(utf16.length() + 1);
    memcpy(buffer.data(), utf16.ptr(), utf16.length() * sizeof(char16_t));
    buffer[utf16.length()] = 0;
    return ::sqlite3_win32_set_directory16((unsigned long)type, buffer.data());
}
#endif

#ifdef _WIN32
int Sqlite3Wrapper::win32_data_directory_type(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_WIN32_DATA_DIRECTORY_TYPE;
}
#endif

#ifdef _WIN32
int Sqlite3Wrapper::win32_temp_directory_type(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_WIN32_TEMP_DIRECTORY_TYPE;
}
#endif

int Sqlite3Wrapper::get_autocommit(const Ref<Sqlite3Handle>& db) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), 0);
    return ::sqlite3_get_autocommit(db->handle);
}

Ref<Sqlite3StmtHandle> Sqlite3Wrapper::next_stmt(const Ref<Sqlite3Handle>& db, const Ref<Sqlite3StmtHandle>& stmt) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), Ref<Sqlite3StmtHandle>());
    sqlite3_stmt *next = ::sqlite3_next_stmt(db->handle, (stmt.is_valid() && stmt->is_valid()) ? stmt->handle : nullptr);
    if (!next) {
        return Ref<Sqlite3StmtHandle>();
    }
    Ref<Sqlite3StmtHandle> out;
    out.instantiate();
    out->set_handle(reinterpret_cast<intptr_t>(next));
    return out;
}

int64_t Sqlite3Wrapper::rollback_hook(const Ref<Sqlite3Handle>& db, Callable callback) { // NOLINT(readability-convert-member-functions-to-static)
    // Validate input
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), 0);
    ERR_FAIL_COND_V(!callback.is_valid(), 0);

    // Define context struct
    struct RollbackHookCtx {
        Callable cb;
    };

    // Allocate context on the heap
    RollbackHookCtx *ctx = memnew(RollbackHookCtx);
    ctx->cb = callback;

    // Trampoline
    auto trampoline = [](void *user_data) {
        RollbackHookCtx *ctx = reinterpret_cast<RollbackHookCtx *>(user_data);
        if (ctx && ctx->cb.is_valid()) {
            ctx->cb.call();
        }
    };

    // Register hook and get previous user_data
    void *prev_userdata = ::sqlite3_rollback_hook(db->handle, trampoline, ctx);

    // Clean up previous context if we recognize it (optional; here, we do not attempt to delete foreign pointers)
    // If you previously set a rollback hook from Godot, you may want to track and memdelete(prev_userdata);

    return reinterpret_cast<int64_t>(prev_userdata);
}

int Sqlite3Wrapper::release_memory(int n) { // NOLINT(readability-convert-member-functions-to-static)
    return ::sqlite3_release_memory(n);
}

int Sqlite3Wrapper::db_release_memory(const Ref<Sqlite3Handle>& db) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    return ::sqlite3_db_release_memory(db->handle);
}

int Sqlite3Wrapper::hard_heap_limit64(int n) { // NOLINT(readability-convert-member-functions-to-static)
    return ::sqlite3_hard_heap_limit64(n);
}

void Sqlite3Wrapper::soft_heap_limit(int n) { // NOLINT(readability-convert-member-functions-to-static)
    ::sqlite3_soft_heap_limit((int)n);
}

Dictionary Sqlite3Wrapper::load_extension(const Ref<Sqlite3Handle>& db, const String& file, const String& proc) { // NOLINT(readability-convert-member-functions-to-static)
    Dictionary result_dict;
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), result_dict);
    CharString file_cs = file.utf8();
    const char *file_cstr = file_cs.get_data();
    const char *proc_cstr = nullptr;
    CharString proc_cs;
    if (!proc.is_empty()) {
        proc_cs = proc.utf8();
        proc_cstr = proc_cs.get_data();
    }
    char *err_msg = nullptr;
    int rc = ::sqlite3_load_extension(db->handle, file_cstr, proc_cstr, &err_msg);
    String err_string;
    if (err_msg) {
        err_string = String(err_msg);
        ::sqlite3_free(err_msg);
    } else {
        err_string = "";
    }
    result_dict["result"] = rc;
    result_dict["error_message"] = err_string;
    return result_dict;
}

int Sqlite3Wrapper::cancel_auto_extension(int64_t x_entry_point) { // NOLINT(readability-convert-member-functions-to-static)
    int result = ::sqlite3_cancel_auto_extension(reinterpret_cast<void(*)(void)>(x_entry_point));
    return result;
}

void Sqlite3Wrapper::reset_auto_extension(void) { // NOLINT(readability-convert-member-functions-to-static)
    ::sqlite3_reset_auto_extension();
}

int Sqlite3Wrapper::sqlite_index_scan_unique(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_INDEX_SCAN_UNIQUE;
}

int Sqlite3Wrapper::sqlite_index_scan_hex(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_INDEX_SCAN_HEX;
}

int Sqlite3Wrapper::sqlite_index_constraint_eq(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_INDEX_CONSTRAINT_EQ;
}

int Sqlite3Wrapper::sqlite_index_constraint_gt(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_INDEX_CONSTRAINT_GT;
}

int Sqlite3Wrapper::sqlite_index_constraint_le(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_INDEX_CONSTRAINT_LE;
}

int Sqlite3Wrapper::sqlite_index_constraint_lt(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_INDEX_CONSTRAINT_LT;
}

int Sqlite3Wrapper::sqlite_index_constraint_ge(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_INDEX_CONSTRAINT_GE;
}

int Sqlite3Wrapper::sqlite_index_constraint_match(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_INDEX_CONSTRAINT_MATCH;
}

int Sqlite3Wrapper::sqlite_index_constraint_like(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_INDEX_CONSTRAINT_LIKE;
}

int Sqlite3Wrapper::sqlite_index_constraint_glob(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_INDEX_CONSTRAINT_GLOB;
}

int Sqlite3Wrapper::sqlite_index_constraint_regexp(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_INDEX_CONSTRAINT_REGEXP;
}

int Sqlite3Wrapper::sqlite_index_constraint_ne(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_INDEX_CONSTRAINT_NE;
}

int Sqlite3Wrapper::sqlite_index_constraint_isnot(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_INDEX_CONSTRAINT_ISNOT;
}

int Sqlite3Wrapper::sqlite_index_constraint_isnotnull(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_INDEX_CONSTRAINT_ISNOTNULL;
}

int Sqlite3Wrapper::sqlite_index_constraint_isnull(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_INDEX_CONSTRAINT_ISNULL;
}

int Sqlite3Wrapper::sqlite_index_constraint_is(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_INDEX_CONSTRAINT_IS;
}

int Sqlite3Wrapper::sqlite_index_constraint_limit(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_INDEX_CONSTRAINT_LIMIT;
}

int Sqlite3Wrapper::sqlite_index_constraint_offset(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_INDEX_CONSTRAINT_OFFSET;
}

int Sqlite3Wrapper::sqlite_index_constraint_function(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_INDEX_CONSTRAINT_FUNCTION;
}

int Sqlite3Wrapper::create_module(const Ref<Sqlite3Handle>& db, const String& z_name, const Ref<Sqlite3ModuleHandle>& module, int64_t client_data) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    godot::CharString name_utf8 = z_name.utf8();
    sqlite3_module *module_ptr = module.is_valid() ? module->handle : nullptr;
    void *client_data_ptr = reinterpret_cast<void *>(client_data);
    return ::sqlite3_create_module(db->handle, name_utf8.get_data(), module_ptr, client_data_ptr);
}

int Sqlite3Wrapper::blob_open(const Ref<Sqlite3Handle>& db, const String& db_name, const String& table_name, const String& column_name, int64_t row, int flags, const Ref<Sqlite3BlobHandle>& out_blob) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_MISUSE);
    ERR_FAIL_COND_V(out_blob.is_null(), SQLITE_MISUSE);
    CharString db_name_utf8 = db_name.utf8();
    CharString table_name_utf8 = table_name.utf8();
    CharString column_name_utf8 = column_name.utf8();
    sqlite3_blob *blob = nullptr;
    int result = ::sqlite3_blob_open(db->handle, db_name_utf8.get_data(), table_name_utf8.get_data(), column_name_utf8.get_data(), (sqlite3_int64)row, flags, &blob);
    if (result == SQLITE_OK) {
        out_blob->set_handle(reinterpret_cast<intptr_t>(blob));
    }
    return result;
}

int Sqlite3Wrapper::vfs_register(const Ref<Sqlite3VfsHandle>& vfs, int make_dflt) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(vfs.is_null() || !vfs->is_valid(), -1);
    return ::sqlite3_vfs_register(vfs->handle, make_dflt);
}

int Sqlite3Wrapper::vfs_unregister(const Ref<Sqlite3VfsHandle>& vfs) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(vfs.is_null() || !vfs->is_valid(), -1);
    return ::sqlite3_vfs_unregister(vfs->handle);
}

void Sqlite3Wrapper::mutex_free(const Ref<Sqlite3MutexHandle>& mutex) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND(mutex.is_null() || !mutex->is_valid());
    ::sqlite3_mutex_free(mutex->handle);
    mutex->set_handle(0);
}

void Sqlite3Wrapper::mutex_enter(const Ref<Sqlite3MutexHandle>& mutex) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND(mutex.is_null() || !mutex->is_valid());
    ::sqlite3_mutex_enter(mutex->handle);
}

int Sqlite3Wrapper::mutex_try(const Ref<Sqlite3MutexHandle>& mutex) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(mutex.is_null() || !mutex->is_valid(), -1);
    return ::sqlite3_mutex_try(mutex->handle);
}

void Sqlite3Wrapper::mutex_leave(const Ref<Sqlite3MutexHandle>& mutex) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND(mutex.is_null() || !mutex->is_valid());
    ::sqlite3_mutex_leave(mutex->handle);
}

Ref<Sqlite3MutexHandle> Sqlite3Wrapper::db_mutex(const Ref<Sqlite3Handle>& db) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), Ref<Sqlite3MutexHandle>());
    sqlite3_mutex *mutex = ::sqlite3_db_mutex(db->handle);
    if (!mutex) {
        return Ref<Sqlite3MutexHandle>();
    }
    Ref<Sqlite3MutexHandle> ret;
    ret.instantiate();
    ret->set_handle(reinterpret_cast<intptr_t>(mutex));
    return ret;
}

int Sqlite3Wrapper::sqlite_testctrl_first(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TESTCTRL_FIRST;
}

int Sqlite3Wrapper::sqlite_testctrl_prng_save(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TESTCTRL_PRNG_SAVE;
}

int Sqlite3Wrapper::sqlite_testctrl_prng_restore(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TESTCTRL_PRNG_RESTORE;
}

int Sqlite3Wrapper::sqlite_testctrl_prng_reset(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TESTCTRL_PRNG_RESET;
}

int Sqlite3Wrapper::sqlite_testctrl_fk_no_action(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TESTCTRL_FK_NO_ACTION;
}

int Sqlite3Wrapper::sqlite_testctrl_bitvec_test(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TESTCTRL_BITVEC_TEST;
}

int Sqlite3Wrapper::sqlite_testctrl_fault_install(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TESTCTRL_FAULT_INSTALL;
}

int Sqlite3Wrapper::sqlite_testctrl_benign_malloc_hooks(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TESTCTRL_BENIGN_MALLOC_HOOKS;
}

int Sqlite3Wrapper::sqlite_testctrl_pending_byte(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TESTCTRL_PENDING_BYTE;
}

int Sqlite3Wrapper::sqlite_testctrl_assert(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TESTCTRL_ASSERT;
}

int Sqlite3Wrapper::sqlite_testctrl_always(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TESTCTRL_ALWAYS;
}

int Sqlite3Wrapper::sqlite_testctrl_reserve(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TESTCTRL_RESERVE;
}

int Sqlite3Wrapper::sqlite_testctrl_json_selfcheck(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TESTCTRL_JSON_SELFCHECK;
}

int Sqlite3Wrapper::sqlite_testctrl_optimizations(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TESTCTRL_OPTIMIZATIONS;
}

int Sqlite3Wrapper::sqlite_testctrl_iskeyword(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TESTCTRL_ISKEYWORD;
}

int Sqlite3Wrapper::sqlite_testctrl_getopt(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TESTCTRL_GETOPT;
}

int Sqlite3Wrapper::sqlite_testctrl_scratchmalloc(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TESTCTRL_SCRATCHMALLOC;
}

int Sqlite3Wrapper::sqlite_testctrl_internal_functions(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TESTCTRL_INTERNAL_FUNCTIONS;
}

int Sqlite3Wrapper::sqlite_testctrl_localtime_fault(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TESTCTRL_LOCALTIME_FAULT;
}

int Sqlite3Wrapper::sqlite_testctrl_explain_stmt(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TESTCTRL_EXPLAIN_STMT;
}

int Sqlite3Wrapper::sqlite_testctrl_once_reset_threshold(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TESTCTRL_ONCE_RESET_THRESHOLD;
}

int Sqlite3Wrapper::sqlite_testctrl_never_corrupt(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TESTCTRL_NEVER_CORRUPT;
}

int Sqlite3Wrapper::sqlite_testctrl_vdbe_coverage(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TESTCTRL_VDBE_COVERAGE;
}

int Sqlite3Wrapper::sqlite_testctrl_byteorder(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TESTCTRL_BYTEORDER;
}

int Sqlite3Wrapper::sqlite_testctrl_isinit(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TESTCTRL_ISINIT;
}

int Sqlite3Wrapper::sqlite_testctrl_sorter_mmap(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TESTCTRL_SORTER_MMAP;
}

int Sqlite3Wrapper::sqlite_testctrl_imposter(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TESTCTRL_IMPOSTER;
}

int Sqlite3Wrapper::sqlite_testctrl_parser_coverage(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TESTCTRL_PARSER_COVERAGE;
}

int Sqlite3Wrapper::sqlite_testctrl_result_intreal(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TESTCTRL_RESULT_INTREAL;
}

int Sqlite3Wrapper::sqlite_testctrl_prng_seed(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TESTCTRL_PRNG_SEED;
}

int Sqlite3Wrapper::sqlite_testctrl_extra_schema_checks(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TESTCTRL_EXTRA_SCHEMA_CHECKS;
}

int Sqlite3Wrapper::sqlite_testctrl_seek_count(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TESTCTRL_SEEK_COUNT;
}

int Sqlite3Wrapper::sqlite_testctrl_traceflags(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TESTCTRL_TRACEFLAGS;
}

int Sqlite3Wrapper::sqlite_testctrl_tune(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TESTCTRL_TUNE;
}

int Sqlite3Wrapper::sqlite_testctrl_logest(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TESTCTRL_LOGEST;
}

int Sqlite3Wrapper::sqlite_testctrl_uselongdouble(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TESTCTRL_USELONGDOUBLE;
}

int Sqlite3Wrapper::sqlite_testctrl_last(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TESTCTRL_LAST;
}

int Sqlite3Wrapper::keyword_count(void) { // NOLINT(readability-convert-member-functions-to-static)
    return ::sqlite3_keyword_count();
}

Dictionary Sqlite3Wrapper::keyword_name(int index) { // NOLINT(readability-convert-member-functions-to-static)
    const char *cstr = nullptr;
    int clen = 0;
    int result = ::sqlite3_keyword_name(index, &cstr, &clen);
    Dictionary dict;
    if (result == 0 && cstr != nullptr && clen > 0) {
        dict["name"] = String::utf8(cstr, clen);
        dict["length"] = clen;
    } else {
        dict["name"] = String();
        dict["length"] = 0;
    }
    dict["result"] = result;
    return dict;
}

int Sqlite3Wrapper::keyword_check(const String& word, int length) { // NOLINT(readability-convert-member-functions-to-static)
    CharString cs = word.utf8();
    int max_length = cs.length();
    if (length > max_length) {
        ERR_PRINT("Length argument exceeds UTF-8 byte length of the input string.");
        return -1;
    }
    return ::sqlite3_keyword_check(cs.get_data(), length);
}

Ref<Sqlite3StrHandle> Sqlite3Wrapper::str_new(const Ref<Sqlite3Handle>& db) { // NOLINT(readability-convert-member-functions-to-static)
    sqlite3 *c_db = db.is_valid() && db->is_valid() ? db->handle : nullptr;
    sqlite3_str *str = ::sqlite3_str_new(c_db);
    Ref<Sqlite3StrHandle> ref;
    ref.instantiate();
    ref->set_handle(reinterpret_cast<intptr_t>(str));
    return ref;
}

void Sqlite3Wrapper::str_free(const Ref<Sqlite3StrHandle>& str) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND(str.is_null() || !str->is_valid());
    ::sqlite3_str_free(str->handle);
    str->set_handle(0);
}

void Sqlite3Wrapper::str_append(const Ref<Sqlite3StrHandle>& str, const String& in, int n) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND(str.is_null() || !str->is_valid());
    CharString cs = in.utf8();
    ::sqlite3_str_append(str->handle, cs.get_data(), n);
}

void Sqlite3Wrapper::str_appendall(const Ref<Sqlite3StrHandle>& str, const String& z_in) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND(str.is_null() || !str->is_valid());
    CharString z_in_utf8 = z_in.utf8();
    ::sqlite3_str_appendall(str->handle, z_in_utf8.get_data());
}

void Sqlite3Wrapper::str_appendchar(const Ref<Sqlite3StrHandle>& str, int n, int c) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND(str.is_null() || !str->is_valid());
    ::sqlite3_str_appendchar(str->handle, n, (char)c);
}

void Sqlite3Wrapper::str_reset(const Ref<Sqlite3StrHandle>& str) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND(str.is_null() || !str->is_valid());
    ::sqlite3_str_reset(str->handle);
}

void Sqlite3Wrapper::str_truncate(const Ref<Sqlite3StrHandle>& str, int n) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND(str.is_null() || !str->is_valid());
    ::sqlite3_str_truncate(str->handle, n);
}

int Sqlite3Wrapper::str_length(const Ref<Sqlite3StrHandle>& str) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(str.is_null() || !str->is_valid(), 0);
    return ::sqlite3_str_length(str->handle);
}

String Sqlite3Wrapper::str_value(const Ref<Sqlite3StrHandle>& str) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(str.is_null() || !str->is_valid(), "");
    const char *buf = ::sqlite3_str_value(str->handle);
    return buf ? String::utf8(buf) : String();
}

Dictionary Sqlite3Wrapper::status64(int op, bool reset_highwater) { // NOLINT(readability-convert-member-functions-to-static)
    sqlite3_int64 curr = 0, hw = 0;
    int err = ::sqlite3_status64(op, &curr, &hw, reset_highwater ? 1 : 0);
    Dictionary d;
    d["error"] = err;
    d["current"] = (int)curr;
    d["highwater"] = (int)hw;
    return d;
}

int Sqlite3Wrapper::sqlite_status_memory_used(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_STATUS_MEMORY_USED;
}

int Sqlite3Wrapper::sqlite_status_pagecache_used(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_STATUS_PAGECACHE_USED;
}

int Sqlite3Wrapper::sqlite_status_pagecache_overflow(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_STATUS_PAGECACHE_OVERFLOW;
}

int Sqlite3Wrapper::sqlite_status_scratch_used(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_STATUS_SCRATCH_USED;
}

int Sqlite3Wrapper::sqlite_status_scratch_overflow(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_STATUS_SCRATCH_OVERFLOW;
}

int Sqlite3Wrapper::sqlite_status_malloc_size(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_STATUS_MALLOC_SIZE;
}

int Sqlite3Wrapper::sqlite_status_parser_stack(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_STATUS_PARSER_STACK;
}

int Sqlite3Wrapper::sqlite_status_pagecache_size(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_STATUS_PAGECACHE_SIZE;
}

int Sqlite3Wrapper::sqlite_status_scratch_size(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_STATUS_SCRATCH_SIZE;
}

int Sqlite3Wrapper::sqlite_status_malloc_count(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_STATUS_MALLOC_COUNT;
}

Dictionary Sqlite3Wrapper::db_status(const Ref<Sqlite3Handle>& db, int op, bool reset_flg) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), Dictionary());
    int cur = 0, hiwtr = 0;
    int error_code = ::sqlite3_db_status(db->handle, op, &cur, &hiwtr, reset_flg ? 1 : 0);
    Dictionary result;
    result["error_code"] = error_code;
    result["cur"] = cur;
    result["hiwtr"] = hiwtr;
    return result;
}

Dictionary Sqlite3Wrapper::db_status64(const Ref<Sqlite3Handle>& db, int op, bool reset_highwater) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), Dictionary());
    sqlite3_int64 curr = 0;
    sqlite3_int64 hw = 0;
    int result = ::sqlite3_db_status64(db->handle, op, &curr, &hw, reset_highwater ? 1 : 0);
    Dictionary d;
    d["result"] = result;
    d["current"] = (int64_t)curr;
    d["highwater"] = (int64_t)hw;
    return d;
}

int Sqlite3Wrapper::stmt_status(const Ref<Sqlite3StmtHandle>& stmt, int op, bool reset_flag) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), -1);
    return ::sqlite3_stmt_status(stmt->handle, op, reset_flag ? 1 : 0);
}

int Sqlite3Wrapper::backup_step(const Ref<Sqlite3BackupHandle>& db_backup, int n_page) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db_backup.is_null() || !db_backup->is_valid(), -1);
    int result = ::sqlite3_backup_step(db_backup->handle, n_page);
    return result;
}

int Sqlite3Wrapper::backup_finish(const Ref<Sqlite3BackupHandle>& p) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(p.is_null() || !p->is_valid(), SQLITE_MISUSE);
    return ::sqlite3_backup_finish(p->handle);
}

int Sqlite3Wrapper::backup_remaining(const Ref<Sqlite3BackupHandle>& p) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(p.is_null() || !p->is_valid(), -1);
    return ::sqlite3_backup_remaining(p->handle);
}

int Sqlite3Wrapper::strnicmp(const String& s1, const String& s2, int n) { // NOLINT(readability-convert-member-functions-to-static)
    CharString cs1 = s1.utf8();
    CharString cs2 = s2.utf8();
    return ::sqlite3_strnicmp(cs1.get_data(), cs2.get_data(), n);
}

int Sqlite3Wrapper::strglob(const String& glob, const String& str) { // NOLINT(readability-convert-member-functions-to-static)
    CharString glob_cs = glob.utf8();
    CharString str_cs = str.utf8();
    return ::sqlite3_strglob(glob_cs.get_data(), str_cs.get_data());
}

int Sqlite3Wrapper::strlike(const String& pattern, const String& input, int escape_char) { // NOLINT(readability-convert-member-functions-to-static)
    CharString glob_cs = pattern.utf8();
    CharString str_cs = input.utf8();
    return ::sqlite3_strlike(glob_cs.get_data(), str_cs.get_data(), (unsigned int)escape_char);
}

void Sqlite3Wrapper::log(int64_t i_err_code, const String& format, const Array& args) { // NOLINT(readability-convert-member-functions-to-static)
    if (format.is_empty()) {
        ERR_PRINT("sqlite3_log: format string must not be empty.");
        return;
    }
    String msg = format.format(args);
    godot::CharString cs = msg.utf8();
    ::sqlite3_log((int)i_err_code, "%s", cs.get_data());
}

int64_t Sqlite3Wrapper::wal_hook(const Ref<Sqlite3Handle>& db, Callable callback, const Variant& user_data) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), 0);

    struct WalHookCtx {
        Callable cb;
        Variant user_data;
    };

    // If callback is not valid, unregister hook
    if (!callback.is_valid()) {
        void *prev = ::sqlite3_wal_hook(db->handle, nullptr, nullptr);
        return reinterpret_cast<int64_t>(prev);
    }

    // Allocate new context
    WalHookCtx *ctx = memnew(WalHookCtx);
    ctx->cb = callback;
    ctx->user_data = user_data;

    // Define trampoline
    auto trampoline = [](void *ud, sqlite3 *c_db, const char *c_db_name, int n_pages) -> int {
        WalHookCtx *ctx = reinterpret_cast<WalHookCtx *>(ud);
        Ref<Sqlite3Handle> gd_db;
        gd_db.instantiate();
        gd_db->set_handle(reinterpret_cast<intptr_t>(c_db));
        String db_name = c_db_name ? String::utf8(c_db_name) : String();
        Array args;
        args.push_back(gd_db);
        args.push_back(db_name);
        args.push_back(n_pages);
        args.push_back(ctx->user_data);
        Variant ret = ctx->cb.callv(args);
        if (ret.get_type() != Variant::INT) {
            ERR_PRINT("wal_hook callback must return int, got: " + ret.stringify() + " (" + Variant::get_type_name(ret.get_type()) + ")");
            return 0;
        }
        return int(ret);
    };

    void *prev = ::sqlite3_wal_hook(db->handle, trampoline, ctx);
    return reinterpret_cast<int64_t>(prev);
}

int Sqlite3Wrapper::vtab_config(const Ref<Sqlite3Handle>& db, int op, const Array& args) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    int result = -1;
    switch (args.size()) {
        case 0:
            result = ::sqlite3_vtab_config(db->handle, op);
            break;
        case 1:
            if (args[0].get_type() == Variant::INT) {
                int arg0 = (int)args[0];
                result = ::sqlite3_vtab_config(db->handle, op, arg0);
            } else if (args[0].get_type() == Variant::STRING) {
                CharString cs = ((String)args[0]).utf8();
                result = ::sqlite3_vtab_config(db->handle, op, cs.get_data());
            } else {
                ERR_PRINT("vtab_config arg0 must be int or String");
                return -1;
            }
            break;
        case 2:
            if (args[0].get_type() == Variant::INT && args[1].get_type() == Variant::INT) {
                int arg0 = (int)args[0];
                int arg1 = (int)args[1];
                result = ::sqlite3_vtab_config(db->handle, op, arg0, arg1);
            } else if (args[0].get_type() == Variant::STRING && args[1].get_type() == Variant::STRING) {
                CharString cs0 = ((String)args[0]).utf8();
                CharString cs1 = ((String)args[1]).utf8();
                result = ::sqlite3_vtab_config(db->handle, op, cs0.get_data(), cs1.get_data());
            } else {
                ERR_PRINT("vtab_config args must be all int or all String for 2 args");
                return -1;
            }
            break;
        default:
            ERR_PRINT("vtab_config supports up to 2 variadic arguments");
            return -1;
    }
    return result;
}

int Sqlite3Wrapper::vtab_on_conflict(const Ref<Sqlite3Handle>& db) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    return ::sqlite3_vtab_on_conflict(db->handle);
}

int Sqlite3Wrapper::vtab_in_next(const Ref<Sqlite3ValueHandle>& p_val, const Ref<Sqlite3ValueHandle>& out_pp_out) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(p_val.is_null() || !p_val->is_valid(), SQLITE_MISUSE);
    ERR_FAIL_COND_V(out_pp_out.is_null(), SQLITE_MISUSE);
    sqlite3_value *out = nullptr;
    int result = ::sqlite3_vtab_in_next(p_val->handle, &out);
    if (out != nullptr) {
        out_pp_out->set_handle(reinterpret_cast<intptr_t>(out));
    }
    return result;
}

#ifdef SQLITE_ENABLE_STMT_SCANSTATUS
Dictionary Sqlite3Wrapper::stmt_scanstatus_int(const Ref<Sqlite3StmtHandle>& stmt, int64_t idx, int64_t scan_status_op) { // NOLINT(readability-convert-member-functions-to-static)
    Dictionary result;
    if (stmt.is_null() || !stmt->is_valid()) {
        result["error"] = -1;
        result["value"] = (int64_t)0;
        return result;
    }
    int64_t out_value = 0;
    int rc = ::sqlite3_stmt_scanstatus(stmt->handle, (int)idx, (int)scan_status_op, &out_value);
    result["error"] = rc;
    if (rc == 0) {
        result["value"] = out_value;
    } else {
        result["value"] = (int64_t)0;
    }
    return result;
}
#endif

#ifdef SQLITE_ENABLE_STMT_SCANSTATUS
Dictionary Sqlite3Wrapper::stmt_scanstatus_double(const Ref<Sqlite3StmtHandle>& stmt, int64_t idx, int64_t scan_status_op) { // NOLINT(readability-convert-member-functions-to-static)
    Dictionary result;
    if (stmt.is_null() || !stmt->is_valid()) {
        result["error"] = -1;
        result["value"] = 0.0;
        return result;
    }
    double out_value = 0.0;
    int rc = ::sqlite3_stmt_scanstatus(stmt->handle, (int)idx, (int)scan_status_op, &out_value);
    result["error"] = rc;
    if (rc == 0) {
        result["value"] = out_value;
    } else {
        result["value"] = 0.0;
    }
    return result;
}
#endif

#ifdef SQLITE_ENABLE_STMT_SCANSTATUS
Dictionary Sqlite3Wrapper::stmt_scanstatus_string(const Ref<Sqlite3StmtHandle>& stmt, int64_t idx, int64_t scan_status_op) { // NOLINT(readability-convert-member-functions-to-static)
    Dictionary result;
    if (stmt.is_null() || !stmt->is_valid()) {
        result["error"] = -1;
        result["value"] = String();
        return result;
    }
    const char *out_value = nullptr;
    int rc = ::sqlite3_stmt_scanstatus(stmt->handle, (int)idx, (int)scan_status_op, &out_value);
    result["error"] = rc;
    if (rc == 0 && out_value) {
        result["value"] = String::utf8(out_value);
    } else {
        result["value"] = String();
    }
    return result;
}
#endif

int Sqlite3Wrapper::scanstat_complex(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_SCANSTAT_COMPLEX;
}

#ifdef SQLITE_ENABLE_SNAPSHOT
int Sqlite3Wrapper::snapshot_get(const Ref<Sqlite3Handle>& db, const String& schema, const Ref<Sqlite3SnapshotHandle>& out_snapshot) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_ERROR);
    ERR_FAIL_COND_V(out_snapshot.is_null(), SQLITE_ERROR);
    sqlite3_snapshot *snap = nullptr;
    godot::CharString schema_utf8 = schema.utf8();
    int ret = ::sqlite3_snapshot_get(db->handle, schema_utf8.get_data(), &snap);
    if (ret == SQLITE_OK) {
        out_snapshot->set_handle(reinterpret_cast<intptr_t>(snap));
    }
    return ret;
}
#endif

#ifdef SQLITE_ENABLE_SNAPSHOT
void Sqlite3Wrapper::snapshot_free(const Ref<Sqlite3SnapshotHandle>& snapshot) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND(snapshot.is_null() || !snapshot->is_valid());
    ::sqlite3_snapshot_free(snapshot->handle);
    snapshot->set_handle(0);
}
#endif

#ifndef SQLITE_OMIT_DESERIALIZE
int Sqlite3Wrapper::deserialize(const Ref<Sqlite3Handle>& db, const String& schema, const PackedByteArray& p_data, int64_t sz_db, int64_t sz_buf, int64_t flags) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_MISUSE);
    ERR_FAIL_COND_V(p_data.size() == 0, SQLITE_MISUSE);
    // Only allow READONLY flag for safety.
    #ifndef SQLITE_DESERIALIZE_READONLY
    const int SQLITE_DESERIALIZE_READONLY = 0x01;
    #endif
    if ((flags & SQLITE_DESERIALIZE_READONLY) == 0) {
        ERR_PRINT("sqlite3_deserialize wrapper: Only SQLITE_DESERIALIZE_READONLY is supported for p_data buffer safety. Buffer will not remain alive after this call.");
        return SQLITE_MISUSE;
    }
    PackedByteArray mutable_data = p_data;
    CharString schema_cs = schema.is_empty() ? CharString() : schema.utf8();
    unsigned char *buffer = mutable_data.ptrw();
    int result = ::sqlite3_deserialize(
        db->handle,
        schema.is_empty() ? nullptr : schema_cs.get_data(),
        buffer,
        (sqlite3_int64)sz_db,
        (sqlite3_int64)sz_buf,
        (unsigned)flags
    );
    return result;
}
#endif

int Sqlite3Wrapper::carray_bind_v2(const Ref<Sqlite3StmtHandle>& stmt, int index, const PackedByteArray& data, int n_elements, int flags, int x_del, int p_del) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), SQLITE_MISUSE);
    ERR_FAIL_COND_V(data.is_empty(), SQLITE_MISUSE);
    (void)x_del; // Unused due to safety concerns with raw pointers from GDScript
    (void)p_del; // Unused due to safety concerns with raw pointers from GDScript
    (void)flags; // Unused for now, but could be extended in the future if needed
    (void)n_elements; // Unused since PackedByteArray already knows its size, but could be used for validation if desired
    (void)index; // Unused in this wrapper since GDScript can only pass int, but could be used for validation if desired
    //const void *data_ptr = static_cast<const void *>(data.ptr());
    //return ::sqlite3_carray_bind_v2(stmt->handle, index, const_cast<void *>(data_ptr), n_elements, flags, reinterpret_cast<void (*)(void*)>(intptr_t(x_del)), reinterpret_cast<void *>(intptr_t(p_del)));
    return SQLITE_MISUSE; // Not safe to pass raw pointers from GDScript, so this wrapper does not support x_del and p_del callbacks. Caller must ensure data remains valid for the lifetime of the statement.
}

int Sqlite3Wrapper::rtree_geometry_callback(const Ref<Sqlite3Handle>& db, const String& z_geom, Callable x_geom) { // NOLINT(readability-convert-member-functions-to-static)
    // Validate input
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_MISUSE);
    ERR_FAIL_COND_V(!x_geom.is_valid(), SQLITE_MISUSE);

    struct _RtreeGeomCtx {
        Callable callback;
    };
    _RtreeGeomCtx *ctx = memnew(_RtreeGeomCtx);
    ctx->callback = x_geom;

    auto trampoline = [](sqlite3_rtree_geometry *pGeom, int nCoord, double *aCoord, int *pRes) -> int {
        _RtreeGeomCtx *my_ctx = nullptr;
        if (pGeom && pGeom->pContext) {
            my_ctx = static_cast<_RtreeGeomCtx *>(pGeom->pContext);
        }
        Ref<Sqlite3RtreeGeometryHandle> geom_handle;
        geom_handle.instantiate();
        geom_handle->set_handle(reinterpret_cast<intptr_t>(pGeom));

        PackedFloat64Array coords;
        for (int i = 0; i < nCoord; i++) {
            coords.push_back(aCoord[i]);
        }

        int result_code = 0;
        if (my_ctx && my_ctx->callback.is_valid()) {
            Array args;
            args.push_back(geom_handle);
            args.push_back(coords);
            Variant ret = my_ctx->callback.callv(args);
            if (ret.get_type() == Variant::DICTIONARY) {
                Dictionary d = ret;
                if (d.has("result_code")) {
                    result_code = int(d["result_code"]);
                }
                if (d.has("output") && pRes) {
                    *pRes = int(d["output"]);
                }
            } else if (ret.get_type() == Variant::INT) {
                result_code = int(ret);
            } else {
                ERR_PRINT("x_geom Callable should return int or Dictionary with 'result_code' (int) and optionally 'output' (int)");
                result_code = SQLITE_ERROR;
            }
        } else {
            ERR_PRINT("R-tree geometry callback context or Callable is invalid.");
            result_code = SQLITE_ERROR;
        }
        return result_code;
    };

    CharString z_geom_utf8 = z_geom.utf8();
    int rc = ::sqlite3_rtree_geometry_callback(db->handle, z_geom_utf8.get_data(), trampoline, ctx);
    return rc;
}

int Sqlite3Wrapper::rtree_query_callback(const Ref<Sqlite3Handle>& db, const String& z_query_func, Callable x_query_func, const Variant& p_context, Callable x_destructor) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    ERR_FAIL_COND_V(!x_query_func.is_valid(), -1);

    struct _RtreeQueryCtx {
        Callable cb;
        Variant ctx;
        Callable destructor;
    };

    _RtreeQueryCtx *cb_ctx = memnew(_RtreeQueryCtx);
    cb_ctx->cb = x_query_func;
    cb_ctx->ctx = p_context;
    cb_ctx->destructor = x_destructor;

    auto trampoline = [](sqlite3_rtree_query_info *info) -> int {
        _RtreeQueryCtx *cb_ctx = (_RtreeQueryCtx *)info->pUser;
        Ref<Sqlite3RtreeQueryInfoHandle> gd_info;
        gd_info.instantiate();
        gd_info->set_handle(reinterpret_cast<intptr_t>(info));
        Array args;
        args.push_back(gd_info);
        args.push_back(cb_ctx->ctx);
        Variant ret = cb_ctx->cb.callv(args);
        if (ret.get_type() != Variant::INT) {
            ERR_PRINT("rtree_query_callback Callable must return int");
            return 0;
        }
        return int(ret);
    };

    auto destructor_trampoline = [](void *ud) {
        _RtreeQueryCtx *cb_ctx = (_RtreeQueryCtx *)ud;
        if (cb_ctx->destructor.is_valid()) {
            cb_ctx->destructor.call(cb_ctx->ctx);
        }
        memdelete(cb_ctx);
    };

    int result = ::sqlite3_rtree_query_callback(
        db->handle,
        z_query_func.utf8().get_data(),
        trampoline,
        cb_ctx,
        destructor_trampoline
    );
    return result;
}

int Sqlite3Wrapper::not_within(void) { // NOLINT(readability-convert-member-functions-to-static)
    return NOT_WITHIN;
}

int Sqlite3Wrapper::partly_within(void) { // NOLINT(readability-convert-member-functions-to-static)
    return PARTLY_WITHIN;
}

int Sqlite3Wrapper::fully_within(void) { // NOLINT(readability-convert-member-functions-to-static)
    return FULLY_WITHIN;
}

int Sqlite3Wrapper::session_create(const Ref<Sqlite3Handle>& db, const String& z_db, const Ref<Sqlite3SessionHandle>& out_session) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    ERR_FAIL_COND_V(out_session.is_null(), -1);
    sqlite3_session *session = nullptr;
    CharString z_db_utf8 = z_db.utf8();
    int ret = ::sqlite3session_create(db->handle, z_db_utf8.get_data(), &session);
    if (ret == SQLITE_OK) {
        out_session->set_handle(reinterpret_cast<intptr_t>(session));
    }
    return ret;
}

int Sqlite3Wrapper::session_enable(const Ref<Sqlite3SessionHandle>& session, int enable) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(session.is_null() || !session->is_valid(), -1);
    return ::sqlite3session_enable(session->handle, enable);
}

int64_t Sqlite3Wrapper::session_memory_used(const Ref<Sqlite3SessionHandle>& p_session) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(p_session.is_null() || !p_session->is_valid(), 0);
    return ::sqlite3session_memory_used(p_session->handle);
}

int Sqlite3Wrapper::changeset_start_v2(const PackedByteArray& changeset, int64_t flags, const Ref<Sqlite3ChangesetIterHandle>& out_iter) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(out_iter.is_null(), SQLITE_MISUSE);
    int nChangeset = changeset.size();
    void *pChangeset = (void *)changeset.ptr();
    sqlite3_changeset_iter *iter = nullptr;
    int rc = ::sqlite3changeset_start_v2(&iter, nChangeset, pChangeset, (int)flags);
    if (rc == SQLITE_OK && iter) {
        out_iter->set_handle(reinterpret_cast<intptr_t>(iter));
    }
    return rc;
}

int Sqlite3Wrapper::next(const Ref<Sqlite3ChangesetIterHandle>& p_iter) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(p_iter.is_null() || !p_iter->is_valid(), SQLITE_MISUSE);
    return ::sqlite3changeset_next(p_iter->handle);
}

Dictionary Sqlite3Wrapper::changeset_concat(const PackedByteArray& a, const PackedByteArray& b) { // NOLINT(readability-convert-member-functions-to-static)
    Dictionary result;
    int nOut = 0;
    void *pOut = nullptr;
    int rc = ::sqlite3changeset_concat(a.size(), (void *)a.ptr(), b.size(), (void *)b.ptr(), &nOut, &pOut);
    PackedByteArray out;
    if (rc == SQLITE_OK && nOut > 0 && pOut != nullptr) {
        out.resize(nOut);
        memcpy(out.ptrw(), pOut, nOut);
        ::sqlite3_free(pOut);
    }
    result["error"] = rc;
    result["changeset"] = out;
    return result;
}

Ref<Sqlite3ChangegroupHandle> Sqlite3Wrapper::create(void) { // NOLINT(readability-convert-member-functions-to-static)
    sqlite3_changegroup *ptr = nullptr;
    int result = ::sqlite3changegroup_new(&ptr);
    if (result == SQLITE_OK && ptr != nullptr) {
        Ref<Sqlite3ChangegroupHandle> ref;
        ref.instantiate();
        ref->set_handle(reinterpret_cast<intptr_t>(ptr));
        return ref;
    }
    return Ref<Sqlite3ChangegroupHandle>();
}

void Sqlite3Wrapper::changegroup_delete(const Ref<Sqlite3ChangegroupHandle>& changegroup) { // NOLINT(readability-convert-member-functions-to-static)
    if (changegroup.is_null() || !changegroup->is_valid()) {
        return;
    }
    sqlite3changegroup_delete(changegroup->handle);
    changegroup->set_handle(0);
}

int Sqlite3Wrapper::rebaser_create(const Ref<Sqlite3RebaserHandle>& out_handle) { // NOLINT(readability-convert-member-functions-to-static)
    sqlite3_rebaser *handle = nullptr;
    int result = ::sqlite3rebaser_create(&handle);
    if (result == SQLITE_OK && out_handle.is_valid()) {
        out_handle->set_handle(reinterpret_cast<intptr_t>(handle));
    }
    return result;
}

int Sqlite3Wrapper::configure(const Ref<Sqlite3RebaserHandle>& rebaser, const PackedByteArray& rebase_buffer) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(rebaser.is_null() || !rebaser->is_valid(), -1);
    const int nRebase = rebase_buffer.size();
    const void *pRebase = nRebase > 0 ? rebase_buffer.ptr() : nullptr;
    return ::sqlite3rebaser_configure(rebaser->handle, nRebase, pRebase);
}

void Sqlite3Wrapper::rebaser_delete(const Ref<Sqlite3RebaserHandle>& p_rebaser) { // NOLINT(readability-convert-member-functions-to-static)
    if (p_rebaser.is_null() || !p_rebaser->is_valid()) {
        ERR_PRINT("Attempted to delete an invalid or null sqlite3_rebaser handle.");
        return;
    }
    ::sqlite3rebaser_delete(reinterpret_cast<sqlite3_rebaser*>(p_rebaser->get_handle()));
    p_rebaser->set_handle(0);
}

int Sqlite3Wrapper::changeset_concat_strm(Callable x_input_a, const Variant& in_a, Callable x_input_b, const Variant& in_b, Callable x_output, const Variant& out) { // NOLINT(readability-convert-member-functions-to-static)
    // Context structs for callbacks
    struct _InputCtx {
        Callable cb;
        Variant ctx;
    };
    struct _OutputCtx {
        Callable cb;
        Variant ctx;
    };

    _InputCtx ctx_a { x_input_a, in_a };
    _InputCtx ctx_b { x_input_b, in_b };
    _OutputCtx ctx_out { x_output, out };

    // Input trampoline
    static auto xinput_trampoline = [](void *pIn, void *pData, int *pnData) -> int {
        _InputCtx *ctx = reinterpret_cast<_InputCtx *>(pIn);
        int size = *pnData;
        PackedByteArray arr;
        arr.resize(size);
        if (size > 0 && pData) {
            memcpy(arr.ptrw(), pData, size);
        }
        Array args;
        args.push_back(arr);
        args.push_back(ctx->ctx);
        Variant ret = ctx->cb.callv(args);
        if (ret.get_type() != Variant::DICTIONARY) {
            ERR_PRINT("xInput callback must return a Dictionary with 'data' (PackedByteArray) and 'size' (int)");
            return -1;
        }
        Dictionary dict = ret;
        if (!dict.has("data") || !dict.has("size")) {
            ERR_PRINT("xInput callback Dictionary missing 'data' or 'size'");
            return -1;
        }
        PackedByteArray ret_arr = dict["data"];
        int new_size = int(dict["size"]);
        if (new_size > 0 && pData) {
            int cp_size = MIN(new_size, ret_arr.size());
            memcpy(pData, ret_arr.ptr(), cp_size);
            *pnData = cp_size;
        } else {
            *pnData = 0;
        }
        if (dict.has("result")) {
            return int(dict["result"]);
        }
        return 0;
    };

    // Output trampoline
    static auto xoutput_trampoline = [](void *pOut, const void *pData, int nData) -> int {
        _OutputCtx *ctx = reinterpret_cast<_OutputCtx *>(pOut);
        PackedByteArray arr;
        if (nData > 0 && pData) {
            arr.resize(nData);
            memcpy(arr.ptrw(), pData, nData);
        }
        Array args;
        args.push_back(arr);
        args.push_back(ctx->ctx);
        Variant ret = ctx->cb.callv(args);
        if (ret.get_type() != Variant::INT) {
            ERR_PRINT("xOutput callback must return int");
            return -1;
        }
        return int(ret);
    };

    return ::sqlite3changeset_concat_strm(
        xinput_trampoline, &ctx_a,
        xinput_trampoline, &ctx_b,
        xoutput_trampoline, &ctx_out
    );
}

int Sqlite3Wrapper::changeset_start_v2_strm(const Ref<Sqlite3ChangesetIterHandle>& out_iter, Callable x_input, int flags) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(out_iter.is_null(), SQLITE_MISUSE);
    ERR_FAIL_COND_V(!x_input.is_valid(), SQLITE_MISUSE);

    struct _InputCtx {
        Callable cb;
    } ctx { x_input };

    auto trampoline = [](void *pIn, void *pData, int *pnData) -> int {
        _InputCtx *ctx = reinterpret_cast<_InputCtx *>(pIn);
        int buf_size = 0;
        if (pnData) buf_size = *pnData;
        Array args;
        args.push_back(buf_size);
        Variant ret = ctx->cb.callv(args);
        PackedByteArray out_data;
        int result_code = 0;
        if (ret.get_type() == Variant::PACKED_BYTE_ARRAY) {
            out_data = ret;
        } else if (ret.get_type() == Variant::ARRAY) {
            Array retarr = ret;
            if (retarr.size() >= 2 && retarr[0].get_type() == Variant::PACKED_BYTE_ARRAY && retarr[1].get_type() == Variant::INT) {
                out_data = retarr[0];
                result_code = int(retarr[1]);
            }
        } else {
            ERR_PRINT("x_input callback must return PackedByteArray or [PackedByteArray, int].");
            return SQLITE_MISUSE;
        }
        int copy_bytes = MIN(buf_size, out_data.size());
        if (pData && copy_bytes > 0) {
            memcpy(pData, out_data.ptr(), copy_bytes);
        }
        if (pnData) *pnData = copy_bytes;
        return result_code;
    };

    sqlite3_changeset_iter *iter = nullptr;
    int result = ::sqlite3changeset_start_v2_strm(&iter, trampoline, &ctx, flags);
    if (result == SQLITE_OK && iter) {
        out_iter->set_handle(reinterpret_cast<intptr_t>(iter));
    }
    return result;
}

int Sqlite3Wrapper::changeset_strm(const Ref<Sqlite3SessionHandle>& session, Callable x_output) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(session.is_null() || !session->is_valid(), -1);
    ERR_FAIL_COND_V(!x_output.is_valid(), -1);

    struct _ChangesetStreamCtx {
        Callable cb;
    } ctx { x_output };

    auto trampoline = [](void *pOut, const void *pData, int nData) -> int {
        _ChangesetStreamCtx *ctx = reinterpret_cast<_ChangesetStreamCtx *>(pOut);
        PackedByteArray data;
        if (pData && nData > 0) {
            data.resize(nData);
            memcpy(data.ptrw(), pData, nData);
        }
        Array args;
        args.push_back(data);
        Variant ret = ctx->cb.callv(args);
        if (ret.get_type() != Variant::INT) {
            ERR_PRINT("x_output must return int, but got: " + ret.stringify() + " (" + Variant::get_type_name(ret.get_type()) + ")");
            return -1;
        }
        return int(ret);
    };

    return ::sqlite3session_changeset_strm(session->handle, trampoline, &ctx);
}

int Sqlite3Wrapper::patchset_strm(const Ref<Sqlite3SessionHandle>& session, Callable x_output, const Variant& p_out) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(session.is_null() || !session->is_valid(), -1);
    ERR_FAIL_COND_V(!x_output.is_valid(), -1);

    struct _OutputCtx {
        Callable cb;
        Variant user_data;
    } ctx{x_output, p_out};

    auto trampoline = [](void *ud, const void *pData, int nData) -> int {
        _OutputCtx *ctx = reinterpret_cast<_OutputCtx *>(ud);
        PackedByteArray gd_data;
        if (pData && nData > 0) {
            gd_data.resize(nData);
            memcpy(gd_data.ptrw(), pData, nData);
        }
        Array args;
        args.push_back(ctx->user_data);
        args.push_back(gd_data);
        Variant ret = ctx->cb.callv(args);
        if (ret.get_type() != Variant::INT) {
            ERR_PRINT("x_output must return int, but got: " + ret.stringify() + " (" + Variant::get_type_name(ret.get_type()) + ")");
            return -1;
        }
        return int(ret);
    };

    return ::sqlite3session_patchset_strm(session->handle, trampoline, &ctx);
}

int Sqlite3Wrapper::changegroup_add_strm(const Ref<Sqlite3ChangegroupHandle>& changegroup, Callable x_input) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(changegroup.is_null() || !changegroup->is_valid(), -1);
    ERR_FAIL_COND_V(!x_input.is_valid(), -1);

    struct _InputCtx {
        Callable cb;
    } ctx{x_input};

    auto trampoline = [](void *pIn, void *pData, int *pnData) -> int {
        _InputCtx *ctx = reinterpret_cast<_InputCtx *>(pIn);
        int buf_size = pnData ? *pnData : 0;
        Array args;
        args.push_back(buf_size);
        Variant ret = ctx->cb.callv(args);
        if (ret.get_type() != Variant::PACKED_BYTE_ARRAY) {
            ERR_PRINT("x_input must return PackedByteArray, got: " + ret.stringify() + " (" + Variant::get_type_name(ret.get_type()) + ")");
            if (pnData) *pnData = 0;
            return -1;
        }
        PackedByteArray arr = ret;
        int to_copy = buf_size < arr.size() ? buf_size : arr.size();
        if (to_copy > 0 && pData) {
            memcpy(pData, arr.ptr(), to_copy);
        }
        if (pnData) *pnData = to_copy;
        return 0;
    };

    return ::sqlite3changegroup_add_strm(changegroup->handle, trampoline, &ctx);
}

int Sqlite3Wrapper::session_config_strmsize(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_SESSION_CONFIG_STRMSIZE;
}

int Sqlite3Wrapper::close_v2(const Ref<Sqlite3Handle>& db) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    int result = ::sqlite3_close_v2(db->handle);
    db->handle = nullptr;
    return result;
}

Dictionary Sqlite3Wrapper::exec(const Ref<Sqlite3Handle>& db, const String& sql, Callable callback) { // NOLINT(readability-convert-member-functions-to-static)
    Dictionary result;
    result["code"] = SQLITE_MISUSE;
    result["error_message"] = String();
    if (db.is_null() || !db->is_valid()) {
        result["error_message"] = "Invalid or null SQLite database handle.";
        return result;
    }
    if (sql.is_empty()) {
        result["error_message"] = "SQL string is empty.";
        return result;
    }

    struct _ExecCtx {
        Callable cb;
    } ctx{callback};

    int (*cb_ptr)(void*, int, char**, char**) = nullptr;
    void *cb_ctx = nullptr;
    if (callback.is_valid()) {
        cb_ptr = [](void *ud, int ncols, char **colv, char **colnames) -> int {
            _ExecCtx *ctx = reinterpret_cast<_ExecCtx *>(ud);
            PackedStringArray gd_colv;
            PackedStringArray gd_colnames;
            for (int i = 0; i < ncols; i++) {
                gd_colv.push_back(colv[i] ? String::utf8(colv[i]) : String());
                gd_colnames.push_back(colnames[i] ? String::utf8(colnames[i]) : String());
            }
            Array args;
            args.push_back(gd_colv);
            args.push_back(gd_colnames);
            Variant ret = ctx->cb.callv(args);
            if (ret.get_type() != Variant::INT) {
                ERR_PRINT("sqlite3_exec callback must return int.");
                return -1;
            }
            return int(ret);
        };
        cb_ctx = &ctx;
    }

    CharString sql_utf8 = sql.utf8();
    char *errmsg = nullptr;
    int rc = ::sqlite3_exec(db->handle, sql_utf8.get_data(), cb_ptr, cb_ctx, &errmsg);
    result["code"] = rc;
    if (errmsg != nullptr) {
        result["error_message"] = String::utf8(errmsg);
        ::sqlite3_free(errmsg);
    }
    return result;
}

int64_t Sqlite3Wrapper::last_insert_rowid(const Ref<Sqlite3Handle>& db) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), 0);
    return ::sqlite3_last_insert_rowid(db->handle);
}

void Sqlite3Wrapper::set_last_insert_rowid(const Ref<Sqlite3Handle>& db, int64_t rowid) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND(db.is_null() || !db->is_valid());
    ::sqlite3_set_last_insert_rowid(db->handle, rowid);
}

int Sqlite3Wrapper::changes(const Ref<Sqlite3Handle>& db) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    return ::sqlite3_changes(db->handle);
}

int Sqlite3Wrapper::total_changes(const Ref<Sqlite3Handle>& db) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    return ::sqlite3_total_changes(db->handle);
}

int Sqlite3Wrapper::complete(const String& sql) { // NOLINT(readability-convert-member-functions-to-static)
    CharString cs = sql.utf8();
    return ::sqlite3_complete(cs.get_data());
}

#ifdef SQLITE_ENABLE_SETLK_TIMEOUT
int Sqlite3Wrapper::setlk_timeout(const Ref<Sqlite3Handle>& db, int ms, int flags) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    return ::sqlite3_setlk_timeout(db->handle, ms, flags);
}
#endif

int Sqlite3Wrapper::setlk_block_on_connect(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_SETLK_BLOCK_ON_CONNECT;
}

Dictionary Sqlite3Wrapper::get_table(const Ref<Sqlite3Handle>& db, const String& sql) { // NOLINT(readability-convert-member-functions-to-static)
    // Validate input
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), Dictionary());

    Dictionary result_dict;
    char **c_result = nullptr;
    int nrow = 0;
    int ncol = 0;
    char *c_errmsg = nullptr;

    // Keep CharString alive for the duration of the call
    CharString sql_cs = sql.utf8();
    int code = ::sqlite3_get_table(db->handle, sql_cs.get_data(), &c_result, &nrow, &ncol, &c_errmsg);

    PackedStringArray result_arr;
    if (c_result) {
        int total = (nrow + 1) * ncol;
        for (int i = 0; i < total; ++i) {
            if (c_result[i]) {
                result_arr.push_back(String::utf8(c_result[i]));
            } else {
                result_arr.push_back("");
            }
        }
        // Free the table with sqlite3_free_table
        ::sqlite3_free_table(c_result);
    }

    String errmsg;
    if (c_errmsg) {
        errmsg = String::utf8(c_errmsg);
        ::sqlite3_free(c_errmsg);
    }

    result_dict["result"] = result_arr;
    result_dict["row_count"] = nrow;
    result_dict["column_count"] = ncol;
    result_dict["error"] = errmsg;
    result_dict["code"] = code;
    return result_dict;
}

int Sqlite3Wrapper::sqlite_deny(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DENY;
}

int Sqlite3Wrapper::sqlite_ignore(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_IGNORE;
}

int Sqlite3Wrapper::sqlite_create_index(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CREATE_INDEX;
}

int Sqlite3Wrapper::sqlite_create_table(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CREATE_TABLE;
}

int Sqlite3Wrapper::sqlite_create_temp_index(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CREATE_TEMP_INDEX;
}

int Sqlite3Wrapper::sqlite_create_temp_table(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CREATE_TEMP_TABLE;
}

int Sqlite3Wrapper::sqlite_create_temp_trigger(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CREATE_TEMP_TRIGGER;
}

int Sqlite3Wrapper::sqlite_create_temp_view(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CREATE_TEMP_VIEW;
}

int Sqlite3Wrapper::sqlite_create_trigger(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CREATE_TRIGGER;
}

int Sqlite3Wrapper::sqlite_create_view(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CREATE_VIEW;
}

int Sqlite3Wrapper::sqlite_delete(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DELETE;
}

int Sqlite3Wrapper::sqlite_drop_index(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DROP_INDEX;
}

int Sqlite3Wrapper::sqlite_drop_table(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DROP_TABLE;
}

int Sqlite3Wrapper::sqlite_drop_temp_index(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DROP_TEMP_INDEX;
}

int Sqlite3Wrapper::sqlite_drop_temp_table(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DROP_TEMP_TABLE;
}

int Sqlite3Wrapper::sqlite_drop_temp_trigger(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DROP_TEMP_TRIGGER;
}

int Sqlite3Wrapper::sqlite_drop_temp_view(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DROP_TEMP_VIEW;
}

int Sqlite3Wrapper::sqlite_drop_trigger(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DROP_TRIGGER;
}

int Sqlite3Wrapper::sqlite_drop_view(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DROP_VIEW;
}

int Sqlite3Wrapper::sqlite_insert(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_INSERT;
}

int Sqlite3Wrapper::sqlite_pragma(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_PRAGMA;
}

int Sqlite3Wrapper::sqlite_read(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_READ;
}

int Sqlite3Wrapper::sqlite_select(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_SELECT;
}

int Sqlite3Wrapper::sqlite_transaction(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TRANSACTION;
}

int Sqlite3Wrapper::sqlite_update(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_UPDATE;
}

int Sqlite3Wrapper::sqlite_attach(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_ATTACH;
}

int Sqlite3Wrapper::sqlite_detach(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DETACH;
}

int Sqlite3Wrapper::sqlite_alter_table(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_ALTER_TABLE;
}

int Sqlite3Wrapper::sqlite_reindex(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_REINDEX;
}

int Sqlite3Wrapper::sqlite_analyze(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_ANALYZE;
}

int Sqlite3Wrapper::sqlite_create_vtable(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CREATE_VTABLE;
}

int Sqlite3Wrapper::sqlite_drop_vtable(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DROP_VTABLE;
}

int Sqlite3Wrapper::sqlite_function(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FUNCTION;
}

int Sqlite3Wrapper::sqlite_savepoint(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_SAVEPOINT;
}

int Sqlite3Wrapper::sqlite_copy(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_COPY;
}

int Sqlite3Wrapper::sqlite_recursive(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_RECURSIVE;
}

int64_t Sqlite3Wrapper::profile(const Ref<Sqlite3Handle>& db, Callable x_profile) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), 0);
    ERR_FAIL_COND_V(!x_profile.is_valid(), 0);

    struct _ProfileCtx {
        Callable cb;
    };
    _ProfileCtx *ctx = memnew(_ProfileCtx);
    ctx->cb = x_profile;

    auto trampoline = [](void *ud, const char *sql, sqlite3_uint64 elapsed_ns) {
        _ProfileCtx *ctx = static_cast<_ProfileCtx *>(ud);
        String gd_sql = sql ? String::utf8(sql) : String();
        int64_t gd_elapsed = (int64_t)elapsed_ns;
        Array args;
        args.push_back(gd_sql);
        args.push_back(gd_elapsed);
        ctx->cb.callv(args);
    };

    void *prev = ::sqlite3_profile(db->handle, trampoline, ctx);
    return reinterpret_cast<int64_t>(prev);
}

int Sqlite3Wrapper::trace_stmt(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TRACE_STMT;
}

int Sqlite3Wrapper::trace_profile(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TRACE_PROFILE;
}

int Sqlite3Wrapper::trace_row(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TRACE_ROW;
}

int Sqlite3Wrapper::trace_close(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TRACE_CLOSE;
}

void Sqlite3Wrapper::progress_handler_disable(const Ref<Sqlite3Handle>& db, int n_instructions) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND(db.is_null() || !db->is_valid());
    ::sqlite3_progress_handler(db->handle, n_instructions, nullptr, nullptr);
}

int Sqlite3Wrapper::open(const String& filename, const Ref<Sqlite3Handle>& out_db) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(out_db.is_null(), SQLITE_NOMEM);
    CharString cs = filename.utf8();
    sqlite3 *db = nullptr;
    int result = ::sqlite3_open(cs.get_data(), &db);
    if (db != nullptr) {
        out_db->set_handle(reinterpret_cast<intptr_t>(db));
    }
    return result;
}

int Sqlite3Wrapper::open16(const String& filename, const Ref<Sqlite3Handle>& out_db) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(out_db.is_null(), SQLITE_MISUSE);
    Char16String c16 = filename.utf16();
    const void *ptr = c16.ptr();
    sqlite3 *db = nullptr;
    int result = ::sqlite3_open16(ptr, &db);
    if (result == SQLITE_OK && db != nullptr) {
        out_db->set_handle(reinterpret_cast<intptr_t>(db));
    }
    return result;
}

int Sqlite3Wrapper::open_v2(const String& filename, const Ref<Sqlite3Handle>& out_db, int flags, const String& z_vfs) { // NOLINT(readability-convert-member-functions-to-static)
    sqlite3 *handle = nullptr;
    godot::CharString filename_cs = filename.utf8();
    const char *filename_c = filename_cs.get_data();
    const char *z_vfs_c = nullptr;
    godot::CharString z_vfs_cs;
    if (!z_vfs.is_empty()) {
        z_vfs_cs = z_vfs.utf8();
        z_vfs_c = z_vfs_cs.get_data();
    }
    int result = ::sqlite3_open_v2(filename_c, &handle, flags, z_vfs_c);
    if (result == 0 && handle != nullptr) {
        out_db->set_handle(reinterpret_cast<intptr_t>(handle));
    }
    return result;
}

String Sqlite3Wrapper::errmsg16(const Ref<Sqlite3Handle>& db) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), String());
    const void *msg_ptr = ::sqlite3_errmsg16(db->handle);
    if (!msg_ptr) {
        return String();
    }
    const char16_t *msg16 = reinterpret_cast<const char16_t *>(msg_ptr);
    size_t len = 0;
    while (msg16[len] != 0) {
        len++;
    }
    return String::utf16(msg16, len);
}

int Sqlite3Wrapper::error_offset(const Ref<Sqlite3Handle>& db) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    return ::sqlite3_error_offset(db->handle);
}

int Sqlite3Wrapper::set_errmsg(const Ref<Sqlite3Handle>& db, int errcode, const String& z_err_msg) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_MISUSE);
    const char *err_msg_ptr = nullptr;
    CharString msg_utf8;
    if (!z_err_msg.is_empty()) {
        msg_utf8 = z_err_msg.utf8();
        err_msg_ptr = msg_utf8.get_data();
    }
    return ::sqlite3_set_errmsg(db->handle, errcode, err_msg_ptr);
}

int Sqlite3Wrapper::limit_length(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_LIMIT_LENGTH;
}

int Sqlite3Wrapper::limit_sql_length(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_LIMIT_SQL_LENGTH;
}

int Sqlite3Wrapper::limit_column(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_LIMIT_COLUMN;
}

int Sqlite3Wrapper::limit_expr_depth(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_LIMIT_EXPR_DEPTH;
}

int Sqlite3Wrapper::limit_compound_select(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_LIMIT_COMPOUND_SELECT;
}

int Sqlite3Wrapper::limit_vdbe_op(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_LIMIT_VDBE_OP;
}

int Sqlite3Wrapper::limit_function_arg(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_LIMIT_FUNCTION_ARG;
}

int Sqlite3Wrapper::limit_attached(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_LIMIT_ATTACHED;
}

int Sqlite3Wrapper::limit_like_pattern_length(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_LIMIT_LIKE_PATTERN_LENGTH;
}

int Sqlite3Wrapper::limit_variable_number(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_LIMIT_VARIABLE_NUMBER;
}

int Sqlite3Wrapper::limit_trigger_depth(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_LIMIT_TRIGGER_DEPTH;
}

int Sqlite3Wrapper::limit_worker_threads(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_LIMIT_WORKER_THREADS;
}

int Sqlite3Wrapper::limit_parser_depth(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_LIMIT_PARSER_DEPTH;
}

int Sqlite3Wrapper::prepare_persistent(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_PREPARE_PERSISTENT;
}

int Sqlite3Wrapper::prepare_normalize(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_PREPARE_NORMALIZE;
}

int Sqlite3Wrapper::prepare_no_vtab(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_PREPARE_NO_VTAB;
}

int Sqlite3Wrapper::prepare_dont_log(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_PREPARE_DONT_LOG;
}

int Sqlite3Wrapper::prepare_from_ddl(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_PREPARE_FROM_DDL;
}

int Sqlite3Wrapper::prepare(const Ref<Sqlite3Handle>& db, const String& sql, int n_byte, const Ref<Sqlite3StmtHandle>& out_stmt) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_MISUSE);
    ERR_FAIL_COND_V(out_stmt.is_null(), SQLITE_MISUSE);

    CharString sql_utf8 = sql.utf8();
    const char *zSql = sql_utf8.get_data();
    sqlite3_stmt *stmt = nullptr;
    int rc = ::sqlite3_prepare(db->handle, zSql, n_byte, &stmt, nullptr);
    if (rc == SQLITE_OK && stmt != nullptr) {
        out_stmt->set_handle(reinterpret_cast<intptr_t>(stmt));
    }
    return rc;
}

Dictionary Sqlite3Wrapper::prepare_v2(const Ref<Sqlite3Handle>& db, const String& sql, int64_t n_byte) { // NOLINT(readability-convert-member-functions-to-static)
    Dictionary result;
    if (db.is_null() || !db->is_valid()) {
        result["error_code"] = SQLITE_MISUSE;
        result["statement"] = Variant();
        result["tail"] = String();
        return result;
    }

    CharString sql_utf8 = sql.utf8();
    const char *zSql = sql_utf8.get_data();

    sqlite3_stmt *stmt = nullptr;
    const char *tail = nullptr;
    int rc = ::sqlite3_prepare_v2(db->handle, zSql, static_cast<int>(n_byte), &stmt, &tail);

    Ref<Sqlite3StmtHandle> stmt_ref;
    if (rc == SQLITE_OK && stmt) {
        stmt_ref.instantiate();
        stmt_ref->set_handle(reinterpret_cast<intptr_t>(stmt));
        result["statement"] = stmt_ref;
    } else {
        result["statement"] = Variant();
    }

    if (tail && zSql) {
        ptrdiff_t offset = tail - zSql;
        if (offset >= 0 && offset <= sql_utf8.length()) {
            result["tail"] = String::utf8(zSql + offset);
        } else {
            result["tail"] = String();
        }
    } else {
        result["tail"] = String();
    }

    result["error_code"] = rc;
    return result;
}

int Sqlite3Wrapper::prepare_v3(const Ref<Sqlite3Handle>& db, const String& sql, int64_t n_byte, int64_t prep_flags, const Ref<Sqlite3StmtHandle>& out_stmt) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_MISUSE);
    ERR_FAIL_COND_V(out_stmt.is_null(), SQLITE_MISUSE);

    sqlite3_stmt *stmt = nullptr;
    godot::CharString cs_sql = sql.utf8();
    int result = ::sqlite3_prepare_v3(db->handle, cs_sql.get_data(), static_cast<int>(n_byte), static_cast<unsigned int>(prep_flags), &stmt, nullptr);
    if (result == SQLITE_OK && stmt != nullptr) {
        out_stmt->set_handle(reinterpret_cast<intptr_t>(stmt));
    }
    return result;
}

int Sqlite3Wrapper::prepare16(const Ref<Sqlite3Handle>& db, const PackedByteArray& z_sql, int n_byte, const Ref<Sqlite3StmtHandle>& out_stmt) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_MISUSE);
    ERR_FAIL_COND_V(z_sql.is_empty(), SQLITE_MISUSE);
    ERR_FAIL_COND_V(out_stmt.is_null(), SQLITE_MISUSE);

    sqlite3_stmt *stmt = nullptr;
    int result = ::sqlite3_prepare16(
        db->handle,
        z_sql.ptr(),
        n_byte,
        &stmt,
        nullptr
    );
    if (result == SQLITE_OK && stmt) {
        out_stmt->set_handle(reinterpret_cast<intptr_t>(stmt));
    }
    return result;
}

int Sqlite3Wrapper::prepare16_v2(const Ref<Sqlite3Handle>& db, const PackedByteArray& sql_utf16, int64_t n_byte, const Ref<Sqlite3StmtHandle>& out_stmt) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_MISUSE);
    ERR_FAIL_COND_V(out_stmt.is_null(), SQLITE_MISUSE);
    ERR_FAIL_COND_V(sql_utf16.is_empty(), SQLITE_MISUSE);

    const void *zSql = sql_utf16.ptr();
    int nByte = (int)n_byte;
    if (nByte < 0 || nByte > sql_utf16.size()) {
        nByte = sql_utf16.size();
    }

    sqlite3_stmt *stmt = nullptr;
    int rc = ::sqlite3_prepare16_v2(db->handle, zSql, nByte, &stmt, nullptr);
    if (rc == SQLITE_OK && stmt) {
        out_stmt->set_handle(reinterpret_cast<intptr_t>(stmt));
    }
    return rc;
}

Dictionary Sqlite3Wrapper::prepare16_v3(const Ref<Sqlite3Handle>& db, const String& sql, int n_byte, int prep_flags) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), Dictionary());
    Char16String utf16_sql = sql.utf16();
    const void *zSql = utf16_sql.ptr();
    int byte_count = n_byte;
    if (byte_count < 0) {
        byte_count = -1;
    } else {
        int max_bytes = utf16_sql.length() * 2;
        if (byte_count > max_bytes) byte_count = max_bytes;
    }
    sqlite3_stmt *stmt = nullptr;
    const void *pzTail = nullptr;
    int rc = ::sqlite3_prepare16_v3(db->handle, zSql, byte_count, (unsigned int)prep_flags, &stmt, &pzTail);
    Ref<Sqlite3StmtHandle> out_stmt;
    if (stmt) {
        out_stmt.instantiate();
        out_stmt->set_handle(reinterpret_cast<intptr_t>(stmt));
    }
    int tail_offset = 0;
    if (pzTail && zSql) {
        tail_offset = static_cast<const uint8_t*>(pzTail) - static_cast<const uint8_t*>(zSql);
    }
    Dictionary result;
    result["result"] = rc;
    result["stmt"] = out_stmt;
    result["tail_offset"] = tail_offset;
    return result;
}

String Sqlite3Wrapper::sql(const Ref<Sqlite3StmtHandle>& stmt) { // NOLINT(readability-convert-member-functions-to-static)
    if (stmt.is_null() || !stmt->is_valid()) {
        return String();
    }
    const char *ptr = ::sqlite3_sql(stmt->handle);
    if (!ptr) {
        return String();
    }
    return String::utf8(ptr);
}

#ifdef SQLITE_ENABLE_NORMALIZE
String Sqlite3Wrapper::normalized_sql(const Ref<Sqlite3StmtHandle>& p_stmt) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(p_stmt.is_null() || !p_stmt->is_valid(), String());
    const char *result = ::sqlite3_normalized_sql(p_stmt->handle);
    return result ? String::utf8(result) : String();
}
#endif

int Sqlite3Wrapper::stmt_readonly(const Ref<Sqlite3StmtHandle>& stmt) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), 0);
    return ::sqlite3_stmt_readonly(stmt->handle);
}

int Sqlite3Wrapper::stmt_isexplain(const Ref<Sqlite3StmtHandle>& p_stmt) { // NOLINT(readability-convert-member-functions-to-static)
    if (p_stmt.is_null() || !p_stmt->is_valid()) {
        return 0;
    }
    return ::sqlite3_stmt_isexplain(p_stmt->handle);
}

int Sqlite3Wrapper::stmt_explain(const Ref<Sqlite3StmtHandle>& stmt, int e_mode) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), -1);
    return ::sqlite3_stmt_explain(stmt->handle, e_mode);
}

int Sqlite3Wrapper::stmt_busy(const Ref<Sqlite3StmtHandle>& stmt) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), 0);
    int ret = ::sqlite3_stmt_busy(stmt->handle);
    return ret;
}

int Sqlite3Wrapper::bind_double(const Ref<Sqlite3StmtHandle>& stmt, int index, double value) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), SQLITE_MISUSE);
    return ::sqlite3_bind_double(stmt->handle, index, value);
}

int Sqlite3Wrapper::bind_int(const Ref<Sqlite3StmtHandle>& stmt, int index, int value) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), -1);
    return ::sqlite3_bind_int(stmt->handle, index, value);
}

int Sqlite3Wrapper::bind_null(const Ref<Sqlite3StmtHandle>& stmt, int index) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), SQLITE_MISUSE);
    return ::sqlite3_bind_null(stmt->handle, index);
}

int Sqlite3Wrapper::bind_text(const Ref<Sqlite3StmtHandle>& stmt, int64_t index, const String& value, int64_t length, int64_t destructor_flag) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), SQLITE_MISUSE);
    godot::CharString cs = value.utf8();
    const char *str_ptr = cs.get_data();
    int result = ::sqlite3_bind_text(
        stmt->handle,
        (int)index,
        str_ptr,
        (int)length,
        (void (*)(void *))destructor_flag
    );
    return result;
}

int Sqlite3Wrapper::bind_text16(const Ref<Sqlite3StmtHandle>& stmt, int index, const String& value, int length) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), SQLITE_MISUSE);
    Char16String utf16 = value.utf16();
    const void *buf = utf16.ptr();
    int bytes = length;
    if (bytes == -1) {
        // Null-terminated, pass -1 as is
        bytes = -1;
    } else {
        // Length is number of bytes (number of char16_t units * 2)
        bytes = length * 2;
    }
    return ::sqlite3_bind_text16(stmt->handle, index, buf, bytes, SQLITE_TRANSIENT);
}

int Sqlite3Wrapper::bind_text64(const Ref<Sqlite3StmtHandle>& stmt, int64_t index, const String& text, int64_t nbytes, int64_t destructor, int64_t encoding) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), SQLITE_MISUSE);
    CharString utf8 = text.utf8();
    const char *cstr = utf8.get_data();
    sqlite3_uint64 len = (nbytes < 0) ? (sqlite3_uint64)utf8.length() : (sqlite3_uint64)nbytes;
    return ::sqlite3_bind_text64(stmt->handle, (int)index, cstr, len, (void(*)(void*))destructor, (unsigned char)encoding);
}

int Sqlite3Wrapper::bind_value(const Ref<Sqlite3StmtHandle>& stmt, int64_t index, const Ref<Sqlite3ValueHandle>& value) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), -1);
    ERR_FAIL_COND_V(value.is_null() || !value->is_valid(), -1);
    return ::sqlite3_bind_value(stmt->handle, (int)index, value->handle);
}

int Sqlite3Wrapper::bind_pointer(const Ref<Sqlite3StmtHandle>& stmt, int index, int64_t pointer, const String& type) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), SQLITE_MISUSE);
    void *c_pointer = reinterpret_cast<void *>(pointer);
    CharString type_utf8 = type.utf8();
    const char *c_type = type_utf8.length() > 0 ? type_utf8.get_data() : nullptr;
    return ::sqlite3_bind_pointer(stmt->handle, index, c_pointer, c_type, nullptr);
}

int Sqlite3Wrapper::bind_zeroblob64(const Ref<Sqlite3StmtHandle>& stmt, int64_t index, int64_t size) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), -1);
    return ::sqlite3_bind_zeroblob64(stmt->handle, (int)index, (sqlite3_uint64)size);
}

int Sqlite3Wrapper::bind_parameter_count(const Ref<Sqlite3StmtHandle>& stmt) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), 0);
    return ::sqlite3_bind_parameter_count(stmt->handle);
}

String Sqlite3Wrapper::bind_parameter_name(const Ref<Sqlite3StmtHandle>& stmt, int64_t index) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), String());
    const char *ret = ::sqlite3_bind_parameter_name(stmt->handle, (int)index);
    if (ret == nullptr) {
        return String();
    }
    return String(ret);
}

int Sqlite3Wrapper::bind_parameter_index(const Ref<Sqlite3StmtHandle>& stmt, const String& name) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), 0);
    CharString name_utf8 = name.utf8();
    return ::sqlite3_bind_parameter_index(stmt->handle, name_utf8.get_data());
}

int Sqlite3Wrapper::clear_bindings(const Ref<Sqlite3StmtHandle>& stmt) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), -1);
    int result = ::sqlite3_clear_bindings(stmt->handle);
    return result;
}

int Sqlite3Wrapper::column_count(const Ref<Sqlite3StmtHandle>& p_stmt) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(p_stmt.is_null() || !p_stmt->is_valid(), 0);
    return ::sqlite3_column_count(p_stmt->handle);
}

String Sqlite3Wrapper::column_name(const Ref<Sqlite3StmtHandle>& stmt, int column) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), String());
    const char *name = ::sqlite3_column_name(stmt->handle, column);
    if (name == nullptr) {
        return String();
    }
    return String::utf8(name);
}

#ifdef SQLITE_ENABLE_COLUMN_METADATA
String Sqlite3Wrapper::column_database_name(const Ref<Sqlite3StmtHandle>& stmt, int column) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), String());
    const char *name = ::sqlite3_column_database_name(stmt->handle, column);
    return name ? String::utf8(name) : String();
}
#endif

String Sqlite3Wrapper::column_table_name16(const Ref<Sqlite3StmtHandle>& stmt, int col) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), String());
    const void* ptr = ::sqlite3_column_table_name16(stmt->handle, col);
    if (ptr) {
        return String::utf16(reinterpret_cast<const char16_t*>(ptr));
    }
    return String();
}

String Sqlite3Wrapper::column_origin_name(const Ref<Sqlite3StmtHandle>& stmt, int col) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), String());
    const char *name = ::sqlite3_column_origin_name(stmt->handle, col);
    return name ? String::utf8(name) : String();
}

String Sqlite3Wrapper::column_origin_name16(const Ref<Sqlite3StmtHandle>& stmt, int column) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), String());
    const void *ptr = ::sqlite3_column_origin_name16(stmt->handle, column);
    if (!ptr) {
        return String();
    }
    return String::utf16((const char16_t *)ptr);
}

String Sqlite3Wrapper::column_decltype(const Ref<Sqlite3StmtHandle>& stmt, int i) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), String());
    const char *decl = ::sqlite3_column_decltype(stmt->handle, i);
    if (!decl)
        return String();
    return String::utf8(decl);
}

int Sqlite3Wrapper::step(const Ref<Sqlite3StmtHandle>& stmt) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), SQLITE_MISUSE);
    return ::sqlite3_step(stmt->handle);
}

int Sqlite3Wrapper::data_count(const Ref<Sqlite3StmtHandle>& p_stmt) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(p_stmt.is_null() || !p_stmt->is_valid(), 0);
    return ::sqlite3_data_count(p_stmt->handle);
}

int Sqlite3Wrapper::sqlite_integer(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_INTEGER;
}

int Sqlite3Wrapper::sqlite_float(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FLOAT;
}

int Sqlite3Wrapper::sqlite_blob(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_BLOB;
}

int Sqlite3Wrapper::sqlite_null(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_NULL;
}

String Sqlite3Wrapper::column_text(const Ref<Sqlite3StmtHandle>& stmt, int i_col) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), String());
    const unsigned char *res = ::sqlite3_column_text(stmt->handle, i_col);
    return res ? String::utf8((const char *)res) : String();
}

String Sqlite3Wrapper::column_text16(const Ref<Sqlite3StmtHandle>& stmt, int i_col) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), String());
    const void *ptr = ::sqlite3_column_text16(stmt->handle, i_col);
    if (!ptr) {
        return String();
    }
    return String::utf16(reinterpret_cast<const char16_t *>(ptr));
}

Ref<Sqlite3ValueHandle> Sqlite3Wrapper::column_value(const Ref<Sqlite3StmtHandle>& stmt, int i_col) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), Ref<Sqlite3ValueHandle>());
    sqlite3_value *val = ::sqlite3_column_value(stmt->handle, i_col);
    if (!val) {
        return Ref<Sqlite3ValueHandle>();
    }
    Ref<Sqlite3ValueHandle> ref;
    ref.instantiate();
    ref->set_handle(reinterpret_cast<intptr_t>(val));
    return ref;
}

int Sqlite3Wrapper::column_bytes(const Ref<Sqlite3StmtHandle>& stmt, int i_col) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), -1);
    return ::sqlite3_column_bytes(stmt->handle, i_col);
}

int Sqlite3Wrapper::column_bytes16(const Ref<Sqlite3StmtHandle>& stmt, int i_col) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), -1);
    return ::sqlite3_column_bytes16(stmt->handle, i_col);
}

int Sqlite3Wrapper::column_type(const Ref<Sqlite3StmtHandle>& stmt, int i_col) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), -1);
    return ::sqlite3_column_type(stmt->handle, i_col);
}

int Sqlite3Wrapper::finalize(const Ref<Sqlite3StmtHandle>& p_stmt) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(p_stmt.is_null() || !p_stmt->is_valid(), -1);
    return ::sqlite3_finalize(p_stmt->handle);
}

int Sqlite3Wrapper::reset(const Ref<Sqlite3StmtHandle>& p_stmt) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(p_stmt.is_null() || !p_stmt->is_valid(), -1);
    return ::sqlite3_reset(p_stmt->handle);
}
int Sqlite3Wrapper::create_function(const Ref<Sqlite3Handle>& db, const String& function_name, int64_t n_arg, int64_t text_rep, int64_t app_data, Callable x_func, Callable x_step, Callable x_final) { // NOLINT(readability-convert-member-functions-to-static)
    // Validate db
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_MISUSE);
    // Validate function name length in UTF-8
    CharString cs_fn = function_name.utf8();
    if (strlen(cs_fn.get_data()) > 255) {
        return SQLITE_MISUSE;
    }

    struct _Sqlite3FunctionCtx {
        Callable x_func;
        Callable x_step;
        Callable x_final;
        int64_t app_data;
    };
    _Sqlite3FunctionCtx *ctx = memnew(_Sqlite3FunctionCtx);
    ctx->x_func = x_func;
    ctx->x_step = x_step;
    ctx->x_final = x_final;
    ctx->app_data = app_data;

    // Trampoline for xFunc
    auto xFunc = [](sqlite3_context *c, int argc, sqlite3_value **argv) {
        _Sqlite3FunctionCtx *ctx = (_Sqlite3FunctionCtx*)sqlite3_user_data(c);
        if (!ctx || !ctx->x_func.is_valid()) return;
        Ref<Sqlite3ContextHandle> context_handle;
        context_handle.instantiate();
        context_handle->set_handle(reinterpret_cast<intptr_t>(c));
        Array args;
        for (int i = 0; i < argc; ++i) {
            Ref<Sqlite3ValueHandle> val;
            val.instantiate();
            val->set_handle(reinterpret_cast<intptr_t>(argv[i]));
            args.push_back(val);
        }
        Array call_args;
        call_args.push_back(context_handle);
        call_args.push_back(args);
        ctx->x_func.callv(call_args);
    };

    // Trampoline for xStep
    auto xStep = [](sqlite3_context *c, int argc, sqlite3_value **argv) {
        _Sqlite3FunctionCtx *ctx = (_Sqlite3FunctionCtx*)sqlite3_user_data(c);
        if (!ctx || !ctx->x_step.is_valid()) return;
        Ref<Sqlite3ContextHandle> context_handle;
        context_handle.instantiate();
        context_handle->set_handle(reinterpret_cast<intptr_t>(c));
        Array args;
        for (int i = 0; i < argc; ++i) {
            Ref<Sqlite3ValueHandle> val;
            val.instantiate();
            val->set_handle(reinterpret_cast<intptr_t>(argv[i]));
            args.push_back(val);
        }
        Array call_args;
        call_args.push_back(context_handle);
        call_args.push_back(args);
        ctx->x_step.callv(call_args);
    };

    // Trampoline for xFinal
    auto xFinal = [](sqlite3_context *c) {
        _Sqlite3FunctionCtx *ctx = (_Sqlite3FunctionCtx*)sqlite3_user_data(c);
        if (!ctx || !ctx->x_final.is_valid()) return;
        Ref<Sqlite3ContextHandle> context_handle;
        context_handle.instantiate();
        context_handle->set_handle(reinterpret_cast<intptr_t>(c));
        Array call_args;
        call_args.push_back(context_handle);
        ctx->x_final.callv(call_args);
    };

    int ret = ::sqlite3_create_function(
        db->handle,
        cs_fn.get_data(),
        int(n_arg),
        int(text_rep),
        reinterpret_cast<void*>(ctx),
        x_func.is_valid() ? +xFunc : nullptr,
        x_step.is_valid() ? +xStep : nullptr,
        x_final.is_valid() ? +xFinal : nullptr
    );
    if (ret != 0) {
        memdelete(ctx);
    }
    return ret;
}

int Sqlite3Wrapper::create_function16(const Ref<Sqlite3Handle>& db, const String& function_name, int n_arg, int e_text_rep, Callable x_func, Callable x_step, Callable x_final) { // NOLINT(readability-convert-member-functions-to-static)
    // Convert function_name to UTF-16 as required by SQLite
    godot::Char16String utf16 = function_name.utf16();
    const void *zFunctionName = utf16.ptr();

    // Prepare context struct to hold Callables
    struct FunctionCtx {
        Callable x_func;
        Callable x_step;
        Callable x_final;
    };
    FunctionCtx *ctx = memnew(FunctionCtx);
    ctx->x_func = x_func;
    ctx->x_step = x_step;
    ctx->x_final = x_final;

    // Trampoline for xFunc
    auto xFunc = [](sqlite3_context *c, int argc, sqlite3_value **argv) {
        FunctionCtx *ctx = (FunctionCtx *)sqlite3_user_data(c);
        if (!ctx || !ctx->x_func.is_valid()) return;
        Ref<Sqlite3ContextHandle> context_handle;
        context_handle.instantiate();
        context_handle->set_handle(reinterpret_cast<intptr_t>(c));
        Array args;
        for (int i = 0; i < argc; ++i) {
            Ref<Sqlite3ValueHandle> val;
            val.instantiate();
            val->set_handle(reinterpret_cast<intptr_t>(argv[i]));
            args.push_back(val);
        }
        Array call_args;
        call_args.push_back(context_handle);
        call_args.push_back(args);
        ctx->x_func.callv(call_args);
    };

    // Trampoline for xStep
    auto xStep = [](sqlite3_context *c, int argc, sqlite3_value **argv) {
        FunctionCtx *ctx = (FunctionCtx *)sqlite3_user_data(c);
        if (!ctx || !ctx->x_step.is_valid()) return;
        Ref<Sqlite3ContextHandle> context_handle;
        context_handle.instantiate();
        context_handle->set_handle(reinterpret_cast<intptr_t>(c));
        Array args;
        for (int i = 0; i < argc; ++i) {
            Ref<Sqlite3ValueHandle> val;
            val.instantiate();
            val->set_handle(reinterpret_cast<intptr_t>(argv[i]));
            args.push_back(val);
        }
        Array call_args;
        call_args.push_back(context_handle);
        call_args.push_back(args);
        ctx->x_step.callv(call_args);
    };

    // Trampoline for xFinal
    auto xFinal = [](sqlite3_context *c) {
        FunctionCtx *ctx = (FunctionCtx *)sqlite3_user_data(c);
        if (!ctx || !ctx->x_final.is_valid()) return;
        Ref<Sqlite3ContextHandle> context_handle;
        context_handle.instantiate();
        context_handle->set_handle(reinterpret_cast<intptr_t>(c));
        Array call_args;
        call_args.push_back(context_handle);
        ctx->x_final.callv(call_args);
    };

    // Register the function
    int result = ::sqlite3_create_function16(
        db->handle, zFunctionName, n_arg, e_text_rep, ctx,
        x_func.is_valid() ? +xFunc : nullptr,
        x_step.is_valid() ? +xStep : nullptr,
        x_final.is_valid() ? +xFinal : nullptr
    );
    if (result != 0) {
        memdelete(ctx);
    }
    return result;
}

int Sqlite3Wrapper::create_function_v2(const Ref<Sqlite3Handle>& db, const String& function_name, int64_t n_arg, int64_t e_text_rep, Callable x_func, Callable x_step, Callable x_final) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_MISUSE);
    ERR_FAIL_COND_V(function_name.is_empty(), SQLITE_MISUSE);

    struct FunctionCtx {
        Callable func;
        Callable step;
        Callable finalizer;
    };
    FunctionCtx *ctx = memnew(FunctionCtx);
    ctx->func = x_func;
    ctx->step = x_step;
    ctx->finalizer = x_final;

    auto trampoline_func = [](sqlite3_context *c, int argc, sqlite3_value **argv) {
        FunctionCtx *ctx = (FunctionCtx *)sqlite3_user_data(c);
        if (!ctx || !ctx->func.is_valid()) return;
        Ref<Sqlite3ContextHandle> context_handle;
        context_handle.instantiate();
        context_handle->set_handle(reinterpret_cast<intptr_t>(c));
        Array args;
        for (int i = 0; i < argc; ++i) {
            Ref<Sqlite3ValueHandle> val;
            val.instantiate();
            val->set_handle(reinterpret_cast<intptr_t>(argv[i]));
            args.push_back(val);
        }
        Array call_args;
        call_args.push_back(context_handle);
        call_args.push_back(args);
        ctx->func.callv(call_args);
    };
    auto trampoline_step = [](sqlite3_context *c, int argc, sqlite3_value **argv) {
        FunctionCtx *ctx = (FunctionCtx *)sqlite3_user_data(c);
        if (!ctx || !ctx->step.is_valid()) return;
        Ref<Sqlite3ContextHandle> context_handle;
        context_handle.instantiate();
        context_handle->set_handle(reinterpret_cast<intptr_t>(c));
        Array args;
        for (int i = 0; i < argc; ++i) {
            Ref<Sqlite3ValueHandle> val;
            val.instantiate();
            val->set_handle(reinterpret_cast<intptr_t>(argv[i]));
            args.push_back(val);
        }
        Array call_args;
        call_args.push_back(context_handle);
        call_args.push_back(args);
        ctx->step.callv(call_args);
    };
    auto trampoline_final = [](sqlite3_context *c) {
        FunctionCtx *ctx = (FunctionCtx *)sqlite3_user_data(c);
        if (!ctx || !ctx->finalizer.is_valid()) return;
        Ref<Sqlite3ContextHandle> context_handle;
        context_handle.instantiate();
        context_handle->set_handle(reinterpret_cast<intptr_t>(c));
        Array call_args;
        call_args.push_back(context_handle);
        ctx->finalizer.callv(call_args);
    };
    auto trampoline_destroy = [](void *p) {
        FunctionCtx *ctx = (FunctionCtx *)p;
        memdelete(ctx);
    };

    godot::CharString cs_func = function_name.utf8();
    int result = ::sqlite3_create_function_v2(
        db->handle,
        cs_func.get_data(),
        (int)n_arg,
        (int)e_text_rep,
        ctx,
        x_func.is_valid() ? +trampoline_func : nullptr,
        x_step.is_valid() ? +trampoline_step : nullptr,
        x_final.is_valid() ? +trampoline_final : nullptr,
        trampoline_destroy
    );
    return result;
}

int Sqlite3Wrapper::create_window_function(const Ref<Sqlite3Handle>& db, const String& function_name, int n_arg, int e_text_rep, Callable step, Callable final, Callable value, Callable inverse, Callable destroy) { // NOLINT(readability-convert-member-functions-to-static)
    // Validate input
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_MISUSE);

    struct _WindowFuncCtx {
        Callable step_cb;
        Callable final_cb;
        Callable value_cb;
        Callable inverse_cb;
        Callable destroy_cb;
    } *ctx = memnew(_WindowFuncCtx);
    ctx->step_cb = step;
    ctx->final_cb = final;
    ctx->value_cb = value;
    ctx->inverse_cb = inverse;
    ctx->destroy_cb = destroy;

    // Trampoline for step
    auto xStep = [](sqlite3_context *c, int argc, sqlite3_value **argv) {
        _WindowFuncCtx *ctx = (_WindowFuncCtx*)sqlite3_user_data(c);
        if (!ctx || !ctx->step_cb.is_valid()) return;
        Ref<Sqlite3ContextHandle> gd_ctx;
        gd_ctx.instantiate();
        gd_ctx->set_handle(reinterpret_cast<intptr_t>(c));
        Array args;
        args.push_back(gd_ctx);
        PackedInt64Array vals;
        Array arg_array;
        for (int i = 0; i < argc; i++) {
            Ref<Sqlite3ValueHandle> gd_val;
            gd_val.instantiate();
            gd_val->set_handle(reinterpret_cast<intptr_t>(argv[i]));
            arg_array.push_back(gd_val);
        }
        args.push_back(argc);
        args.push_back(arg_array);
        ctx->step_cb.callv(args);
    };
    // Trampoline for final
    auto xFinal = [](sqlite3_context *c) {
        _WindowFuncCtx *ctx = (_WindowFuncCtx*)sqlite3_user_data(c);
        if (!ctx || !ctx->final_cb.is_valid()) return;
        Ref<Sqlite3ContextHandle> gd_ctx;
        gd_ctx.instantiate();
        gd_ctx->set_handle(reinterpret_cast<intptr_t>(c));
        Array args;
        args.push_back(gd_ctx);
        ctx->final_cb.callv(args);
    };
    // Trampoline for value
    auto xValue = [](sqlite3_context *c) {
        _WindowFuncCtx *ctx = (_WindowFuncCtx*)sqlite3_user_data(c);
        if (!ctx || !ctx->value_cb.is_valid()) return;
        Ref<Sqlite3ContextHandle> gd_ctx;
        gd_ctx.instantiate();
        gd_ctx->set_handle(reinterpret_cast<intptr_t>(c));
        Array args;
        args.push_back(gd_ctx);
        ctx->value_cb.callv(args);
    };
    // Trampoline for inverse
    auto xInverse = [](sqlite3_context *c, int argc, sqlite3_value **argv) {
        _WindowFuncCtx *ctx = (_WindowFuncCtx*)sqlite3_user_data(c);
        if (!ctx || !ctx->inverse_cb.is_valid()) return;
        Ref<Sqlite3ContextHandle> gd_ctx;
        gd_ctx.instantiate();
        gd_ctx->set_handle(reinterpret_cast<intptr_t>(c));
        Array args;
        args.push_back(gd_ctx);
        Array arg_array;
        for (int i = 0; i < argc; i++) {
            Ref<Sqlite3ValueHandle> gd_val;
            gd_val.instantiate();
            gd_val->set_handle(reinterpret_cast<intptr_t>(argv[i]));
            arg_array.push_back(gd_val);
        }
        args.push_back(argc);
        args.push_back(arg_array);
        ctx->inverse_cb.callv(args);
    };
    // Trampoline for destroy
    auto xDestroy = [](void *p) {
        _WindowFuncCtx *ctx = (_WindowFuncCtx*)p;
        if (ctx && ctx->destroy_cb.is_valid()) {
            ctx->destroy_cb.callv(Array());
        }
        memdelete(ctx);
    };

    CharString cs = function_name.utf8();
    int rc = ::sqlite3_create_window_function(
        db->handle,
        cs.get_data(),
        n_arg,
        e_text_rep,
        ctx,
        xStep,
        xFinal,
        xValue,
        xInverse,
        xDestroy
    );
    if (rc != 0) {
        memdelete(ctx);
    }
    return rc;
}

int Sqlite3Wrapper::sqlite_utf8(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_UTF8;
}

int Sqlite3Wrapper::sqlite_utf16le(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_UTF16LE;
}

int Sqlite3Wrapper::sqlite_utf16be(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_UTF16BE;
}

int Sqlite3Wrapper::sqlite_utf16(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_UTF16;
}

int Sqlite3Wrapper::sqlite_any(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_ANY;
}

int Sqlite3Wrapper::sqlite_utf16_aligned(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_UTF16_ALIGNED;
}

int Sqlite3Wrapper::sqlite_utf8_zt(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_UTF8_ZT;
}

int Sqlite3Wrapper::sqlite_deterministic(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DETERMINISTIC;
}

int Sqlite3Wrapper::sqlite_directonly(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DIRECTONLY;
}

int Sqlite3Wrapper::sqlite_subtype(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_SUBTYPE;
}

int Sqlite3Wrapper::sqlite_innocuous(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_INNOCUOUS;
}

int Sqlite3Wrapper::sqlite_result_subtype(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_RESULT_SUBTYPE;
}

int Sqlite3Wrapper::sqlite_selforder1(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_SELFORDER1;
}

#ifndef SQLITE_OMIT_DEPRECATED
int Sqlite3Wrapper::aggregate_count(const Ref<Sqlite3ContextHandle>& ctx) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(ctx.is_null() || !ctx->is_valid(), -1);
    return ::sqlite3_aggregate_count(ctx->handle);
}
#endif

#ifndef SQLITE_OMIT_DEPRECATED
int Sqlite3Wrapper::expired(const Ref<Sqlite3StmtHandle>& stmt) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), -1);
    return ::sqlite3_expired(stmt->handle);
}
#endif

#ifndef SQLITE_OMIT_DEPRECATED
int Sqlite3Wrapper::transfer_bindings(const Ref<Sqlite3StmtHandle>& from, const Ref<Sqlite3StmtHandle>& to) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(from.is_null() || !from->is_valid(), -1);
    ERR_FAIL_COND_V(to.is_null() || !to->is_valid(), -1);
    return ::sqlite3_transfer_bindings(from->handle, to->handle);
}
#endif

#ifndef SQLITE_OMIT_DEPRECATED
int Sqlite3Wrapper::global_recover(void) { // NOLINT(readability-convert-member-functions-to-static)
    return ::sqlite3_global_recover();
}
#endif

#ifndef SQLITE_OMIT_DEPRECATED
void Sqlite3Wrapper::thread_cleanup(void) { // NOLINT(readability-convert-member-functions-to-static)
    ::sqlite3_thread_cleanup();
}
#endif

#ifndef SQLITE_OMIT_DEPRECATED
int Sqlite3Wrapper::memory_alarm(Callable callback, int user_data, int threshold) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(!callback.is_valid(), -1);
    struct _MemoryAlarmCtx {
        Callable cb;
        int user_data;
    } ctx{callback, user_data};
    auto trampoline = [](void *ud, sqlite3_int64 t, int i) {
        _MemoryAlarmCtx *ctx = reinterpret_cast<_MemoryAlarmCtx *>(ud);
        Array args;
        args.push_back(ctx->user_data);
        args.push_back(int64_t(t));
        args.push_back(i);
        ctx->cb.callv(args);
    };
    return ::sqlite3_memory_alarm(trampoline, &ctx, threshold);
}
#endif

String Sqlite3Wrapper::value_text(const Ref<Sqlite3ValueHandle>& value) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(value.is_null() || !value->is_valid(), String());
    const unsigned char *ptr = ::sqlite3_value_text(value->handle);
    return ptr ? String::utf8((const char*)ptr) : String();
}

String Sqlite3Wrapper::value_text16(const Ref<Sqlite3ValueHandle>& value) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(value.is_null() || !value->is_valid(), String());
    const void *ptr = ::sqlite3_value_text16(value->handle);
    if (!ptr) {
        return String();
    }
    const char16_t *utf16 = reinterpret_cast<const char16_t*>(ptr);
    int len = 0;
    while (utf16[len]) ++len;
    return String::utf16(utf16, len);
}

int64_t Sqlite3Wrapper::value_text16le(const Ref<Sqlite3ValueHandle>& value) { // NOLINT(readability-convert-member-functions-to-static)
    const void *ptr = ::sqlite3_value_text16le(value->handle);
    return ptr ? reinterpret_cast<int64_t>(ptr) : 0;
}

String Sqlite3Wrapper::value_text16be(const Ref<Sqlite3ValueHandle>& value) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(value.is_null() || !value->is_valid(), String());
    const void *ptr = ::sqlite3_value_text16be(value->handle);
    if (!ptr) {
        return String();
    }
    int byte_len = ::sqlite3_value_bytes16(value->handle);
    if (byte_len <= 0) {
        return String();
    }
    int char_len = byte_len / 2;
    const uint8_t *src_bytes = static_cast<const uint8_t *>(ptr);
    std::vector<char16_t> utf16_buf(char_len);
    for (int i = 0; i < char_len; i++) {
        // SQLite returns UTF-16BE, swap to native if needed
        utf16_buf[i] = (char16_t)((src_bytes[2*i] << 8) | src_bytes[2*i+1]);
    }
    return String::utf16((const char16_t *)utf16_buf.data(), char_len);
}

int Sqlite3Wrapper::value_bytes16(const Ref<Sqlite3ValueHandle>& value) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(value.is_null() || !value->is_valid(), 0);
    return ::sqlite3_value_bytes16(value->handle);
}

int Sqlite3Wrapper::value_type(const Ref<Sqlite3ValueHandle>& value) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(value.is_null() || !value->is_valid(), -1);
    return ::sqlite3_value_type(value->handle);
}

int Sqlite3Wrapper::value_numeric_type(const Ref<Sqlite3ValueHandle>& value) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(value.is_null() || !value->is_valid(), -1);
    return ::sqlite3_value_numeric_type(value->handle);
}

int Sqlite3Wrapper::value_nochange(const Ref<Sqlite3ValueHandle>& value) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(value.is_null() || !value->is_valid(), -1);
    return ::sqlite3_value_nochange(value->handle);
}

int Sqlite3Wrapper::value_frombind(const Ref<Sqlite3ValueHandle>& value) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(value.is_null() || !value->is_valid(), 0);
    return ::sqlite3_value_frombind(value->handle);
}

int Sqlite3Wrapper::value_encoding(const Ref<Sqlite3ValueHandle>& value) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(value.is_null() || !value->is_valid(), 0);
    return ::sqlite3_value_encoding(value->handle);
}

int Sqlite3Wrapper::value_subtype(const Ref<Sqlite3ValueHandle>& value) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(value.is_null() || !value->is_valid(), 0);
    return ::sqlite3_value_subtype(value->handle);
}

Ref<Sqlite3ValueHandle> Sqlite3Wrapper::value_dup(const Ref<Sqlite3ValueHandle>& value) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(value.is_null() || !value->is_valid(), Ref<Sqlite3ValueHandle>());
    sqlite3_value *dup_ptr = ::sqlite3_value_dup(value->handle);
    if (!dup_ptr) {
        return Ref<Sqlite3ValueHandle>();
    }
    Ref<Sqlite3ValueHandle> ref;
    ref.instantiate();
    ref->set_handle(reinterpret_cast<intptr_t>(dup_ptr));
    return ref;
}

int Sqlite3Wrapper::aggregate_context(const Ref<Sqlite3ContextHandle>& ctx, int n_bytes) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(ctx.is_null() || !ctx->is_valid(), 0);
    void *ptr = ::sqlite3_aggregate_context(ctx->handle, n_bytes);
    return reinterpret_cast<int64_t>(ptr);
}

int64_t Sqlite3Wrapper::user_data(const Ref<Sqlite3ContextHandle>& ctx) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(ctx.is_null() || !ctx->is_valid(), 0);
    void *ptr = ::sqlite3_user_data(ctx->handle);
    return reinterpret_cast<int64_t>(ptr);
}

Ref<Sqlite3Handle> Sqlite3Wrapper::context_db_handle(const Ref<Sqlite3ContextHandle>& ctx) { // NOLINT(readability-convert-member-functions-to-static)
    if (ctx.is_null() || !ctx->is_valid()) {
        return Ref<Sqlite3Handle>();
    }
    sqlite3 *db_ptr = ::sqlite3_context_db_handle(ctx->handle);
    if (!db_ptr) {
        return Ref<Sqlite3Handle>();
    }
    Ref<Sqlite3Handle> db_handle;
    db_handle.instantiate();
    db_handle->set_handle(reinterpret_cast<intptr_t>(db_ptr));
    return db_handle;
}

int64_t Sqlite3Wrapper::get_auxdata(const Ref<Sqlite3ContextHandle>& context, int n) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(context.is_null() || !context->is_valid(), 0);
    void *ptr = ::sqlite3_get_auxdata(context->handle, n);
    return reinterpret_cast<int64_t>(ptr);
}

int64_t Sqlite3Wrapper::get_clientdata(const Ref<Sqlite3Handle>& db, const String& name) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), 0);
    CharString name_utf8 = name.utf8();
    void *ptr = ::sqlite3_get_clientdata(db->handle, name_utf8.get_data());
    return reinterpret_cast<int64_t>(ptr);
}

void Sqlite3Wrapper::result_error(const Ref<Sqlite3ContextHandle>& ctx, const String& error_message, int length) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND(ctx.is_null() || !ctx->is_valid());
    CharString cs = error_message.utf8();
    ::sqlite3_result_error(ctx->handle, cs.get_data(), length);
}

void Sqlite3Wrapper::result_error_toobig(const Ref<Sqlite3ContextHandle>& ctx) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND(ctx.is_null() || !ctx->is_valid());
    ::sqlite3_result_error_toobig(ctx->handle);
}

void Sqlite3Wrapper::result_error_code(const Ref<Sqlite3ContextHandle>& context, int error_code) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND(context.is_null() || !context->is_valid());
    ::sqlite3_result_error_code(context->handle, error_code);
}

void Sqlite3Wrapper::result_int(const Ref<Sqlite3ContextHandle>& context, int value) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND(context.is_null() || !context->is_valid());
    ::sqlite3_result_int(context->handle, value);
}

void Sqlite3Wrapper::result_int64(const Ref<Sqlite3ContextHandle>& ctx, int64_t value) { // NOLINT(readability-convert-member-functions-to-static)
    ::sqlite3_result_int64(ctx->handle, value);
}

void Sqlite3Wrapper::result_null(const Ref<Sqlite3ContextHandle>& ctx) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND(ctx.is_null() || !ctx->is_valid());
    ::sqlite3_result_null(ctx->handle);
}

void Sqlite3Wrapper::result_text(const Ref<Sqlite3ContextHandle>& context, const String& text, int64_t length, int64_t destructor) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND(context.is_null() || !context->is_valid());
    godot::CharString utf8 = text.utf8();
    ::sqlite3_result_text(context->handle, utf8.get_data(), (int)length, reinterpret_cast<void(*)(void*)>(destructor));
}

void Sqlite3Wrapper::result_text64(const Ref<Sqlite3ContextHandle>& ctx, const String& text, uint64_t n, int encoding) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND(ctx.is_null() || !ctx->is_valid());
    CharString cs = text.utf8();
    ::sqlite3_result_text64(ctx->handle, cs.get_data(), n, (void(*)(void*))-1, (unsigned char)encoding);
}

void Sqlite3Wrapper::result_text16(const Ref<Sqlite3ContextHandle>& ctx, const String& text, int length, int destructor) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND(ctx.is_null() || !ctx->is_valid());
    Char16String cs = text.utf16();
    const void *ptr = cs.ptr();
    int nbytes = length;
    ::sqlite3_result_text16(ctx->handle, ptr, nbytes, reinterpret_cast<void(*)(void*)>(destructor));
}

void Sqlite3Wrapper::result_text16le(const Ref<Sqlite3ContextHandle>& ctx, const PackedByteArray& data, int64_t destructor) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND(ctx.is_null() || !ctx->is_valid());
    const void *ptr = data.ptr();
    int len = data.size();
    ::sqlite3_result_text16le(ctx->handle, ptr, len, reinterpret_cast<void(*)(void*)>(destructor));
}

void Sqlite3Wrapper::result_text16be(const Ref<Sqlite3ContextHandle>& context, const PackedByteArray& text, int length, int64_t destructor) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND(context.is_null() || !context->is_valid());
    ERR_FAIL_COND(text.size() < length);
    const uint8_t *ptr = text.ptr();
    ::sqlite3_result_text16be(context->handle, ptr, (int)length, (void(*)(void*))destructor);
}

void Sqlite3Wrapper::result_pointer(const Ref<Sqlite3ContextHandle>& ctx, int data_ptr, const String& type, int destructor_ptr) { // NOLINT(readability-convert-member-functions-to-static)
    CharString cs_type = type.utf8();
    ::sqlite3_result_pointer(
        ctx->handle,
        reinterpret_cast<void*>(data_ptr),
        cs_type.get_data(),
        reinterpret_cast<void(*)(void*)>(destructor_ptr)
    );
}

void Sqlite3Wrapper::result_zeroblob(const Ref<Sqlite3ContextHandle>& ctx, int n) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND(ctx.is_null() || !ctx->is_valid());
    ::sqlite3_result_zeroblob(ctx->handle, n);
}

int Sqlite3Wrapper::result_zeroblob64(const Ref<Sqlite3ContextHandle>& context, int64_t n) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(context.is_null() || !context->is_valid(), -1);
    return ::sqlite3_result_zeroblob64(context->handle, (sqlite3_uint64)n);
}

void Sqlite3Wrapper::result_subtype(const Ref<Sqlite3ContextHandle>& context, int64_t subtype) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND(context.is_null() || !context->is_valid());
    ::sqlite3_result_subtype(context->handle, (unsigned int)subtype);
}

int Sqlite3Wrapper::create_collation(const Ref<Sqlite3Handle>& db, const String& name, int e_text_rep, const Variant& user_data, Callable compare) { // NOLINT(readability-convert-member-functions-to-static)
    // Validate inputs
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_MISUSE);
    ERR_FAIL_COND_V(!compare.is_valid(), SQLITE_MISUSE);

    struct _CollationCtx {
        Callable cb;
        Variant user_data;
    };
    _CollationCtx *ctx = memnew(_CollationCtx);
    ctx->cb = compare;
    ctx->user_data = user_data;

    auto trampoline = [](void *pArg, int n1, const void *s1, int n2, const void *s2) -> int {
        _CollationCtx *ctx = reinterpret_cast<_CollationCtx *>(pArg);
        PackedByteArray a;
        PackedByteArray b;
        if (n1 > 0 && s1) {
            a.resize(n1);
            memcpy(a.ptrw(), s1, n1);
        }
        if (n2 > 0 && s2) {
            b.resize(n2);
            memcpy(b.ptrw(), s2, n2);
        }
        Array args;
        args.push_back(ctx->user_data);
        args.push_back(a);
        args.push_back(b);
        Variant ret = ctx->cb.callv(args);
        if (ret.get_type() != Variant::INT) {
            ERR_PRINT("Collation compare callback must return int");
            return 0;
        }
        return int(ret);
    };

    int result = ::sqlite3_create_collation(db->handle, name.utf8().get_data(), e_text_rep, ctx, trampoline);
    // Note: SQLite will not call any destructor for ctx, so this memory will be leaked unless the collation is destroyed. Document this for users.
    return result;
}

int Sqlite3Wrapper::create_collation16(const Ref<Sqlite3Handle>& db, const String& z_name, int e_text_rep, const Variant& user_data, Callable x_compare) { // NOLINT(readability-convert-member-functions-to-static)
    // Validate input
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_MISUSE);
    ERR_FAIL_COND_V(!x_compare.is_valid(), SQLITE_MISUSE);
    ERR_FAIL_COND_V(z_name.is_empty(), SQLITE_MISUSE);

    Char16String name_utf16 = z_name.utf16();
    const void *z_name_ptr = static_cast<const void *>(name_utf16.ptr());

    struct Collation16Context {
        Callable cb;
        Variant user_data;
    };
    Collation16Context *ctx = memnew(Collation16Context);
    ctx->cb = x_compare;
    ctx->user_data = user_data;

    auto trampoline = [](void *p_arg, int n1, const void *s1, int n2, const void *s2) -> int {
        Collation16Context *ctx = static_cast<Collation16Context *>(p_arg);
        String str1 = String::utf16(reinterpret_cast<const char16_t *>(s1), n1 / 2);
        String str2 = String::utf16(reinterpret_cast<const char16_t *>(s2), n2 / 2);
        Array args;
        args.push_back(ctx->user_data);
        args.push_back(str1);
        args.push_back(str2);
        Variant ret = ctx->cb.callv(args);
        if (ret.get_type() != Variant::INT) {
            ERR_PRINT("Collation callback should return int, got: " + ret.stringify());
            return 0;
        }
        return int(ret);
    };

    return ::sqlite3_create_collation16(db->handle, z_name_ptr, e_text_rep, ctx, trampoline);
}

int Sqlite3Wrapper::collation_needed(const Ref<Sqlite3Handle>& db, Callable callback) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_MISUSE);
    ERR_FAIL_COND_V(!callback.is_valid(), SQLITE_MISUSE);

    struct _CollationNeededCtx {
        Callable cb;
    };

    // Clean up previous context if set
    if (db->has_meta("collation_needed_ctx")) {
        void *prev_ctx = db->get_meta("collation_needed_ctx");
        memdelete(reinterpret_cast<_CollationNeededCtx*>(prev_ctx));
        db->set_meta("collation_needed_ctx", nullptr);
    }

    _CollationNeededCtx *ctx = memnew(_CollationNeededCtx);
    ctx->cb = callback;
    db->set_meta("collation_needed_ctx", ctx);

    auto trampoline = [](void *ud, sqlite3 *c_db, int eTextRep, const char *name) {
        _CollationNeededCtx *ctx = reinterpret_cast<_CollationNeededCtx *>(ud);
        Ref<Sqlite3Handle> db_ref;
        db_ref.instantiate();
        db_ref->set_handle(reinterpret_cast<intptr_t>(c_db));
        String gd_name = name ? String::utf8(name) : String();
        Array args;
        args.push_back(db_ref);
        args.push_back(eTextRep);
        args.push_back(gd_name);
        ctx->cb.callv(args);
    };

    return ::sqlite3_collation_needed(db->handle, ctx, trampoline);
}

#ifdef SQLITE_ENABLE_CEROD
void Sqlite3Wrapper::activate_cerod(const String& pass_phrase) { // NOLINT(readability-convert-member-functions-to-static)
    CharString cs = pass_phrase.utf8();
    ::sqlite3_activate_cerod(cs.get_data());
}
#endif

int64_t Sqlite3Wrapper::sleep(int64_t milliseconds) { // NOLINT(readability-convert-member-functions-to-static)
    return (int64_t)::sqlite3_sleep((int)milliseconds);
}

Ref<Sqlite3Handle> Sqlite3Wrapper::db_handle(const Ref<Sqlite3StmtHandle>& stmt) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), Ref<Sqlite3Handle>());
    sqlite3* db = ::sqlite3_db_handle(stmt->handle);
    Ref<Sqlite3Handle> ref;
    ref.instantiate();
    ref->set_handle(reinterpret_cast<intptr_t>(db));
    return ref;
}

String Sqlite3Wrapper::db_name(const Ref<Sqlite3Handle>& db, int N) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), String());
    const char *result = ::sqlite3_db_name(db->handle, N);
    if (!result) {
        return String();
    }
    return String::utf8(result);
}

String Sqlite3Wrapper::db_filename(const Ref<Sqlite3Handle>& db, const String& z_db_name) { // NOLINT(readability-convert-member-functions-to-static)
    if (db.is_null() || !db->is_valid()) {
        return String();
    }
    godot::CharString cs = z_db_name.utf8();
    const char *res = ::sqlite3_db_filename(db->handle, cs.get_data());
    if (res == nullptr) {
        return String();
    }
    return String(res);
}

int Sqlite3Wrapper::db_readonly(const Ref<Sqlite3Handle>& db, const String& db_name) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    CharString cs = db_name.utf8();
    return ::sqlite3_db_readonly(db->handle, cs.get_data());
}

int Sqlite3Wrapper::txn_state(const Ref<Sqlite3Handle>& db, const String& z_schema) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    int result;
    if (z_schema.is_empty()) {
        result = ::sqlite3_txn_state(db->handle, nullptr);
    } else {
        CharString cs = z_schema.utf8();
        result = ::sqlite3_txn_state(db->handle, cs.get_data());
    }
    return result;
}

int Sqlite3Wrapper::txn_none(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TXN_NONE;
}

int Sqlite3Wrapper::txn_read(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TXN_READ;
}

int Sqlite3Wrapper::txn_write(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_TXN_WRITE;
}

int64_t Sqlite3Wrapper::commit_hook(const Ref<Sqlite3Handle>& db, Callable callback) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), 0);

    struct _CommitHookCtx {
        Callable cb;
    };

    static auto trampoline = [](void *ud) -> int {
        _CommitHookCtx *ctx = reinterpret_cast<_CommitHookCtx *>(ud);
        Variant ret = ctx->cb.call();
        if (ret.get_type() != Variant::INT) {
            ERR_PRINT("commit_hook callback must return int (0 or nonzero), got: " + ret.stringify());
            return 0;
        }
        return int(ret);
    };

    _CommitHookCtx *ctx_ptr = nullptr;
    int (*cb_ptr)(void *) = nullptr;
    if (callback.is_valid()) {
        ctx_ptr = memnew(_CommitHookCtx);
        ctx_ptr->cb = callback;
        cb_ptr = trampoline;
    }
    void *prev_userdata = ::sqlite3_commit_hook(db->handle, cb_ptr, ctx_ptr);
    return reinterpret_cast<int64_t>(prev_userdata);
}

int Sqlite3Wrapper::autovacuum_pages(const Ref<Sqlite3Handle>& db, Callable on_autovacuum, Callable on_userdata_destroy) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_MISUSE);

    typedef struct {
        Callable cb;
        Callable destructor;
    } AutoVacuumCtx;

    AutoVacuumCtx *ctx = nullptr;
    unsigned int (*cb_fn)(void*,const char*,unsigned int,unsigned int,unsigned int) = nullptr;
    void (*destructor_fn)(void*) = nullptr;

    if (on_autovacuum.is_valid()) {
        ctx = memnew(AutoVacuumCtx);
        ctx->cb = on_autovacuum;
        ctx->destructor = on_userdata_destroy;

        cb_fn = [](void *ud, const char *zSchema, unsigned int nDbPage, unsigned int nFreePage, unsigned int nBytePerPage) -> unsigned int {
            AutoVacuumCtx *ctx = reinterpret_cast<AutoVacuumCtx *>(ud);
            Array args;
            args.push_back(String(zSchema));
            args.push_back((int64_t)nDbPage);
            args.push_back((int64_t)nFreePage);
            args.push_back((int64_t)nBytePerPage);
            Variant ret = ctx->cb.callv(args);
            if (ret.get_type() != Variant::INT) {
                ERR_PRINT("autovacuum callback must return int, got: " + ret.stringify());
                return 0;
            }
            return (unsigned int)(int64_t)ret;
        };

        destructor_fn = [](void *ud) {
            AutoVacuumCtx *ctx = reinterpret_cast<AutoVacuumCtx *>(ud);
            if (ctx->destructor.is_valid()) {
                ctx->destructor.call();
            }
            memdelete(ctx);
        };
    }

    int rc = ::sqlite3_autovacuum_pages(
        db->handle,
        cb_fn,
        ctx,
        destructor_fn
    );

    return rc;
}

void Sqlite3Wrapper::update_hook(const Ref<Sqlite3Handle>& db, Callable callback) { // NOLINT(readability-convert-member-functions-to-static)
    // Validate input
    ERR_FAIL_COND(db.is_null() || !db->is_valid());

    // Define context struct to hold the Callable
    struct _UpdateHookContext {
        Callable cb;
    };

    // Retrieve user_data field for storing context pointer (per connection)
    static thread_local std::unordered_map<sqlite3*, _UpdateHookContext*> hook_contexts;

    // If a previous context exists, clean it up
    auto it = hook_contexts.find(db->handle);
    if (it != hook_contexts.end()) {
        delete it->second;
        hook_contexts.erase(it);
    }

    _UpdateHookContext *ctx = nullptr;
    void (*c_hook)(void *, int, const char *, const char *, sqlite3_int64) = nullptr;

    if (callback.is_valid()) {
        ctx = new _UpdateHookContext{callback};
        c_hook = [](void *ud, int op, const char *db_name, const char *tbl_name, sqlite3_int64 rowid) {
            _UpdateHookContext *ctx = reinterpret_cast<_UpdateHookContext *>(ud);
            Array args;
            args.push_back(op);
            args.push_back(db_name ? String::utf8(db_name) : String());
            args.push_back(tbl_name ? String::utf8(tbl_name) : String());
            args.push_back((int64_t)rowid);
            ctx->cb.callv(args);
        };
        hook_contexts[db->handle] = ctx;
    }

    // Register the hook (returns previous user_data, which we ignore)
    ::sqlite3_update_hook(db->handle, c_hook, ctx);
}

#ifndef SQLITE_OMIT_SHARED_CACHE
int Sqlite3Wrapper::enable_shared_cache(bool enable) { // NOLINT(readability-convert-member-functions-to-static)
    return ::sqlite3_enable_shared_cache(enable ? 1 : 0);
}
#endif

int64_t Sqlite3Wrapper::soft_heap_limit64(int64_t n) { // NOLINT(readability-convert-member-functions-to-static)
    return ::sqlite3_soft_heap_limit64(n);
}

Dictionary Sqlite3Wrapper::table_column_metadata(const Ref<Sqlite3Handle>& db, const String& db_name, const String& table_name, const String& column_name) { // NOLINT(readability-convert-member-functions-to-static)
    Dictionary result;
    if (db.is_null() || !db->is_valid()) {
        result["error"] = (int)SQLITE_MISUSE;
        return result;
    }
    CharString db_name_cs = db_name.is_empty() ? CharString() : db_name.utf8();
    const char *c_db_name = db_name.is_empty() ? nullptr : db_name_cs.get_data();
    CharString table_name_cs = table_name.is_empty() ? CharString() : table_name.utf8();
    const char *c_table_name = table_name.is_empty() ? nullptr : table_name_cs.get_data();
    CharString column_name_cs = column_name.is_empty() ? CharString() : column_name.utf8();
    const char *c_column_name = column_name.is_empty() ? nullptr : column_name_cs.get_data();
    const char *data_type = nullptr;
    const char *coll_seq = nullptr;
    int not_null = 0;
    int primary_key = 0;
    int autoinc = 0;
    int rc = ::sqlite3_table_column_metadata(
        db->handle,
        c_db_name,
        c_table_name,
        c_column_name,
        &data_type,
        &coll_seq,
        &not_null,
        &primary_key,
        &autoinc
    );
    result["data_type"] = data_type ? String(data_type) : String();
    result["coll_seq"] = coll_seq ? String(coll_seq) : String();
    result["not_null"] = not_null;
    result["primary_key"] = primary_key;
    result["autoinc"] = autoinc;
    result["error"] = rc;
    return result;
}

int Sqlite3Wrapper::enable_load_extension(const Ref<Sqlite3Handle>& db, int onoff) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    return ::sqlite3_enable_load_extension(db->handle, onoff);
}

int Sqlite3Wrapper::auto_extension(Callable x_entry_point) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_PRINT("sqlite3_auto_extension is not supported in this wrapper due to the complexity of managing global state and ensuring proper cleanup. Consider manually loading extensions using load_extension instead.");
    (void)x_entry_point; // Suppress unused parameter warning
    return SQLITE_MISUSE;
}

int Sqlite3Wrapper::overload_function(const Ref<Sqlite3Handle>& db, const String& func_name, int n_arg) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    CharString fn = func_name.utf8();
    return ::sqlite3_overload_function(db->handle, fn.get_data(), n_arg);
}

int Sqlite3Wrapper::blob_reopen(const Ref<Sqlite3BlobHandle>& db_blob, int64_t rowid) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db_blob.is_null() || !db_blob->is_valid(), -1);
    return ::sqlite3_blob_reopen(db_blob->handle, rowid);
}

int Sqlite3Wrapper::blob_close(const Ref<Sqlite3BlobHandle>& blob_handle) { // NOLINT(readability-convert-member-functions-to-static)
    if (blob_handle.is_null() || !blob_handle->is_valid()) {
        return 0;
    }
    int result = ::sqlite3_blob_close(blob_handle->handle);
    blob_handle->set_handle(0);
    return result;
}

int Sqlite3Wrapper::blob_bytes(const Ref<Sqlite3BlobHandle>& blob) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(blob.is_null() || !blob->is_valid(), -1);
    return ::sqlite3_blob_bytes(blob->handle);
}

PackedByteArray Sqlite3Wrapper::blob_read(const Ref<Sqlite3BlobHandle>& blob, int64_t n, int64_t offset) { // NOLINT(readability-convert-member-functions-to-static)
    PackedByteArray buffer;
    if (blob.is_null() || !blob->is_valid()) {
        ERR_PRINT("Invalid or null Sqlite3BlobHandle in blob_read.");
        return buffer;
    }
    if (n < 0 || offset < 0) {
        ERR_PRINT("n and offset must be non-negative in blob_read.");
        return buffer;
    }
    buffer.resize(n);
    if (n == 0) {
        return buffer;
    }
    int result = ::sqlite3_blob_read(blob->handle, buffer.ptrw(), (int)n, (int)offset);
    if (result != SQLITE_OK) {
        ERR_PRINT("sqlite3_blob_read failed with error code: " + itos(result));
        buffer.resize(0);
    }
    return buffer;
}

int Sqlite3Wrapper::blob_write(const Ref<Sqlite3BlobHandle>& blob, const PackedByteArray& buffer, int64_t offset) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(blob.is_null() || !blob->is_valid(), SQLITE_MISUSE);
    ERR_FAIL_COND_V(offset < 0, SQLITE_ERROR);

    int n = buffer.size();
    const void *ptr = n > 0 ? buffer.ptr() : nullptr;

    return ::sqlite3_blob_write(blob->handle, ptr, n, (int)offset);
}

Ref<Sqlite3VfsHandle> Sqlite3Wrapper::vfs_find(const String& vfs_name) { // NOLINT(readability-convert-member-functions-to-static)
    Ref<Sqlite3VfsHandle> ref;
    if (vfs_name.is_empty()) {
        sqlite3_vfs *ptr = ::sqlite3_vfs_find(nullptr);
        if (ptr) {
            ref.instantiate();
            ref->set_handle(reinterpret_cast<intptr_t>(ptr));
        }
        return ref;
    } else {
        CharString cs = vfs_name.utf8();
        sqlite3_vfs *ptr = ::sqlite3_vfs_find(cs.get_data());
        if (ptr) {
            ref.instantiate();
            ref->set_handle(reinterpret_cast<intptr_t>(ptr));
        }
        return ref;
    }
}

#ifndef NDEBUG
int Sqlite3Wrapper::mutex_held(const Ref<Sqlite3MutexHandle>& handle) { // NOLINT(readability-convert-member-functions-to-static)
    int result = ::sqlite3_mutex_held(handle.is_null() ? nullptr : handle->handle);
    return result;
}
#endif

#ifndef NDEBUG
int Sqlite3Wrapper::mutex_notheld(const Ref<Sqlite3MutexHandle>& handle) { // NOLINT(readability-convert-member-functions-to-static)
    int result = ::sqlite3_mutex_notheld(handle.is_null() ? nullptr : handle->handle);
    return result;
}
#endif

int Sqlite3Wrapper::sqlite_mutex_fast(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_MUTEX_FAST;
}

int Sqlite3Wrapper::sqlite_mutex_recursive(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_MUTEX_RECURSIVE;
}

int Sqlite3Wrapper::sqlite_mutex_static_main(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_MUTEX_STATIC_MAIN;
}

int Sqlite3Wrapper::sqlite_mutex_static_mem(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_MUTEX_STATIC_MEM;
}

int Sqlite3Wrapper::sqlite_mutex_static_mem2(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_MUTEX_STATIC_MEM2;
}

int Sqlite3Wrapper::sqlite_mutex_static_open(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_MUTEX_STATIC_OPEN;
}

int Sqlite3Wrapper::sqlite_mutex_static_prng(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_MUTEX_STATIC_PRNG;
}

int Sqlite3Wrapper::sqlite_mutex_static_lru(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_MUTEX_STATIC_LRU;
}

int Sqlite3Wrapper::sqlite_mutex_static_lru2(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_MUTEX_STATIC_LRU2;
}

int Sqlite3Wrapper::sqlite_mutex_static_pmem(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_MUTEX_STATIC_PMEM;
}

int Sqlite3Wrapper::sqlite_mutex_static_app1(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_MUTEX_STATIC_APP1;
}

int Sqlite3Wrapper::sqlite_mutex_static_app2(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_MUTEX_STATIC_APP2;
}

int Sqlite3Wrapper::sqlite_mutex_static_app3(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_MUTEX_STATIC_APP3;
}

int Sqlite3Wrapper::sqlite_mutex_static_vfs1(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_MUTEX_STATIC_VFS1;
}

int Sqlite3Wrapper::sqlite_mutex_static_vfs2(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_MUTEX_STATIC_VFS2;
}

int Sqlite3Wrapper::sqlite_mutex_static_vfs3(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_MUTEX_STATIC_VFS3;
}

int Sqlite3Wrapper::sqlite_mutex_static_master(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_MUTEX_STATIC_MASTER;
}

int Sqlite3Wrapper::file_control(const Ref<Sqlite3Handle>& db, const String& db_name, int op, int data) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_MISUSE);
    void *p_data = nullptr;
    int data_val = data;
    if (op == SQLITE_FCNTL_DATA_VERSION || op == SQLITE_FCNTL_PRAGMA || op == SQLITE_FCNTL_SIZE_HINT || op == SQLITE_FCNTL_CHUNK_SIZE || op == SQLITE_FCNTL_PERSIST_WAL || op == SQLITE_FCNTL_POWERSAFE_OVERWRITE || op == SQLITE_FCNTL_VFSNAME || op == SQLITE_FCNTL_RESERVE_BYTES || op == SQLITE_FCNTL_CKPT_DONE || op == SQLITE_FCNTL_CKPT_START || op == SQLITE_FCNTL_WIN32_SET_HANDLE || op == SQLITE_FCNTL_FILE_POINTER || op == SQLITE_FCNTL_JOURNAL_POINTER || op == SQLITE_FCNTL_VFS_POINTER) {
        p_data = &data_val;
    } else if (data != 0) {
        p_data = &data_val;
    } else {
        p_data = nullptr;
    }
    CharString dbname_cs = db_name.is_empty() ? CharString() : db_name.utf8();
    const char *z_dbname = db_name.is_empty() ? nullptr : dbname_cs.get_data();
    int rc = ::sqlite3_file_control(db->handle, z_dbname, (int)op, p_data);
    if (p_data == &data_val) {
        // If the opcode expects an out-param, update 'data' accordingly (not possible by value in Godot, document limitation).
    }
    return rc;
}

int Sqlite3Wrapper::test_control(int op, const Array& args) { // NOLINT(readability-convert-member-functions-to-static)
    switch (args.size()) {
        case 0:
            return ::sqlite3_test_control(op);
        case 1:
            if (args[0].get_type() == Variant::INT) {
                int arg0 = (int)args[0];
                return ::sqlite3_test_control(op, arg0);
            } else if (args[0].get_type() == Variant::STRING) {
                CharString cs = String(args[0]).utf8();
                return ::sqlite3_test_control(op, cs.get_data());
            } else {
                ERR_PRINT("sqlite3_test_control: Only int or String as single argument is supported.");
                return -1;
            }
        case 2:
            if (args[0].get_type() == Variant::INT && args[1].get_type() == Variant::INT) {
                int arg0 = (int)args[0];
                int arg1 = (int)args[1];
                return ::sqlite3_test_control(op, arg0, arg1);
            } else {
                ERR_PRINT("sqlite3_test_control: Only two int arguments supported.");
                return -1;
            }
        default:
            ERR_PRINT("sqlite3_test_control: Unsupported number or type of arguments.");
            return -1;
    }
}

String Sqlite3Wrapper::str_finish(const Ref<Sqlite3StrHandle>& str_handle) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(str_handle.is_null() || !str_handle->is_valid(), String());
    char *buf = ::sqlite3_str_finish(str_handle->handle);
    if (!buf) {
        return String();
    }
    String ret = String::utf8(buf);
    sqlite3_free(buf);
    return ret;
}

int Sqlite3Wrapper::dbstatus_lookaside_used(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DBSTATUS_LOOKASIDE_USED;
}

int Sqlite3Wrapper::dbstatus_cache_used(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DBSTATUS_CACHE_USED;
}

int Sqlite3Wrapper::dbstatus_schema_used(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DBSTATUS_SCHEMA_USED;
}

int Sqlite3Wrapper::dbstatus_stmt_used(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DBSTATUS_STMT_USED;
}

int Sqlite3Wrapper::dbstatus_lookaside_hit(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DBSTATUS_LOOKASIDE_HIT;
}

int Sqlite3Wrapper::dbstatus_lookaside_miss_size(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DBSTATUS_LOOKASIDE_MISS_SIZE;
}

int Sqlite3Wrapper::dbstatus_lookaside_miss_full(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DBSTATUS_LOOKASIDE_MISS_FULL;
}

int Sqlite3Wrapper::dbstatus_cache_hit(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DBSTATUS_CACHE_HIT;
}

int Sqlite3Wrapper::dbstatus_cache_miss(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DBSTATUS_CACHE_MISS;
}

int Sqlite3Wrapper::dbstatus_cache_write(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DBSTATUS_CACHE_WRITE;
}

int Sqlite3Wrapper::dbstatus_deferred_fks(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DBSTATUS_DEFERRED_FKS;
}

int Sqlite3Wrapper::dbstatus_cache_used_shared(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DBSTATUS_CACHE_USED_SHARED;
}

int Sqlite3Wrapper::dbstatus_cache_spill(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DBSTATUS_CACHE_SPILL;
}

int Sqlite3Wrapper::dbstatus_tempbuf_spill(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DBSTATUS_TEMPBUF_SPILL;
}

int Sqlite3Wrapper::dbstatus_max(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DBSTATUS_MAX;
}

int Sqlite3Wrapper::stmtstatus_fullscan_step(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_STMTSTATUS_FULLSCAN_STEP;
}

int Sqlite3Wrapper::stmtstatus_sort(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_STMTSTATUS_SORT;
}

int Sqlite3Wrapper::stmtstatus_autoindex(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_STMTSTATUS_AUTOINDEX;
}

int Sqlite3Wrapper::stmtstatus_vm_step(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_STMTSTATUS_VM_STEP;
}

int Sqlite3Wrapper::stmtstatus_reprepare(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_STMTSTATUS_REPREPARE;
}

int Sqlite3Wrapper::stmtstatus_run(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_STMTSTATUS_RUN;
}

int Sqlite3Wrapper::stmtstatus_filter_miss(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_STMTSTATUS_FILTER_MISS;
}

int Sqlite3Wrapper::stmtstatus_filter_hit(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_STMTSTATUS_FILTER_HIT;
}

int Sqlite3Wrapper::stmtstatus_memused(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_STMTSTATUS_MEMUSED;
}

int Sqlite3Wrapper::backup_pagecount(const Ref<Sqlite3BackupHandle>& p) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(p.is_null() || !p->is_valid(), -1);
    return ::sqlite3_backup_pagecount(p->handle);
}

int Sqlite3Wrapper::stricmp(const String& a, const String& b) { // NOLINT(readability-convert-member-functions-to-static)
    CharString cs1 = a.utf8();
    CharString cs2 = b.utf8();
    return ::sqlite3_stricmp(cs1.get_data(), cs2.get_data());
}

int Sqlite3Wrapper::wal_autocheckpoint(const Ref<Sqlite3Handle>& db, int N) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_MISUSE);
    return ::sqlite3_wal_autocheckpoint(db->handle, N);
}

int Sqlite3Wrapper::wal_checkpoint(const Ref<Sqlite3Handle>& db, const String& db_name) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    CharString db_name_utf8 = db_name.utf8();
    int rc = ::sqlite3_wal_checkpoint(db->handle, db_name_utf8.get_data());
    return rc;
}

Dictionary Sqlite3Wrapper::wal_checkpoint_v2(const Ref<Sqlite3Handle>& db, const String& z_db, int e_mode) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), Dictionary());
    int n_log = -1;
    int n_ckpt = -1;
    int result;
    if (z_db.is_empty()) {
        result = ::sqlite3_wal_checkpoint_v2(db->handle, nullptr, e_mode, &n_log, &n_ckpt);
    } else {
        CharString z_db_utf8 = z_db.utf8();
        result = ::sqlite3_wal_checkpoint_v2(db->handle, z_db_utf8.get_data(), e_mode, &n_log, &n_ckpt);
    }
    Dictionary out;
    out["result"] = result;
    out["n_log"] = n_log;
    out["n_ckpt"] = n_ckpt;
    return out;
}

int Sqlite3Wrapper::checkpoint_noop(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CHECKPOINT_NOOP;
}

int Sqlite3Wrapper::checkpoint_passive(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CHECKPOINT_PASSIVE;
}

int Sqlite3Wrapper::checkpoint_full(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CHECKPOINT_FULL;
}

int Sqlite3Wrapper::checkpoint_restart(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CHECKPOINT_RESTART;
}

int Sqlite3Wrapper::checkpoint_truncate(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CHECKPOINT_TRUNCATE;
}

int Sqlite3Wrapper::vtab_constraint_support(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_VTAB_CONSTRAINT_SUPPORT;
}

int Sqlite3Wrapper::vtab_innocuous(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_VTAB_INNOCUOUS;
}

int Sqlite3Wrapper::vtab_directonly(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_VTAB_DIRECTONLY;
}

int Sqlite3Wrapper::vtab_uses_all_schemas(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_VTAB_USES_ALL_SCHEMAS;
}

int Sqlite3Wrapper::vtab_nochange(const Ref<Sqlite3ContextHandle>& context) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(context.is_null() || !context->is_valid(), 0);
    return ::sqlite3_vtab_nochange(context->handle);
}

String Sqlite3Wrapper::vtab_collation(const Ref<Sqlite3IndexInfoHandle>& index_info, int idx) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(index_info.is_null() || !index_info->is_valid(), String());
    const char *result = ::sqlite3_vtab_collation(index_info->handle, idx);
    return String(result);
}

int Sqlite3Wrapper::vtab_rhs_value(const Ref<Sqlite3IndexInfoHandle>& info, int idx, const Ref<Sqlite3ValueHandle>& out_val) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(info.is_null() || !info->is_valid(), -1);
    ERR_FAIL_COND_V(out_val.is_null(), -1);
    sqlite3_value *val = nullptr;
    int result = ::sqlite3_vtab_rhs_value(info->handle, idx, &val);
    if (result == SQLITE_OK && val != nullptr) {
        out_val->set_handle(reinterpret_cast<intptr_t>(val));
    }
    return result;
}

#ifdef SQLITE_ENABLE_STMT_SCANSTATUS
Dictionary Sqlite3Wrapper::stmt_scanstatus_v2(const Ref<Sqlite3StmtHandle>& stmt, int idx, int scan_status_op, int flags) { // NOLINT(readability-convert-member-functions-to-static)
    Dictionary result;
    if (stmt.is_null() || !stmt->is_valid()) {
        result["status"] = -1;
        result["value"] = Variant();
        return result;
    }
    // See SQLite docs for scan_status_op meanings.
    // 0:NLOOP(int), 1:NVISIT(int), 2:EST(double), 3:NAME(string), 4:EXPLAIN(int), 5:SELECTID(int)
    int status = 0;
    Variant value;
    if (scan_status_op == 2) { // EST
        double double_val = 0.0;
        status = ::sqlite3_stmt_scanstatus_v2(stmt->handle, idx, scan_status_op, flags, &double_val);
        value = double_val;
    } else if (scan_status_op == 3) { // NAME
        const char *str_val = nullptr;
        status = ::sqlite3_stmt_scanstatus_v2(stmt->handle, idx, scan_status_op, flags, &str_val);
        value = str_val ? String::utf8(str_val) : String();
    } else {
        int int_val = 0;
        status = ::sqlite3_stmt_scanstatus_v2(stmt->handle, idx, scan_status_op, flags, &int_val);
        value = int_val;
    }
    result["status"] = status;
    result["value"] = value;
    return result;
}
#endif

#ifdef SQLITE_ENABLE_STMT_SCANSTATUS
void Sqlite3Wrapper::stmt_scanstatus_reset(const Ref<Sqlite3StmtHandle>& stmt) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND(stmt.is_null() || !stmt->is_valid());
    ::sqlite3_stmt_scanstatus_reset(stmt->handle);
}
#endif

int Sqlite3Wrapper::db_cacheflush(const Ref<Sqlite3Handle>& db) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_MISUSE);
    return ::sqlite3_db_cacheflush(db->handle);
}

#if defined(SQLITE_ENABLE_PREUPDATE_HOOK)
int64_t Sqlite3Wrapper::preupdate_hook(const Ref<Sqlite3Handle>& db, Callable on_preupdate) { // NOLINT(readability-convert-member-functions-to-static)
    // Only one hook per connection is allowed. We'll store the Callable inside a context struct.
    struct PreupdateCtx {
        Callable cb;
    };
    // Retrieve previous context (if any) from the database handle's metadata (not implemented here).
    static thread_local PreupdateCtx *prev_ctx = nullptr;
    PreupdateCtx *ctx = nullptr;
    if (on_preupdate.is_valid()) {
        ctx = memnew(PreupdateCtx);
        ctx->cb = on_preupdate;
    }
    auto trampoline = [](void *pCtx, sqlite3 *c_db, int op, const char *zDb, const char *zName, sqlite3_int64 iKey1, sqlite3_int64 iKey2) {
        PreupdateCtx *ctx = reinterpret_cast<PreupdateCtx *>(pCtx);
        if (!ctx || !ctx->cb.is_valid()) return;
        Ref<Sqlite3Handle> db_ref;
        db_ref.instantiate();
        db_ref->set_handle(reinterpret_cast<intptr_t>(c_db));
        Array args;
        args.push_back(db_ref);
        args.push_back((int64_t)op);
        args.push_back(zDb ? String::utf8(zDb) : String());
        args.push_back(zName ? String::utf8(zName) : String());
        args.push_back((int64_t)iKey1);
        args.push_back((int64_t)iKey2);
        ctx->cb.callv(args);
    };
    void *result = ::sqlite3_preupdate_hook(db->handle, ctx ? +trampoline : nullptr, ctx);
    // Clean up previous context if present and not null.
    if (prev_ctx && prev_ctx != ctx) {
        memdelete(prev_ctx);
    }
    prev_ctx = ctx;
    return reinterpret_cast<int64_t>(result);
}
#endif

#if defined(SQLITE_ENABLE_PREUPDATE_HOOK)
int Sqlite3Wrapper::preupdate_old(const Ref<Sqlite3Handle>& db, int64_t n, const Ref<Sqlite3ValueHandle>& out_value) { // NOLINT(readability-convert-member-functions-to-static)
    sqlite3_value *value = nullptr;
    int result = ::sqlite3_preupdate_old(db->handle, (int)n, &value);
    if (result == 0 && out_value.is_valid()) {
        out_value->set_handle(reinterpret_cast<intptr_t>(value));
    }
    return result;
}
#endif

#if defined(SQLITE_ENABLE_PREUPDATE_HOOK)
int Sqlite3Wrapper::preupdate_count(const Ref<Sqlite3Handle>& db) { // NOLINT(readability-convert-member-functions-to-static)
    return ::sqlite3_preupdate_count(db->handle);
}
#endif

#if defined(SQLITE_ENABLE_PREUPDATE_HOOK)
int Sqlite3Wrapper::preupdate_depth(const Ref<Sqlite3Handle>& db) { // NOLINT(readability-convert-member-functions-to-static)
    return ::sqlite3_preupdate_depth(db->handle);
}
#endif

#if defined(SQLITE_ENABLE_PREUPDATE_HOOK)
int Sqlite3Wrapper::preupdate_new(const Ref<Sqlite3Handle>& db, int64_t n, const Ref<Sqlite3ValueHandle>& out_value) { // NOLINT(readability-convert-member-functions-to-static)
    sqlite3_value *value = nullptr;
    int result = ::sqlite3_preupdate_new(db->handle, (int)n, &value);
    if (result == 0 && out_value.is_valid()) {
        out_value->set_handle(reinterpret_cast<intptr_t>(value));
    }
    return result;
}
#endif

#if defined(SQLITE_ENABLE_PREUPDATE_HOOK)
int Sqlite3Wrapper::preupdate_blobwrite(const Ref<Sqlite3Handle>& db) { // NOLINT(readability-convert-member-functions-to-static)
    return ::sqlite3_preupdate_blobwrite(db->handle);
}
#endif

int Sqlite3Wrapper::system_errno(const Ref<Sqlite3Handle>& db) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    return ::sqlite3_system_errno(db->handle);
}

#ifndef SQLITE_OMIT_DESERIALIZE
PackedByteArray Sqlite3Wrapper::serialize(const Ref<Sqlite3Handle>& db, const String& schema, int64_t flags) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), PackedByteArray());
    sqlite3_int64 size = 0;
    CharString schema_utf8 = schema.utf8();
    unsigned char *buf = ::sqlite3_serialize(db->handle, schema_utf8.get_data(), &size, static_cast<unsigned int>(flags));
    if (!buf || size <= 0) {
        return PackedByteArray();
    }
    PackedByteArray bytes;
    bytes.resize((int)size);
    memcpy(bytes.ptrw(), buf, (size_t)size);
    if ((flags & SQLITE_SERIALIZE_NOCOPY) == 0) {
        ::sqlite3_free(buf);
    }
    return bytes;
}
#endif

int Sqlite3Wrapper::serialize_nocopy(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_SERIALIZE_NOCOPY;
}

int Sqlite3Wrapper::deserialize_freeonclose(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DESERIALIZE_FREEONCLOSE;
}

int Sqlite3Wrapper::deserialize_resizeable(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DESERIALIZE_RESIZEABLE;
}

int Sqlite3Wrapper::deserialize_readonly(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_DESERIALIZE_READONLY;
}

int Sqlite3Wrapper::carray_bind(const Ref<Sqlite3StmtHandle>& stmt, int index, const PackedByteArray& data, int n_data, int flags) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), -1);
    ERR_FAIL_COND_V(data.is_empty(), -1);

    // The memory will be copied by SQLite if SQLITE_TRANSIENT is passed as the destructor.
    // Safe default: always use SQLITE_TRANSIENT for xDel.
    // If the user wants alternate behavior, a more advanced binding can be created.

    //return ::sqlite3_carray_bind(stmt->handle, index, (void*)data.ptr(), n_data, flags, SQLITE_TRANSIENT);
    (void)flags; // Suppress unused parameter warning since we're
    (void)data; // not currently using the flags parameter in this simplified implementation.
    (void)n_data; // Suppress unused parameter warning since n_data can be derived from data.size().
    (void)index; // Suppress unused parameter warning since this simplified implementation does not support indexed binding.
    return SQLITE_MISUSE; // Indicate misuse since this simplified version does not support the full functionality of sqlite3_carray_bind.
}

int Sqlite3Wrapper::sqlite_carray_int32(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CARRAY_INT32;
}

int Sqlite3Wrapper::sqlite_carray_int64(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CARRAY_INT64;
}

int Sqlite3Wrapper::sqlite_carray_double(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CARRAY_DOUBLE;
}

int Sqlite3Wrapper::sqlite_carray_text(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CARRAY_TEXT;
}

int Sqlite3Wrapper::sqlite_carray_blob(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CARRAY_BLOB;
}

int Sqlite3Wrapper::carray_int32(void) { // NOLINT(readability-convert-member-functions-to-static)
    return CARRAY_INT32;
}

int Sqlite3Wrapper::carray_int64(void) { // NOLINT(readability-convert-member-functions-to-static)
    return CARRAY_INT64;
}

int Sqlite3Wrapper::carray_double(void) { // NOLINT(readability-convert-member-functions-to-static)
    return CARRAY_DOUBLE;
}

int Sqlite3Wrapper::carray_text(void) { // NOLINT(readability-convert-member-functions-to-static)
    return CARRAY_TEXT;
}

int Sqlite3Wrapper::carray_blob(void) { // NOLINT(readability-convert-member-functions-to-static)
    return CARRAY_BLOB;
}

void Sqlite3Wrapper::session_delete(const Ref<Sqlite3SessionHandle>& p_session) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND(p_session.is_null() || !p_session->is_valid());
    ::sqlite3session_delete(p_session->handle);
    p_session->set_handle(0);
}

Ref<Sqlite3MutexHandle> Sqlite3Wrapper::mutex_alloc(int mutex_type) { // NOLINT(readability-convert-member-functions-to-static)
    sqlite3_mutex *ptr = ::sqlite3_mutex_alloc(mutex_type);
    Ref<Sqlite3MutexHandle> ref;
    if (ptr) {
        ref.instantiate();
        ref->set_handle(reinterpret_cast<intptr_t>(ptr));
    }
    return ref;
}

void Sqlite3Wrapper::str_appendf(const Ref<Sqlite3StrHandle>& str, const String& format, const Array& args) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND(str.is_null() || !str->is_valid());
    String formatted = format.format(args);
    CharString cstr = formatted.utf8();
    ::sqlite3_str_appendall(str->handle, cstr.get_data());
}

int Sqlite3Wrapper::str_errcode(const Ref<Sqlite3StrHandle>& x) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(x.is_null() || !x->is_valid(), SQLITE_NOMEM);
    return ::sqlite3_str_errcode(x->handle);
}

Dictionary Sqlite3Wrapper::status(int op, bool reset_flag) { // NOLINT(readability-convert-member-functions-to-static)
    int current = 0;
    int highwater = 0;
    int result = ::sqlite3_status(op, &current, &highwater, reset_flag ? 1 : 0);
    Dictionary d;
    d["result"] = result;
    d["current"] = current;
    d["highwater"] = highwater;
    return d;
}

Ref<Sqlite3BackupHandle> Sqlite3Wrapper::backup_init(const Ref<Sqlite3Handle>& p_dest, const String& z_dest_name, const Ref<Sqlite3Handle>& p_source, const String& z_source_name) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(p_dest.is_null() || !p_dest->is_valid(), Ref<Sqlite3BackupHandle>());
    ERR_FAIL_COND_V(p_source.is_null() || !p_source->is_valid(), Ref<Sqlite3BackupHandle>());
    CharString dest_name_cs = z_dest_name.utf8();
    CharString source_name_cs = z_source_name.utf8();
    sqlite3_backup *backup = ::sqlite3_backup_init(
        p_dest->handle,
        dest_name_cs.get_data(),
        p_source->handle,
        source_name_cs.get_data()
    );
    Ref<Sqlite3BackupHandle> out;
    if (backup) {
        out.instantiate();
        out->set_handle(reinterpret_cast<intptr_t>(backup));
    }
    return out;
}

#ifdef SQLITE_ENABLE_SNAPSHOT
int Sqlite3Wrapper::snapshot_open(const Ref<Sqlite3Handle>& db, const String& schema, const Ref<Sqlite3SnapshotHandle>& snapshot) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_ERROR);
    ERR_FAIL_COND_V(snapshot.is_null() || !snapshot->is_valid(), SQLITE_ERROR);
    godot::CharString cs = schema.utf8();
    int result = ::sqlite3_snapshot_open(db->handle, cs.get_data(), snapshot->handle);
    return result;
}
#endif

#ifdef SQLITE_ENABLE_SNAPSHOT
int Sqlite3Wrapper::snapshot_cmp(const Ref<Sqlite3SnapshotHandle>& p1, const Ref<Sqlite3SnapshotHandle>& p2) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(p1.is_null() || !p1->is_valid(), 0);
    ERR_FAIL_COND_V(p2.is_null() || !p2->is_valid(), 0);
    return ::sqlite3_snapshot_cmp(p1->handle, p2->handle);
}
#endif

#ifdef SQLITE_ENABLE_SNAPSHOT
int Sqlite3Wrapper::snapshot_recover(const Ref<Sqlite3Handle>& db, const String& z_db) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    CharString z_db_cstr = z_db.utf8();
    return ::sqlite3_snapshot_recover(db->handle, z_db_cstr.get_data());
}
#endif

int Sqlite3Wrapper::session_object_config(const Ref<Sqlite3SessionHandle>& session, int op, int p_arg) { // NOLINT(readability-convert-member-functions-to-static)
    return ::sqlite3session_object_config(session->handle, op, reinterpret_cast<void*>(p_arg));
}

int Sqlite3Wrapper::session_objconfig_size(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_SESSION_OBJCONFIG_SIZE;
}

int Sqlite3Wrapper::session_objconfig_rowid(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_SESSION_OBJCONFIG_ROWID;
}

int Sqlite3Wrapper::session_indirect(const Ref<Sqlite3SessionHandle>& session, int b_indirect) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(session.is_null() || !session->is_valid(), -1);
    return ::sqlite3session_indirect(session->handle, b_indirect);
}

int Sqlite3Wrapper::session_attach(const Ref<Sqlite3SessionHandle>& p_session, const String& z_tab) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(p_session.is_null() || !p_session->is_valid(), -1);
    CharString c_zTab = z_tab.utf8();
    const char *cstr = (z_tab.is_empty()) ? nullptr : c_zTab.get_data();
    return ::sqlite3session_attach(p_session->handle, cstr);
}

void Sqlite3Wrapper::session_table_filter(const Ref<Sqlite3SessionHandle>& session, Callable filter) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND(session.is_null() || !session->is_valid());
    ERR_FAIL_COND(!filter.is_valid());

    struct _TableFilterCtx {
        Callable cb;
    };

    _TableFilterCtx *ctx = memnew(_TableFilterCtx);
    ctx->cb = filter;

    auto trampoline = [](void *pCtx, const char *zTab) -> int {
        _TableFilterCtx *ctx = reinterpret_cast<_TableFilterCtx *>(pCtx);
        String table_name = zTab ? String::utf8(zTab) : String();
        Array args;
        args.push_back(table_name);
        Variant ret = ctx->cb.callv(args);
        if (ret.get_type() != Variant::INT) {
            ERR_PRINT("session_table_filter Callable must return int, got: " + ret.stringify() + " (" + Variant::get_type_name(ret.get_type()) + ")");
            return 0;
        }
        return int(ret);
    };

    ::sqlite3session_table_filter(session->handle, trampoline, ctx);
}

Dictionary Sqlite3Wrapper::session_changeset(const Ref<Sqlite3SessionHandle>& session) { // NOLINT(readability-convert-member-functions-to-static)
    Dictionary dict;
    if (session.is_null() || !session->is_valid()) {
        dict["error"] = SQLITE_MISUSE;
        dict["changeset"] = PackedByteArray();
        return dict;
    }
    int n = 0;
    void *buf = nullptr;
    int rc = ::sqlite3session_changeset(session->handle, &n, &buf);
    PackedByteArray arr;
    if (rc == SQLITE_OK && n > 0 && buf != nullptr) {
        arr.resize(n);
        memcpy(arr.ptrw(), buf, n);
        ::sqlite3_free(buf);
    }
    dict["error"] = rc;
    dict["changeset"] = arr;
    return dict;
}

int64_t Sqlite3Wrapper::changeset_size(const Ref<Sqlite3SessionHandle>& session) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(session.is_null() || !session->is_valid(), 0);
    return (int64_t)::sqlite3session_changeset_size(session->handle);
}

Dictionary Sqlite3Wrapper::session_diff(const Ref<Sqlite3SessionHandle>& p_session, const String& from_db, const String& table) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(p_session.is_null() || !p_session->is_valid(), Dictionary());
    CharString from_db_cs = from_db.utf8();
    CharString table_cs = table.utf8();
    char *errmsg = nullptr;
    int result = ::sqlite3session_diff(p_session->handle, from_db_cs.get_data(), table_cs.get_data(), &errmsg);
    String error_message;
    if (errmsg != nullptr) {
        error_message = String(errmsg);
        ::sqlite3_free(errmsg);
    } else {
        error_message = String("");
    }
    Dictionary dict;
    dict["result"] = result;
    dict["error_message"] = error_message;
    return dict;
}

Dictionary Sqlite3Wrapper::session_patchset(const Ref<Sqlite3SessionHandle>& session) { // NOLINT(readability-convert-member-functions-to-static)
    Dictionary result;
    result["code"] = SQLITE_MISUSE;
    result["patchset"] = PackedByteArray();
    if (session.is_null() || !session->is_valid()) {
        return result;
    }
    void *patchset = nullptr;
    int patchset_size = 0;
    int rc = ::sqlite3session_patchset(session->handle, &patchset_size, &patchset);
    result["code"] = rc;
    PackedByteArray arr;
    if (rc == SQLITE_OK && patchset != nullptr && patchset_size > 0) {
        arr.resize(patchset_size);
        memcpy(arr.ptrw(), patchset, patchset_size);
        ::sqlite3_free(patchset);
    }
    result["patchset"] = arr;
    return result;
}

int Sqlite3Wrapper::is_empty(const Ref<Sqlite3SessionHandle>& p_session) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(p_session.is_null() || !p_session->is_valid(), 0);
    return ::sqlite3session_isempty(p_session->handle);
}

int Sqlite3Wrapper::changeset_start(const Ref<Sqlite3ChangesetIterHandle>& out_iter, const PackedByteArray& changeset_blob) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(out_iter.is_null(), SQLITE_MISUSE);
    ERR_FAIL_COND_V(changeset_blob.is_empty(), SQLITE_MISUSE);

    sqlite3_changeset_iter *iter = nullptr;
    int result = ::sqlite3changeset_start(&iter, changeset_blob.size(), (void *)changeset_blob.ptr());
    if (result == SQLITE_OK && iter != nullptr) {
        out_iter->set_handle(reinterpret_cast<intptr_t>(iter));
    }
    return result;
}

int Sqlite3Wrapper::changesetstart_invert(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CHANGESETSTART_INVERT;
}

Dictionary Sqlite3Wrapper::changeset_op(const Ref<Sqlite3ChangesetIterHandle>& iter, bool request_indirect) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(iter.is_null() || !iter->is_valid(), Dictionary());

    const char *zTab = nullptr;
    int nCol = 0;
    int op = 0;
    int indirect = 0;

    int rc = ::sqlite3changeset_op(iter->handle, &zTab, &nCol, &op, request_indirect ? &indirect : nullptr);

    Dictionary result;
    result["error"] = rc;
    if (rc == SQLITE_OK) {
        result["table"] = zTab ? String::utf8(zTab) : String();
        result["column_count"] = nCol;
        result["operation"] = op;
        if (request_indirect) {
            result["indirect"] = bool(indirect);
        }
    }
    return result;
}

Dictionary Sqlite3Wrapper::pk(const Ref<Sqlite3ChangesetIterHandle>& iter) { // NOLINT(readability-convert-member-functions-to-static)
    Dictionary result_dict;
    if (iter.is_null() || !iter->is_valid()) {
        result_dict["result"] = SQLITE_MISUSE;
        result_dict["pk"] = PackedByteArray();
        result_dict["ncol"] = 0;
        return result_dict;
    }
    unsigned char *pab_pk = nullptr;
    int ncol = 0;
    int rc = ::sqlite3changeset_pk(iter->handle, &pab_pk, &ncol);
    PackedByteArray pk_array;
    if (rc == SQLITE_OK && pab_pk && ncol > 0) {
        pk_array.resize(ncol);
        memcpy(pk_array.ptrw(), pab_pk, ncol);
    } else {
        ncol = 0;
    }
    result_dict["result"] = rc;
    result_dict["pk"] = pk_array;
    result_dict["ncol"] = ncol;
    return result_dict;
}

int Sqlite3Wrapper::changeset_old(const Ref<Sqlite3ChangesetIterHandle>& p_iter, int i_val, const Ref<Sqlite3ValueHandle>& out_value) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(p_iter.is_null() || !p_iter->is_valid(), SQLITE_MISUSE);
    ERR_FAIL_COND_V(out_value.is_null(), SQLITE_MISUSE);
    sqlite3_value *val_ptr = nullptr;
    int result = ::sqlite3changeset_old(p_iter->handle, i_val, &val_ptr);
    if (result == SQLITE_OK && val_ptr) {
        out_value->set_handle(reinterpret_cast<intptr_t>(val_ptr));
    }
    return result;
}

int Sqlite3Wrapper::changeset_new(const Ref<Sqlite3ChangesetIterHandle>& p_iter, int i_val, const Ref<Sqlite3ValueHandle>& out_value) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(p_iter.is_null() || !p_iter->is_valid(), SQLITE_MISUSE);
    ERR_FAIL_COND_V(out_value.is_null(), SQLITE_MISUSE);

    sqlite3_value *c_value = nullptr;
    int result = ::sqlite3changeset_new(p_iter->handle, i_val, &c_value);
    if (result == SQLITE_OK && c_value != nullptr) {
        out_value->set_handle(reinterpret_cast<intptr_t>(c_value));
    }
    return result;
}

int Sqlite3Wrapper::changeset_conflict(const Ref<Sqlite3ChangesetIterHandle>& p_iter, int i_val, const Ref<Sqlite3ValueHandle>& out_value) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(p_iter.is_null() || !p_iter->is_valid(), SQLITE_MISUSE);
    ERR_FAIL_COND_V(out_value.is_null(), SQLITE_MISUSE);
    sqlite3_value *value = nullptr;
    int rc = ::sqlite3changeset_conflict(p_iter->handle, i_val, &value);
    if (rc == SQLITE_OK && value) {
        out_value->set_handle(reinterpret_cast<intptr_t>(value));
    }
    return rc;
}

Dictionary Sqlite3Wrapper::fk_conflicts(const Ref<Sqlite3ChangesetIterHandle>& iter) { // NOLINT(readability-convert-member-functions-to-static)
    int n = 0;
    int rc = ::sqlite3changeset_fk_conflicts(iter->handle, &n);
    Dictionary d;
    d["result"] = rc;
    d["fk_violations"] = n;
    return d;
}

Dictionary Sqlite3Wrapper::changeset_invert(const PackedByteArray& input) { // NOLINT(readability-convert-member-functions-to-static)
    Dictionary result;
    int nIn = input.size();
    const uint8_t *pIn = input.ptr();
    int pnOut = 0;
    void *ppOut = nullptr;
    int rc = ::sqlite3changeset_invert(nIn, pIn, &pnOut, &ppOut);
    PackedByteArray inverted;
    if (rc == SQLITE_OK && pnOut > 0 && ppOut != nullptr) {
        inverted.resize(pnOut);
        std::memcpy(inverted.ptrw(), ppOut, pnOut);
        ::sqlite3_free(ppOut);
    }
    result["error"] = rc;
    result["inverted"] = inverted;
    return result;
}

int Sqlite3Wrapper::changegroup_schema(const Ref<Sqlite3ChangegroupHandle>& changegroup, const Ref<Sqlite3Handle>& db, const String& db_name) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(changegroup.is_null() || !changegroup->is_valid(), -1);
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    CharString db_name_utf8 = db_name.utf8();
    return ::sqlite3changegroup_schema(changegroup->handle, db->handle, db_name_utf8.get_data());
}

int Sqlite3Wrapper::changegroup_add(const Ref<Sqlite3ChangegroupHandle>& changegroup, const PackedByteArray& data) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(changegroup.is_null() || !changegroup->is_valid(), SQLITE_ERROR);
    int result = ::sqlite3changegroup_add(changegroup->handle, data.size(), data.size() ? (void *)data.ptr() : nullptr);
    return result;
}

int Sqlite3Wrapper::add_change(const Ref<Sqlite3ChangegroupHandle>& changegroup, const Ref<Sqlite3ChangesetIterHandle>& iter) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(changegroup.is_null() || !changegroup->is_valid(), SQLITE_ERROR);
    ERR_FAIL_COND_V(iter.is_null() || !iter->is_valid(), SQLITE_ERROR);
    return ::sqlite3changegroup_add_change(changegroup->handle, iter->handle);
}

PackedByteArray Sqlite3Wrapper::changegroup_output(const Ref<Sqlite3ChangegroupHandle>& group) { // NOLINT(readability-convert-member-functions-to-static)
    PackedByteArray result;
    ERR_FAIL_COND_V(group.is_null() || !group->is_valid(), result);
    int nData = 0;
    void *pData = nullptr;
    int rc = ::sqlite3changegroup_output(group->handle, &nData, &pData);
    if (rc == SQLITE_OK && pData && nData > 0) {
        result.resize(nData);
        memcpy(result.ptrw(), pData, nData);
        ::sqlite3_free(pData);
    } else {
        if (pData) {
            ::sqlite3_free(pData);
        }
        result.clear();
    }
    return result;
}

int Sqlite3Wrapper::changeset_apply(const Ref<Sqlite3Handle>& db, const PackedByteArray& changeset, Callable filter, Callable conflict) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_MISUSE);
    ERR_FAIL_COND_V(!conflict.is_valid(), SQLITE_MISUSE);
    ERR_FAIL_COND_V(changeset.is_empty(), SQLITE_MISUSE);

    struct _Ctx {
        Callable filter;
        Callable conflict;
    } ctx { filter, conflict };

    auto xFilter = [](void *pCtx, const char *zTab) -> int {
        _Ctx *ctx = reinterpret_cast<_Ctx *>(pCtx);
        if (!ctx->filter.is_valid())
            return 1;
        Array args;
        args.push_back(zTab ? String::utf8(zTab) : String());
        Variant ret = ctx->filter.callv(args);
        if (ret.get_type() != Variant::INT) {
            ERR_PRINT("filter callback must return int, got: " + ret.stringify());
            return 1;
        }
        return int(ret);
    };

    auto xConflict = [](void *pCtx, int eConflict, sqlite3_changeset_iter *p) -> int {
        _Ctx *ctx = reinterpret_cast<_Ctx *>(pCtx);
        if (!ctx->conflict.is_valid())
            return SQLITE_CHANGESET_ABORT;
        Ref<Sqlite3ChangesetIterHandle> iter;
        iter.instantiate();
        iter->set_handle(reinterpret_cast<intptr_t>(p));
        Array args;
        args.push_back(int64_t(eConflict));
        args.push_back(iter);
        Variant ret = ctx->conflict.callv(args);
        if (ret.get_type() != Variant::INT) {
            ERR_PRINT("conflict callback must return int, got: " + ret.stringify());
            return SQLITE_CHANGESET_ABORT;
        }
        return int(ret);
    };

    int result = ::sqlite3changeset_apply(
        db->handle,
        static_cast<int>(changeset.size()),
        (void *)changeset.ptr(),
        filter.is_valid() ? +xFilter : nullptr,
        xConflict,
        &ctx);
    return result;
}

Dictionary Sqlite3Wrapper::changeset_apply_v2(const Ref<Sqlite3Handle>& db, const PackedByteArray& changeset_blob, Callable x_filter, Callable x_conflict, int64_t flags) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), Dictionary());
    ERR_FAIL_COND_V(!x_filter.is_valid(), Dictionary());
    ERR_FAIL_COND_V(!x_conflict.is_valid(), Dictionary());

    struct _ApplyCtx {
        Callable filter;
        Callable conflict;
    };
    _ApplyCtx ctx { x_filter, x_conflict };

    auto trampoline_filter = [](void *pCtx, const char *zTab) -> int {
        _ApplyCtx *ctx = reinterpret_cast<_ApplyCtx *>(pCtx);
        Array args;
        args.push_back(String(zTab ? zTab : ""));
        Variant ret = ctx->filter.callv(args);
        if (ret.get_type() != Variant::INT) {
            ERR_PRINT("x_filter must return int, but got: " + ret.stringify() + " (" + Variant::get_type_name(ret.get_type()) + ")");
            return 0;
        }
        return int(ret);
    };

    auto trampoline_conflict = [](void *pCtx, int eConflict, sqlite3_changeset_iter *p) -> int {
        _ApplyCtx *ctx = reinterpret_cast<_ApplyCtx *>(pCtx);
        Ref<Sqlite3ChangesetIterHandle> iter;
        iter.instantiate();
        iter->set_handle(reinterpret_cast<intptr_t>(p));
        Array args;
        args.push_back(int64_t(eConflict));
        args.push_back(iter);
        Variant ret = ctx->conflict.callv(args);
        if (ret.get_type() != Variant::INT) {
            ERR_PRINT("x_conflict must return int, but got: " + ret.stringify() + " (" + Variant::get_type_name(ret.get_type()) + ")");
            return 0;
        }
        return int(ret);
    };

    const int nChangeset = (int)changeset_blob.size();
    const void *pChangeset = changeset_blob.size() > 0 ? changeset_blob.ptr() : nullptr;
    void *pRebase = nullptr;
    int nRebase = 0;

    int result = ::sqlite3changeset_apply_v2(
        db->handle,
        nChangeset,
        const_cast<void *>(pChangeset),
        trampoline_filter,
        trampoline_conflict,
        &ctx,
        &pRebase,
        &nRebase,
        (int)flags
    );

    PackedByteArray rebase_blob;
    if (pRebase != nullptr && nRebase > 0) {
        rebase_blob.resize(nRebase);
        memcpy(rebase_blob.ptrw(), pRebase, nRebase);
        ::sqlite3_free(pRebase);
    }
    Dictionary ret_dict;
    ret_dict["result"] = result;
    ret_dict["rebase"] = rebase_blob;
    return ret_dict;
}

Dictionary Sqlite3Wrapper::changeset_apply_v3(const Ref<Sqlite3Handle>& db, const PackedByteArray& changeset, Callable x_filter, Callable x_conflict, int flags) { // NOLINT(readability-convert-member-functions-to-static)
    Dictionary result_dict;
    PackedByteArray rebase;

    if (db.is_null() || !db->is_valid()) {
        result_dict["result"] = SQLITE_MISUSE;
        result_dict["rebase"] = rebase;
        return result_dict;
    }
    if (!x_filter.is_valid() || !x_conflict.is_valid()) {
        result_dict["result"] = SQLITE_MISUSE;
        result_dict["rebase"] = rebase;
        return result_dict;
    }

    struct _Ctx {
        Callable filter;
        Callable conflict;
    } ctx{x_filter, x_conflict};

    auto filter_trampoline = [](void *pCtx, sqlite3_changeset_iter *p) -> int {
        _Ctx *ctx = reinterpret_cast<_Ctx *>(pCtx);
        Ref<Sqlite3ChangesetIterHandle> iter_handle;
        iter_handle.instantiate();
        iter_handle->set_handle(reinterpret_cast<intptr_t>(p));
        Variant ret = ctx->filter.call(iter_handle);
        if (ret.get_type() != Variant::INT) {
            ERR_PRINT("x_filter must return int, got: " + ret.stringify());
            return 0;
        }
        return int(ret);
    };

    auto conflict_trampoline = [](void *pCtx, int eConflict, sqlite3_changeset_iter *p) -> int {
        _Ctx *ctx = reinterpret_cast<_Ctx *>(pCtx);
        Ref<Sqlite3ChangesetIterHandle> iter_handle;
        iter_handle.instantiate();
        iter_handle->set_handle(reinterpret_cast<intptr_t>(p));
        Variant ret = ctx->conflict.call(eConflict, iter_handle);
        if (ret.get_type() != Variant::INT) {
            ERR_PRINT("x_conflict must return int, got: " + ret.stringify());
            return 0;
        }
        return int(ret);
    };

    void *rebase_ptr = nullptr;
    int rebase_size = 0;

    int result = ::sqlite3changeset_apply_v3(
        db->handle,
        changeset.size(),
        changeset.size() > 0 ? (void*)changeset.ptr() : nullptr,
        filter_trampoline,
        conflict_trampoline,
        &ctx,
        &rebase_ptr,
        &rebase_size,
        flags
    );

    if (result == SQLITE_OK && rebase_ptr && rebase_size > 0) {
        rebase.resize(rebase_size);
        memcpy(rebase.ptrw(), rebase_ptr, rebase_size);
        sqlite3_free(rebase_ptr);
    } else if (rebase_ptr) {
        sqlite3_free(rebase_ptr);
    }

    result_dict["result"] = result;
    result_dict["rebase"] = rebase;
    return result_dict;
}

int Sqlite3Wrapper::changesetapply_nosavepoint_flag(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CHANGESETAPPLY_NOSAVEPOINT;
}

int Sqlite3Wrapper::changesetapply_invert_flag(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CHANGESETAPPLY_INVERT;
}

int Sqlite3Wrapper::changesetapply_ignorenoop_flag(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CHANGESETAPPLY_IGNORENOOP;
}

int Sqlite3Wrapper::changesetapply_fknoaction_flag(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CHANGESETAPPLY_FKNOACTION;
}

int Sqlite3Wrapper::changeset_data_type(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CHANGESET_DATA;
}

int Sqlite3Wrapper::changeset_notfound_type(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CHANGESET_NOTFOUND;
}

int Sqlite3Wrapper::changeset_conflict_type(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CHANGESET_CONFLICT;
}

int Sqlite3Wrapper::changeset_constraint_type(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CHANGESET_CONSTRAINT;
}

int Sqlite3Wrapper::changeset_foreign_key_type(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CHANGESET_FOREIGN_KEY;
}

int Sqlite3Wrapper::changeset_omit_result(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CHANGESET_OMIT;
}

int Sqlite3Wrapper::changeset_replace_result(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CHANGESET_REPLACE;
}

int Sqlite3Wrapper::changeset_abort_result(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_CHANGESET_ABORT;
}

Dictionary Sqlite3Wrapper::rebase(const Ref<Sqlite3RebaserHandle>& rebaser, const PackedByteArray& input) { // NOLINT(readability-convert-member-functions-to-static)
    Dictionary result;
    if (rebaser.is_null() || !rebaser->is_valid()) {
        result["error"] = -1;
        result["buffer"] = PackedByteArray();
        return result;
    }
    int n_in = input.size();
    const uint8_t *p_in = input.ptr();
    int n_out = 0;
    void *p_out = nullptr;
    int rc = ::sqlite3rebaser_rebase(rebaser->handle, n_in, p_in, &n_out, &p_out);
    PackedByteArray out_buffer;
    if (rc == SQLITE_OK && p_out != nullptr && n_out > 0) {
        out_buffer.resize(n_out);
        memcpy(out_buffer.ptrw(), p_out, n_out);
        ::sqlite3_free(p_out);
    } else {
        if (p_out) {
            ::sqlite3_free(p_out);
        }
        out_buffer.clear();
    }
    result["error"] = rc;
    result["buffer"] = out_buffer;
    return result;
}

int Sqlite3Wrapper::changeset_apply_strm(const Ref<Sqlite3Handle>& db, Callable x_input, const Variant& input_ctx, Callable x_filter, Callable x_conflict, const Variant& conflict_ctx) { // NOLINT(readability-convert-member-functions-to-static)
    // Validate arguments
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_MISUSE);
    ERR_FAIL_COND_V(!x_input.is_valid(), SQLITE_MISUSE);
    ERR_FAIL_COND_V(!x_conflict.is_valid(), SQLITE_MISUSE);

    struct InputContext {
        Callable cb;
        Variant ctx;
    };
    struct ConflictFilterContext {
        Callable filter_cb;
        Callable conflict_cb;
        Variant ctx;
    };

    InputContext input_ctx_struct{x_input, input_ctx};
    ConflictFilterContext cf_ctx_struct{x_filter, x_conflict, conflict_ctx};

    // xInput trampoline
    auto xInput = [](void *pIn, void *pData, int *pnData) -> int {
        InputContext *ictx = reinterpret_cast<InputContext *>(pIn);
        int req_size = *pnData;
        PackedByteArray buffer;
        if (req_size > 0)
            buffer.resize(req_size);
        Array args;
        args.push_back(ictx->ctx);
        args.push_back(buffer);
        Variant ret = ictx->cb.callv(args);
        if (ret.get_type() != Variant::PACKED_BYTE_ARRAY) {
            ERR_PRINT("x_input must return PackedByteArray");
            *pnData = 0;
            return SQLITE_ERROR;
        }
        PackedByteArray out_bytes = ret;
        int to_copy = MIN(out_bytes.size(), req_size);
        if (to_copy > 0)
            memcpy(pData, out_bytes.ptr(), to_copy);
        *pnData = to_copy;
        return (to_copy == 0) ? SQLITE_OK : SQLITE_OK; // Zero means EOF, but still OK
    };

    // xFilter trampoline
    int (*xFilterPtr)(void *, const char *) = nullptr;
    if (x_filter.is_valid()) {
        xFilterPtr = [](void *pCtx, const char *zTab) -> int {
            ConflictFilterContext *ctx = reinterpret_cast<ConflictFilterContext *>(pCtx);
            if (!ctx->filter_cb.is_valid()) return 1; // Default: apply
            Array args;
            args.push_back(ctx->ctx);
            args.push_back(String::utf8(zTab));
            Variant ret = ctx->filter_cb.callv(args);
            if (ret.get_type() != Variant::INT) return 1;
            return int(ret);
        };
    }

    // xConflict trampoline
    auto xConflict = [](void *pCtx, int eConflict, sqlite3_changeset_iter *p) -> int {
        ConflictFilterContext *ctx = reinterpret_cast<ConflictFilterContext *>(pCtx);
        if (!ctx->conflict_cb.is_valid()) return SQLITE_ERROR;
        Ref<Sqlite3ChangesetIterHandle> iter;
        iter.instantiate();
        iter->set_handle(reinterpret_cast<intptr_t>(p));
        Array args;
        args.push_back(ctx->ctx);
        args.push_back(eConflict);
        args.push_back(iter);
        Variant ret = ctx->conflict_cb.callv(args);
        if (ret.get_type() != Variant::INT) return SQLITE_ERROR;
        return int(ret);
    };

    int result = ::sqlite3changeset_apply_strm(
        db->handle,
        xInput,
        &input_ctx_struct,
        xFilterPtr,
        xConflict,
        &cf_ctx_struct
    );
    return result;
}

Dictionary Sqlite3Wrapper::changeset_apply_v2_strm(const Ref<Sqlite3Handle>& db, Callable x_input, Callable x_filter, Callable x_conflict, int flags) { // NOLINT(readability-convert-member-functions-to-static)
    Dictionary result;
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), result);
    ERR_FAIL_COND_V(!x_input.is_valid(), result);
    ERR_FAIL_COND_V(!x_filter.is_valid(), result);
    ERR_FAIL_COND_V(!x_conflict.is_valid(), result);
    struct _Ctx {
        Callable x_input;
        Callable x_filter;
        Callable x_conflict;
    } ctx{x_input, x_filter, x_conflict};

    // xInput trampoline
    auto xInput_trampoline = [](void *pIn, void *pData, int *pnData) -> int {
        _Ctx *ctx = reinterpret_cast<_Ctx *>(pIn);
        int requested_size = *pnData;
        Array args;
        args.push_back(requested_size);
        Variant ret = ctx->x_input.callv(args);
        if (ret.get_type() != Variant::PACKED_BYTE_ARRAY) {
            ERR_PRINT("x_input must return PackedByteArray. Got: " + ret.stringify() + " (" + Variant::get_type_name(ret.get_type()) + ")");
            *pnData = 0;
            return -1;
        }
        PackedByteArray arr = ret;
        int to_copy = MIN(requested_size, arr.size());
        if (to_copy > 0) {
            memcpy(pData, arr.ptr(), to_copy);
        }
        *pnData = to_copy;
        return 0;
    };

    // xFilter trampoline
    auto xFilter_trampoline = [](void *pCtx, const char *zTab) -> int {
        _Ctx *ctx = reinterpret_cast<_Ctx *>(pCtx);
        Array args;
        args.push_back(String::utf8(zTab));
        Variant ret = ctx->x_filter.callv(args);
        if (ret.get_type() != Variant::INT) {
            ERR_PRINT("x_filter must return int. Got: " + ret.stringify() + " (" + Variant::get_type_name(ret.get_type()) + ")");
            return 0;
        }
        return int(ret);
    };

    // xConflict trampoline
    auto xConflict_trampoline = [](void *pCtx, int eConflict, sqlite3_changeset_iter *p) -> int {
        _Ctx *ctx = reinterpret_cast<_Ctx *>(pCtx);
        Ref<Sqlite3ChangesetIterHandle> iter;
        iter.instantiate();
        iter->set_handle(reinterpret_cast<intptr_t>(p));
        Array args;
        args.push_back(eConflict);
        args.push_back(iter);
        Variant ret = ctx->x_conflict.callv(args);
        if (ret.get_type() != Variant::INT) {
            ERR_PRINT("x_conflict must return int. Got: " + ret.stringify() + " (" + Variant::get_type_name(ret.get_type()) + ")");
            return 0;
        }
        return int(ret);
    };

    void *pRebase = nullptr;
    int nRebase = 0;
    int rc = ::sqlite3changeset_apply_v2_strm(
        db->handle,
        xInput_trampoline, &ctx,
        xFilter_trampoline,
        xConflict_trampoline, &ctx,
        &pRebase, &nRebase,
        flags
    );
    PackedByteArray rebase;
    if (rc == 0 && pRebase && nRebase > 0) {
        rebase.resize(nRebase);
        memcpy(rebase.ptrw(), pRebase, nRebase);
        // The library may expect us to free pRebase with sqlite3_free (not handled here)
    }
    result["error"] = rc;
    result["rebase"] = rebase;
    return result;
}

Dictionary Sqlite3Wrapper::changeset_apply_v3_strm(const Ref<Sqlite3Handle>& db, Callable x_input, Callable x_filter, Callable x_conflict, int flags) { // NOLINT(readability-convert-member-functions-to-static)
    // Validate arguments
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), Dictionary());
    ERR_FAIL_COND_V(!x_input.is_valid(), Dictionary());
    ERR_FAIL_COND_V(!x_filter.is_valid(), Dictionary());
    ERR_FAIL_COND_V(!x_conflict.is_valid(), Dictionary());

    struct _ApplyV3Ctx {
        Callable x_input;
        Callable x_filter;
        Callable x_conflict;
    };
    _ApplyV3Ctx *ctx = memnew(_ApplyV3Ctx);
    ctx->x_input = x_input;
    ctx->x_filter = x_filter;
    ctx->x_conflict = x_conflict;

    // xInput trampoline
    auto input_trampoline = [](void *pIn, void *pData, int *pnData) -> int {
        _ApplyV3Ctx *ctx = reinterpret_cast<_ApplyV3Ctx *>(pIn);
        if (!ctx || !ctx->x_input.is_valid() || !pnData || !pData) {
            ERR_PRINT("Invalid input_trampoline context or arguments");
            return -1;
        }
        // Prepare arguments for Callable: buffer size
        int buf_size = *pnData;
        Array args;
        args.push_back(buf_size);
        Variant ret = ctx->x_input.callv(args);
        if (ret.get_type() != Variant::DICTIONARY) {
            ERR_PRINT("x_input must return a Dictionary {buffer: PackedByteArray, result: int}");
            return -1;
        }
        Dictionary d = ret;
        if (!d.has("buffer") || !d.has("result")) {
            ERR_PRINT("x_input Dictionary must have 'buffer' and 'result' keys");
            return -1;
        }
        PackedByteArray buffer = d["buffer"];
        int result = int(d["result"]);
        int to_copy = (int)MIN((int64_t)buffer.size(), (int64_t)buf_size);
        std::memcpy(pData, buffer.ptr(), to_copy);
        *pnData = to_copy;
        return result;
    };

    // xFilter trampoline
    auto filter_trampoline = [](void *pCtx, struct sqlite3_changeset_iter *p) -> int {
        _ApplyV3Ctx *ctx = reinterpret_cast<_ApplyV3Ctx *>(pCtx);
        if (!ctx || !ctx->x_filter.is_valid()) {
            ERR_PRINT("Invalid filter_trampoline context or Callable");
            return 0;
        }
        Ref<Sqlite3ChangesetIterHandle> iter;
        iter.instantiate();
        iter->set_handle(reinterpret_cast<intptr_t>(p));
        Array args;
        args.push_back(iter);
        Variant ret = ctx->x_filter.callv(args);
        if (ret.get_type() != Variant::INT) {
            ERR_PRINT("x_filter must return int");
            return 0;
        }
        return int(ret);
    };

    // xConflict trampoline
    auto conflict_trampoline = [](void *pCtx, int eConflict, struct sqlite3_changeset_iter *p) -> int {
        _ApplyV3Ctx *ctx = reinterpret_cast<_ApplyV3Ctx *>(pCtx);
        if (!ctx || !ctx->x_conflict.is_valid()) {
            ERR_PRINT("Invalid conflict_trampoline context or Callable");
            return SQLITE_CHANGESET_ABORT;
        }
        Ref<Sqlite3ChangesetIterHandle> iter;
        iter.instantiate();
        iter->set_handle(reinterpret_cast<intptr_t>(p));
        Array args;
        args.push_back(eConflict);
        args.push_back(iter);
        Variant ret = ctx->x_conflict.callv(args);
        if (ret.get_type() != Variant::INT) {
            ERR_PRINT("x_conflict must return int");
            return SQLITE_CHANGESET_ABORT;
        }
        return int(ret);
    };

    // Prepare rebase output
    void *p_rebase = nullptr;
    int n_rebase = 0;
    int result = ::sqlite3changeset_apply_v3_strm(
        db->handle,
        input_trampoline,
        ctx,
        filter_trampoline,
        conflict_trampoline,
        ctx,
        &p_rebase, &n_rebase,
        flags
    );

    Dictionary out;
    out["result"] = result;
    if (result == SQLITE_OK && p_rebase && n_rebase > 0) {
        PackedByteArray rebase;
        rebase.resize(n_rebase);
        std::memcpy(rebase.ptrw(), p_rebase, n_rebase);
        out["rebase"] = rebase;
        sqlite3_free(p_rebase);
    } else {
        out["rebase"] = Variant();
    }
    memdelete(ctx);
    return out;
}

int Sqlite3Wrapper::changeset_invert_strm(Callable x_input, Callable x_output) { // NOLINT(readability-convert-member-functions-to-static)
    // Context for the input callback
    struct _InputCtx {
        Callable cb;
    } input_ctx{x_input};

    // Context for the output callback
    struct _OutputCtx {
        Callable cb;
    } output_ctx{x_output};

    // Trampoline for xInput: reads up to *pnData bytes into pData; user callable should return PackedByteArray.
    auto xInput_trampoline = [](void *pIn, void *pData, int *pnData) -> int {
        _InputCtx *ctx = reinterpret_cast<_InputCtx *>(pIn);
        int max_bytes = *pnData;
        Array args;
        args.push_back(max_bytes);
        Variant ret = ctx->cb.callv(args);
        if (ret.get_type() != Variant::PACKED_BYTE_ARRAY) {
            ERR_PRINT("x_input must return PackedByteArray, but got: " + ret.stringify() + " (" + Variant::get_type_name(ret.get_type()) + ")");
            *pnData = 0;
            return -1;
        }
        PackedByteArray arr = ret;
        int to_copy = MIN(max_bytes, arr.size());
        if (to_copy > 0) {
            memcpy(pData, arr.ptr(), to_copy);
        }
        *pnData = to_copy;
        return 0;
    };

    // Trampoline for xOutput: writes nData bytes from pData; user callable receives PackedByteArray and returns int.
    auto xOutput_trampoline = [](void *pOut, const void *pData, int nData) -> int {
        _OutputCtx *ctx = reinterpret_cast<_OutputCtx *>(pOut);
        PackedByteArray arr;
        if (nData > 0 && pData != nullptr) {
            arr.resize(nData);
            memcpy(arr.ptrw(), pData, nData);
        }
        Array args;
        args.push_back(arr);
        Variant ret = ctx->cb.callv(args);
        if (ret.get_type() != Variant::INT) {
            ERR_PRINT("x_output must return int, but got: " + ret.stringify() + " (" + Variant::get_type_name(ret.get_type()) + ")");
            return -1;
        }
        return int(ret);
    };

    return ::sqlite3changeset_invert_strm(xInput_trampoline, &input_ctx, xOutput_trampoline, &output_ctx);
}

int Sqlite3Wrapper::changeset_start_strm(Callable x_input, const Ref<Sqlite3ChangesetIterHandle>& out_iter) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(out_iter.is_null(), SQLITE_ERROR);
    ERR_FAIL_COND_V(!x_input.is_valid(), SQLITE_ERROR);

    struct _InputCtx {
        Callable cb;
    };
    _InputCtx ctx { x_input };

    auto trampoline = [](void *pIn, void *pData, int *pnData) -> int {
        _InputCtx *ctx = reinterpret_cast<_InputCtx *>(pIn);
        if (!ctx || !ctx->cb.is_valid() || !pData || !pnData) {
            return SQLITE_ERROR;
        }
        int max_len = *pnData;
        Array args;
        args.push_back(max_len);
        Variant ret = ctx->cb.callv(args);
        if (ret.get_type() != Variant::PACKED_BYTE_ARRAY) {
            ERR_PRINT("x_input must return PackedByteArray");
            *pnData = 0;
            return SQLITE_ERROR;
        }
        PackedByteArray arr = ret;
        int to_copy = MIN(max_len, arr.size());
        if (to_copy > 0) {
            memcpy(pData, arr.ptr(), to_copy);
        }
        *pnData = to_copy;
        return SQLITE_OK;
    };

    sqlite3_changeset_iter *iter = nullptr;
    int rc = ::sqlite3changeset_start_strm(&iter, trampoline, &ctx);
    if (rc == SQLITE_OK && iter != nullptr) {
        out_iter->set_handle(reinterpret_cast<intptr_t>(iter));
    }
    return rc;
}

int Sqlite3Wrapper::changegroup_output_strm(const Ref<Sqlite3ChangegroupHandle>& changegroup, Callable x_output) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(changegroup.is_null() || !changegroup->is_valid(), -1);
    ERR_FAIL_COND_V(!x_output.is_valid(), -1);

    struct _OutputCtx {
        Callable cb;
    } ctx{x_output};

    auto trampoline = [](void *pOut, const void *pData, int nData) -> int {
        _OutputCtx *ctx = reinterpret_cast<_OutputCtx *>(pOut);
        PackedByteArray data;
        if (pData && nData > 0) {
            data.resize(nData);
            memcpy(data.ptrw(), pData, nData);
        }
        Array args;
        args.push_back(data);
        Variant ret = ctx->cb.callv(args);
        if (ret.get_type() != Variant::INT) {
            ERR_PRINT("x_output must return int, but got: " + ret.stringify() + " (" + Variant::get_type_name(ret.get_type()) + ")");
            return -1;
        }
        return int(ret);
    };

    return ::sqlite3changegroup_output_strm(changegroup->handle, trampoline, &ctx);
}

int Sqlite3Wrapper::rebase_strm(const Ref<Sqlite3RebaserHandle>& p_rebaser, Callable x_input, Callable x_output) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(p_rebaser.is_null() || !p_rebaser->is_valid(), -1);
    ERR_FAIL_COND_V(!x_input.is_valid(), -1);
    ERR_FAIL_COND_V(!x_output.is_valid(), -1);

    struct _InputCtx {
        Callable cb;
    } input_ctx{x_input};
    struct _OutputCtx {
        Callable cb;
    } output_ctx{x_output};

    // Input trampoline
    auto input_trampoline = [](void *pIn, void *pData, int *pnData) -> int {
        _InputCtx *ctx = reinterpret_cast<_InputCtx *>(pIn);
        int req_size = (pnData && *pnData > 0) ? *pnData : 0;
        Array args;
        args.push_back(req_size);
        Variant ret = ctx->cb.callv(args);
        if (ret.get_type() != Variant::PACKED_BYTE_ARRAY) {
            ERR_PRINT("x_input callback must return PackedByteArray");
            return -1;
        }
        PackedByteArray arr = ret;
        int to_copy = MIN(req_size, arr.size());
        if (pData && to_copy > 0) {
            memcpy(pData, arr.ptr(), to_copy);
        }
        if (pnData) {
            *pnData = to_copy;
        }
        return 0;
    };

    // Output trampoline
    auto output_trampoline = [](void *pOut, const void *pData, int nData) -> int {
        _OutputCtx *ctx = reinterpret_cast<_OutputCtx *>(pOut);
        PackedByteArray arr;
        if (pData && nData > 0) {
            arr.resize(nData);
            memcpy(arr.ptrw(), pData, nData);
        }
        Array args;
        args.push_back(arr);
        Variant ret = ctx->cb.callv(args);
        if (ret.get_type() != Variant::INT) {
            ERR_PRINT("x_output callback must return int status");
            return -1;
        }
        return int(ret);
    };

    return ::sqlite3rebaser_rebase_strm(p_rebaser->handle, input_trampoline, &input_ctx, output_trampoline, &output_ctx);
}

Dictionary Sqlite3Wrapper::session_config(int64_t op, int64_t chunk_size) { // NOLINT(readability-convert-member-functions-to-static)
    int c_chunk_size = static_cast<int>(chunk_size);
    int result = ::sqlite3session_config(static_cast<int>(op), &c_chunk_size);
    Dictionary ret;
    ret["result"] = result;
    ret["chunk_size"] = static_cast<int64_t>(c_chunk_size);
    return ret;
}

int Sqlite3Wrapper::tokenize_query(void) { // NOLINT(readability-convert-member-functions-to-static)
    return FTS5_TOKENIZE_QUERY;
}

int Sqlite3Wrapper::tokenize_prefix(void) { // NOLINT(readability-convert-member-functions-to-static)
    return FTS5_TOKENIZE_PREFIX;
}

int Sqlite3Wrapper::tokenize_document(void) { // NOLINT(readability-convert-member-functions-to-static)
    return FTS5_TOKENIZE_DOCUMENT;
}

int Sqlite3Wrapper::tokenize_aux(void) { // NOLINT(readability-convert-member-functions-to-static)
    return FTS5_TOKENIZE_AUX;
}

int Sqlite3Wrapper::token_colocated(void) { // NOLINT(readability-convert-member-functions-to-static)
    return FTS5_TOKEN_COLOCATED;
}

int Sqlite3Wrapper::create_module_v2(const Ref<Sqlite3Handle>& db, const String& z_name, const Ref<Sqlite3ModuleHandle>& module, const Variant& client_data, Callable on_destroy) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_MISUSE);
    ERR_FAIL_COND_V(module.is_null() || !module->is_valid(), SQLITE_MISUSE);

    CharString z_name_utf8 = z_name.utf8();
    const char *c_zname = z_name_utf8.get_data();

    void *c_client_data = nullptr;
    void (*c_xDestroy)(void *) = nullptr;

    struct _DestroyCtx {
        Variant client_data;
        Callable cb;
    };

    _DestroyCtx *ctx = nullptr;
    if (on_destroy.is_valid()) {
        ctx = new _DestroyCtx{client_data, on_destroy};
        c_client_data = ctx;
        c_xDestroy = [](void *p) {
            _DestroyCtx *ctx = reinterpret_cast<_DestroyCtx *>(p);
            if (ctx->cb.is_valid()) {
                ctx->cb.call(ctx->client_data);
            }
            delete ctx;
        };
    } else {
        c_client_data = nullptr;
        c_xDestroy = nullptr;
    }

    return ::sqlite3_create_module_v2(
        db->handle,
        c_zname,
        module->handle,
        c_client_data,
        c_xDestroy
    );
}

int Sqlite3Wrapper::drop_modules(const Ref<Sqlite3Handle>& db, PackedStringArray keep_list) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    if (keep_list.is_empty()) {
        return ::sqlite3_drop_modules(db->handle, nullptr);
    } else {
        std::vector<CharString> utf8_storage;
        std::vector<const char *> c_ptrs;
        utf8_storage.reserve(keep_list.size());
        c_ptrs.reserve(keep_list.size() + 1);
        for (int i = 0; i < keep_list.size(); ++i) {
            utf8_storage.emplace_back(keep_list[i].utf8());
            c_ptrs.push_back(utf8_storage.back().get_data());
        }
        c_ptrs.push_back(nullptr);
        return ::sqlite3_drop_modules(db->handle, c_ptrs.data());
    }
}

int Sqlite3Wrapper::declare_vtab(const Ref<Sqlite3Handle>& db, const String& z_sql) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    godot::CharString sql8 = z_sql.utf8();
    return ::sqlite3_declare_vtab(db->handle, sql8.get_data());
}

#ifdef SQLITE_ENABLE_UNLOCK_NOTIFY
int Sqlite3Wrapper::unlock_notify(const Ref<Sqlite3Handle>& blocked, Callable notify, const Variant& notify_arg) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(blocked.is_null() || !blocked->is_valid(), SQLITE_MISUSE);
    if (!notify.is_valid()) {
        // Cancel any existing unlock-notify callback
        return ::sqlite3_unlock_notify(blocked->handle, nullptr, nullptr);
    }
    // Context struct for the callable
    struct _NotifyCtx {
        Callable cb;
        Variant *arg;
    };
    _NotifyCtx ctx{notify, memnew(Variant(notify_arg))};

    // Trampoline to bridge C callback to Godot Callable
    auto trampoline = [](void **apArg, int nArg) {
        Array args;
        for (int i = 0; i < nArg; ++i) {
            Variant *v = reinterpret_cast<Variant *>(apArg[i]);
            if (v) {
                args.push_back(*v);
            } else {
                args.push_back(Variant());
            }
        }
        // The context for the callable is the first element's Variant (all are same in this use)
        // But since SQLite may group multiple, pass the full array
        // Retrieve the Callable from any of the context Variants (stored in _NotifyCtx)
        // But in this trampoline, we cannot get the Callable directly, so we must capture _NotifyCtx* as pNotifyArg
        // Instead, for each Variant, we assume it has an associated Callable (identical for each registration)
        // However, SQLite calls with apArg[i] == pNotifyArg from registration time
        // So, we pass _NotifyCtx* as pNotifyArg, and when invoked, apArg[] contains pointers to those
        // But we need the Callable for each, so we can capture from the first one
        if (nArg > 0) {
            _NotifyCtx *ctx = reinterpret_cast<_NotifyCtx *>(apArg[0]);
            if (ctx && ctx->cb.is_valid()) {
                ctx->cb.call(args);
            }
        }
        // Clean up all allocated context pointers after use
        for (int i = 0; i < nArg; ++i) {
            _NotifyCtx *ctx_to_del = reinterpret_cast<_NotifyCtx *>(apArg[i]);
            if (ctx_to_del) {
                memdelete(ctx_to_del->arg);
                // Only delete the _NotifyCtx struct itself if it is unique in this array
                // Defensive: only delete if this is the first occurrence
                bool is_unique = true;
                for (int j = 0; j < i; ++j) {
                    if (apArg[j] == apArg[i]) {
                        is_unique = false;
                        break;
                    }
                }
                if (is_unique) {
                    memdelete(ctx_to_del);
                }
            }
        }
    };
    // Allocate context pointer for registration
    // The C API expects pNotifyArg to be passed through as apArg[] in trampoline
    // Each registration must have its own context
    _NotifyCtx *ctx_ptr = memnew(_NotifyCtx);
    ctx_ptr->cb = notify;
    ctx_ptr->arg = memnew(Variant(notify_arg));
    int result = ::sqlite3_unlock_notify(blocked->handle, trampoline, ctx_ptr);
    // If the callback is called immediately, the context will be deleted in trampoline
    // If not, SQLite will call it later and the trampoline will handle deletion
    return result;
}
#endif

int Sqlite3Wrapper::vtab_distinct(const Ref<Sqlite3IndexInfoHandle>& info) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(info.is_null() || !info->is_valid(), -1);
    return ::sqlite3_vtab_distinct(info->handle);
}

int Sqlite3Wrapper::vtab_in(const Ref<Sqlite3IndexInfoHandle>& index_info, int i_cons, int b_handle) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(index_info.is_null() || !index_info->is_valid(), 0);
    return ::sqlite3_vtab_in(index_info->handle, i_cons, b_handle);
}

int Sqlite3Wrapper::vtab_in_first(const Ref<Sqlite3ValueHandle>& p_val, const Ref<Sqlite3ValueHandle>& out_val) { // NOLINT(readability-convert-member-functions-to-static)
    ERR_FAIL_COND_V(p_val.is_null() || !p_val->is_valid(), SQLITE_ERROR);
    ERR_FAIL_COND_V(out_val.is_null(), SQLITE_ERROR);
    sqlite3_value *out = nullptr;
    int rc = ::sqlite3_vtab_in_first(p_val->handle, &out);
    out_val->set_handle(reinterpret_cast<intptr_t>(out));
    return rc;
}

int Sqlite3Wrapper::sqlite_rollback(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_ROLLBACK;
}

int Sqlite3Wrapper::sqlite_fail(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_FAIL;
}

int Sqlite3Wrapper::sqlite_replace(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_REPLACE;
}

int Sqlite3Wrapper::sqlite_scanstat_nloop(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_SCANSTAT_NLOOP;
}

int Sqlite3Wrapper::sqlite_scanstat_nvisit(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_SCANSTAT_NVISIT;
}

int Sqlite3Wrapper::sqlite_scanstat_est(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_SCANSTAT_EST;
}

int Sqlite3Wrapper::sqlite_scanstat_name(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_SCANSTAT_NAME;
}

int Sqlite3Wrapper::sqlite_scanstat_explain(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_SCANSTAT_EXPLAIN;
}

int Sqlite3Wrapper::sqlite_scanstat_selectid(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_SCANSTAT_SELECTID;
}

int Sqlite3Wrapper::sqlite_scanstat_parentid(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_SCANSTAT_PARENTID;
}

int Sqlite3Wrapper::sqlite_scanstat_ncycle(void) { // NOLINT(readability-convert-member-functions-to-static)
    return SQLITE_SCANSTAT_NCYCLE;
}
