#include "SqliteWrapper.h"

void SqliteWrapper::_bind_methods() {
    ClassDB::bind_method(D_METHOD("version_number"), &SqliteWrapper::version_number);
    ClassDB::bind_method(D_METHOD("version"), &SqliteWrapper::version);
    ClassDB::bind_method(D_METHOD("get_sqlite3_version"), &SqliteWrapper::get_sqlite3_version);
    ClassDB::bind_method(D_METHOD("sqlite3_libversion"), &SqliteWrapper::sqlite3_libversion);
    ClassDB::bind_method(D_METHOD("sqlite3_sourceid"), &SqliteWrapper::sqlite3_sourceid);
    ClassDB::bind_method(D_METHOD("sqlite3_libversion_number"), &SqliteWrapper::sqlite3_libversion_number);
    ClassDB::bind_method(D_METHOD("compileoption_used", "option_name"), &SqliteWrapper::compileoption_used);
    ClassDB::bind_method(D_METHOD("compileoption_get", "index"), &SqliteWrapper::compileoption_get);
    ClassDB::bind_method(D_METHOD("sqlite3_threadsafe"), &SqliteWrapper::sqlite3_threadsafe);
    ClassDB::bind_method(D_METHOD("close", "db"), &SqliteWrapper::close);
    ClassDB::bind_method(D_METHOD("ok"), &SqliteWrapper::ok);
    ClassDB::bind_method(D_METHOD("error"), &SqliteWrapper::error);
    ClassDB::bind_method(D_METHOD("internal"), &SqliteWrapper::internal);
    ClassDB::bind_method(D_METHOD("perm"), &SqliteWrapper::perm);
    ClassDB::bind_method(D_METHOD("abort"), &SqliteWrapper::abort);
    ClassDB::bind_method(D_METHOD("busy"), &SqliteWrapper::busy);
    ClassDB::bind_method(D_METHOD("locked"), &SqliteWrapper::locked);
    ClassDB::bind_method(D_METHOD("nomem"), &SqliteWrapper::nomem);
    ClassDB::bind_method(D_METHOD("readonly"), &SqliteWrapper::readonly);
    ClassDB::bind_method(D_METHOD("interrupt"), &SqliteWrapper::interrupt);
    ClassDB::bind_method(D_METHOD("ioerr"), &SqliteWrapper::ioerr);
    ClassDB::bind_method(D_METHOD("corrupt"), &SqliteWrapper::corrupt);
    ClassDB::bind_method(D_METHOD("notfound"), &SqliteWrapper::notfound);
    ClassDB::bind_method(D_METHOD("full"), &SqliteWrapper::full);
    ClassDB::bind_method(D_METHOD("cantopen"), &SqliteWrapper::cantopen);
    ClassDB::bind_method(D_METHOD("protocol"), &SqliteWrapper::protocol);
    ClassDB::bind_method(D_METHOD("empty"), &SqliteWrapper::empty);
    ClassDB::bind_method(D_METHOD("schema"), &SqliteWrapper::schema);
    ClassDB::bind_method(D_METHOD("toobig"), &SqliteWrapper::toobig);
    ClassDB::bind_method(D_METHOD("constraint"), &SqliteWrapper::constraint);
    ClassDB::bind_method(D_METHOD("mismatch"), &SqliteWrapper::mismatch);
    ClassDB::bind_method(D_METHOD("misuse"), &SqliteWrapper::misuse);
    ClassDB::bind_method(D_METHOD("nolfs"), &SqliteWrapper::nolfs);
    ClassDB::bind_method(D_METHOD("auth"), &SqliteWrapper::auth);
    ClassDB::bind_method(D_METHOD("format"), &SqliteWrapper::format);
    ClassDB::bind_method(D_METHOD("range"), &SqliteWrapper::range);
    ClassDB::bind_method(D_METHOD("notadb"), &SqliteWrapper::notadb);
    ClassDB::bind_method(D_METHOD("notice"), &SqliteWrapper::notice);
    ClassDB::bind_method(D_METHOD("warning"), &SqliteWrapper::warning);
    ClassDB::bind_method(D_METHOD("row"), &SqliteWrapper::row);
    ClassDB::bind_method(D_METHOD("done"), &SqliteWrapper::done);
    ClassDB::bind_method(D_METHOD("open_readonly"), &SqliteWrapper::open_readonly);
    ClassDB::bind_method(D_METHOD("open_readwrite"), &SqliteWrapper::open_readwrite);
    ClassDB::bind_method(D_METHOD("open_create"), &SqliteWrapper::open_create);
    ClassDB::bind_method(D_METHOD("open_memory"), &SqliteWrapper::open_memory);
    ClassDB::bind_method(D_METHOD("open_uri"), &SqliteWrapper::open_uri);
    ClassDB::bind_method(D_METHOD("open_nomutex"), &SqliteWrapper::open_nomutex);
    ClassDB::bind_method(D_METHOD("open_fullmutex"), &SqliteWrapper::open_fullmutex);
    ClassDB::bind_method(D_METHOD("open_sharedcache"), &SqliteWrapper::open_sharedcache);
    ClassDB::bind_method(D_METHOD("open_privatecache"), &SqliteWrapper::open_privatecache);
    ClassDB::bind_method(D_METHOD("open_nofollow"), &SqliteWrapper::open_nofollow);
    ClassDB::bind_method(D_METHOD("fcntl_lockstate"), &SqliteWrapper::fcntl_lockstate);
    ClassDB::bind_method(D_METHOD("fcntl_get_lockproxyfile"), &SqliteWrapper::fcntl_get_lockproxyfile);
    ClassDB::bind_method(D_METHOD("fcntl_set_lockproxyfile"), &SqliteWrapper::fcntl_set_lockproxyfile);
    ClassDB::bind_method(D_METHOD("fcntl_last_errno"), &SqliteWrapper::fcntl_last_errno);
    ClassDB::bind_method(D_METHOD("fcntl_size_hint"), &SqliteWrapper::fcntl_size_hint);
    ClassDB::bind_method(D_METHOD("fcntl_chunk_size"), &SqliteWrapper::fcntl_chunk_size);
    ClassDB::bind_method(D_METHOD("fcntl_file_pointer"), &SqliteWrapper::fcntl_file_pointer);
    ClassDB::bind_method(D_METHOD("fcntl_sync_omitted"), &SqliteWrapper::fcntl_sync_omitted);
    ClassDB::bind_method(D_METHOD("fcntl_win32_av_retry"), &SqliteWrapper::fcntl_win32_av_retry);
    ClassDB::bind_method(D_METHOD("fcntl_persist_wal"), &SqliteWrapper::fcntl_persist_wal);
    ClassDB::bind_method(D_METHOD("fcntl_overwrite"), &SqliteWrapper::fcntl_overwrite);
    ClassDB::bind_method(D_METHOD("fcntl_vfsname"), &SqliteWrapper::fcntl_vfsname);
    ClassDB::bind_method(D_METHOD("fcntl_powersafe_overwrite"), &SqliteWrapper::fcntl_powersafe_overwrite);
    ClassDB::bind_method(D_METHOD("fcntl_pragma"), &SqliteWrapper::fcntl_pragma);
    ClassDB::bind_method(D_METHOD("fcntl_busyhandler"), &SqliteWrapper::fcntl_busyhandler);
    ClassDB::bind_method(D_METHOD("fcntl_tempfilename"), &SqliteWrapper::fcntl_tempfilename);
    ClassDB::bind_method(D_METHOD("fcntl_mmap_size"), &SqliteWrapper::fcntl_mmap_size);
    ClassDB::bind_method(D_METHOD("fcntl_trace"), &SqliteWrapper::fcntl_trace);
    ClassDB::bind_method(D_METHOD("fcntl_has_moved"), &SqliteWrapper::fcntl_has_moved);
    ClassDB::bind_method(D_METHOD("fcntl_sync"), &SqliteWrapper::fcntl_sync);
    ClassDB::bind_method(D_METHOD("fcntl_commit_phasetwo"), &SqliteWrapper::fcntl_commit_phasetwo);
    ClassDB::bind_method(D_METHOD("fcntl_win32_set_handle"), &SqliteWrapper::fcntl_win32_set_handle);
    ClassDB::bind_method(D_METHOD("fcntl_wal_block"), &SqliteWrapper::fcntl_wal_block);
    ClassDB::bind_method(D_METHOD("fcntl_zipvfs"), &SqliteWrapper::fcntl_zipvfs);
    ClassDB::bind_method(D_METHOD("fcntl_rbu"), &SqliteWrapper::fcntl_rbu);
    ClassDB::bind_method(D_METHOD("fcntl_vfs_pointer"), &SqliteWrapper::fcntl_vfs_pointer);
    ClassDB::bind_method(D_METHOD("fcntl_journal_pointer"), &SqliteWrapper::fcntl_journal_pointer);
    ClassDB::bind_method(D_METHOD("fcntl_win32_get_handle"), &SqliteWrapper::fcntl_win32_get_handle);
    ClassDB::bind_method(D_METHOD("fcntl_pdb"), &SqliteWrapper::fcntl_pdb);
    ClassDB::bind_method(D_METHOD("fcntl_begin_atomic_write"), &SqliteWrapper::fcntl_begin_atomic_write);
    ClassDB::bind_method(D_METHOD("fcntl_commit_atomic_write"), &SqliteWrapper::fcntl_commit_atomic_write);
    ClassDB::bind_method(D_METHOD("fcntl_rollback_atomic_write"), &SqliteWrapper::fcntl_rollback_atomic_write);
    ClassDB::bind_method(D_METHOD("fcntl_lock_timeout"), &SqliteWrapper::fcntl_lock_timeout);
    ClassDB::bind_method(D_METHOD("fcntl_data_version"), &SqliteWrapper::fcntl_data_version);
    ClassDB::bind_method(D_METHOD("fcntl_size_limit"), &SqliteWrapper::fcntl_size_limit);
    ClassDB::bind_method(D_METHOD("fcntl_ckpt_done"), &SqliteWrapper::fcntl_ckpt_done);
    ClassDB::bind_method(D_METHOD("fcntl_reserve_bytes"), &SqliteWrapper::fcntl_reserve_bytes);
    ClassDB::bind_method(D_METHOD("fcntl_ckpt_start"), &SqliteWrapper::fcntl_ckpt_start);
    ClassDB::bind_method(D_METHOD("fcntl_external_reader"), &SqliteWrapper::fcntl_external_reader);
    ClassDB::bind_method(D_METHOD("fcntl_cks_file"), &SqliteWrapper::fcntl_cks_file);
    ClassDB::bind_method(D_METHOD("fcntl_reset_cache"), &SqliteWrapper::fcntl_reset_cache);
    ClassDB::bind_method(D_METHOD("fcntl_null_io"), &SqliteWrapper::fcntl_null_io);
    ClassDB::bind_method(D_METHOD("fcntl_block_on_connect"), &SqliteWrapper::fcntl_block_on_connect);
    ClassDB::bind_method(D_METHOD("fcntl_filestat"), &SqliteWrapper::fcntl_filestat);
    ClassDB::bind_method(D_METHOD("initialize"), &SqliteWrapper::initialize);
    ClassDB::bind_method(D_METHOD("shutdown"), &SqliteWrapper::shutdown);
    ClassDB::bind_method(D_METHOD("os_init"), &SqliteWrapper::os_init);
    ClassDB::bind_method(D_METHOD("os_end"), &SqliteWrapper::os_end);
    ClassDB::bind_method(D_METHOD("access_exists"), &SqliteWrapper::access_exists);
    ClassDB::bind_method(D_METHOD("access_readwrite"), &SqliteWrapper::access_readwrite);
    ClassDB::bind_method(D_METHOD("access_read"), &SqliteWrapper::access_read);
    ClassDB::bind_method(D_METHOD("shm_unlock"), &SqliteWrapper::shm_unlock);
    ClassDB::bind_method(D_METHOD("shm_lock"), &SqliteWrapper::shm_lock);
    ClassDB::bind_method(D_METHOD("shm_shared"), &SqliteWrapper::shm_shared);
    ClassDB::bind_method(D_METHOD("shm_exclusive"), &SqliteWrapper::shm_exclusive);
    ClassDB::bind_method(D_METHOD("shm_nlock"), &SqliteWrapper::shm_nlock);
    ClassDB::bind_method(D_METHOD("total_changes64", "db"), &SqliteWrapper::total_changes64);
    ClassDB::bind_method(D_METHOD("config_singlethread"), &SqliteWrapper::config_singlethread);
    ClassDB::bind_method(D_METHOD("config_multithread"), &SqliteWrapper::config_multithread);
    ClassDB::bind_method(D_METHOD("config_serialized"), &SqliteWrapper::config_serialized);
    ClassDB::bind_method(D_METHOD("config_malloc"), &SqliteWrapper::config_malloc);
    ClassDB::bind_method(D_METHOD("config_getmalloc"), &SqliteWrapper::config_getmalloc);
    ClassDB::bind_method(D_METHOD("config_scratch"), &SqliteWrapper::config_scratch);
    ClassDB::bind_method(D_METHOD("config_pagecache"), &SqliteWrapper::config_pagecache);
    ClassDB::bind_method(D_METHOD("config_heap"), &SqliteWrapper::config_heap);
    ClassDB::bind_method(D_METHOD("config_memstatus"), &SqliteWrapper::config_memstatus);
    ClassDB::bind_method(D_METHOD("config_mutex"), &SqliteWrapper::config_mutex);
    ClassDB::bind_method(D_METHOD("config_getmutex"), &SqliteWrapper::config_getmutex);
    ClassDB::bind_method(D_METHOD("config_lookaside"), &SqliteWrapper::config_lookaside);
    ClassDB::bind_method(D_METHOD("config_pcache"), &SqliteWrapper::config_pcache);
    ClassDB::bind_method(D_METHOD("config_getpcache"), &SqliteWrapper::config_getpcache);
    ClassDB::bind_method(D_METHOD("config_log"), &SqliteWrapper::config_log);
    ClassDB::bind_method(D_METHOD("config_uri"), &SqliteWrapper::config_uri);
    ClassDB::bind_method(D_METHOD("config_pcache2"), &SqliteWrapper::config_pcache2);
    ClassDB::bind_method(D_METHOD("config_getpcache2"), &SqliteWrapper::config_getpcache2);
    ClassDB::bind_method(D_METHOD("config_covering_index_scan"), &SqliteWrapper::config_covering_index_scan);
    ClassDB::bind_method(D_METHOD("config_sqllog"), &SqliteWrapper::config_sqllog);
    ClassDB::bind_method(D_METHOD("config_mmap_size"), &SqliteWrapper::config_mmap_size);
    ClassDB::bind_method(D_METHOD("config_win32_heapsize"), &SqliteWrapper::config_win32_heapsize);
    ClassDB::bind_method(D_METHOD("config_pcache_hdrsz"), &SqliteWrapper::config_pcache_hdrsz);
    ClassDB::bind_method(D_METHOD("config_pmasz"), &SqliteWrapper::config_pmasz);
    ClassDB::bind_method(D_METHOD("config_stmtjrnl_spill"), &SqliteWrapper::config_stmtjrnl_spill);
    ClassDB::bind_method(D_METHOD("config_small_malloc"), &SqliteWrapper::config_small_malloc);
    ClassDB::bind_method(D_METHOD("config_sorterref_size"), &SqliteWrapper::config_sorterref_size);
    ClassDB::bind_method(D_METHOD("config_memdb_maxsize"), &SqliteWrapper::config_memdb_maxsize);
    ClassDB::bind_method(D_METHOD("config_rowid_in_view"), &SqliteWrapper::config_rowid_in_view);
    ClassDB::bind_method(D_METHOD("dbconfig_maindbname"), &SqliteWrapper::dbconfig_maindbname);
    ClassDB::bind_method(D_METHOD("dbconfig_lookaside"), &SqliteWrapper::dbconfig_lookaside);
    ClassDB::bind_method(D_METHOD("dbconfig_enable_fkey"), &SqliteWrapper::dbconfig_enable_fkey);
    ClassDB::bind_method(D_METHOD("dbconfig_enable_trigger"), &SqliteWrapper::dbconfig_enable_trigger);
    ClassDB::bind_method(D_METHOD("dbconfig_enable_fts3_tokenizer"), &SqliteWrapper::dbconfig_enable_fts3_tokenizer);
    ClassDB::bind_method(D_METHOD("dbconfig_enable_load_extension"), &SqliteWrapper::dbconfig_enable_load_extension);
    ClassDB::bind_method(D_METHOD("dbconfig_no_ckpt_on_close"), &SqliteWrapper::dbconfig_no_ckpt_on_close);
    ClassDB::bind_method(D_METHOD("dbconfig_enable_qpsg"), &SqliteWrapper::dbconfig_enable_qpsg);
    ClassDB::bind_method(D_METHOD("dbconfig_trigger_eqp"), &SqliteWrapper::dbconfig_trigger_eqp);
    ClassDB::bind_method(D_METHOD("dbconfig_reset_database"), &SqliteWrapper::dbconfig_reset_database);
    ClassDB::bind_method(D_METHOD("dbconfig_defensive"), &SqliteWrapper::dbconfig_defensive);
    ClassDB::bind_method(D_METHOD("dbconfig_writable_schema"), &SqliteWrapper::dbconfig_writable_schema);
    ClassDB::bind_method(D_METHOD("dbconfig_legacy_alter_table"), &SqliteWrapper::dbconfig_legacy_alter_table);
    ClassDB::bind_method(D_METHOD("dbconfig_dqs_dml"), &SqliteWrapper::dbconfig_dqs_dml);
    ClassDB::bind_method(D_METHOD("dbconfig_dqs_ddl"), &SqliteWrapper::dbconfig_dqs_ddl);
    ClassDB::bind_method(D_METHOD("dbconfig_enable_view"), &SqliteWrapper::dbconfig_enable_view);
    ClassDB::bind_method(D_METHOD("dbconfig_legacy_file_format"), &SqliteWrapper::dbconfig_legacy_file_format);
    ClassDB::bind_method(D_METHOD("dbconfig_trusted_schema"), &SqliteWrapper::dbconfig_trusted_schema);
    ClassDB::bind_method(D_METHOD("dbconfig_stmt_scanstatus"), &SqliteWrapper::dbconfig_stmt_scanstatus);
    ClassDB::bind_method(D_METHOD("dbconfig_reverse_scanorder"), &SqliteWrapper::dbconfig_reverse_scanorder);
    ClassDB::bind_method(D_METHOD("dbconfig_enable_attach_create"), &SqliteWrapper::dbconfig_enable_attach_create);
    ClassDB::bind_method(D_METHOD("dbconfig_enable_attach_write"), &SqliteWrapper::dbconfig_enable_attach_write);
    ClassDB::bind_method(D_METHOD("dbconfig_enable_comments"), &SqliteWrapper::dbconfig_enable_comments);
    ClassDB::bind_method(D_METHOD("dbconfig_fp_digits"), &SqliteWrapper::dbconfig_fp_digits);
    ClassDB::bind_method(D_METHOD("dbconfig_max"), &SqliteWrapper::dbconfig_max);
    ClassDB::bind_method(D_METHOD("extended_result_codes", "db", "onoff"), &SqliteWrapper::extended_result_codes);
    ClassDB::bind_method(D_METHOD("changes64", "db"), &SqliteWrapper::changes64);
    ClassDB::bind_method(D_METHOD("complete16", "sql"), &SqliteWrapper::complete16);
    ClassDB::bind_method(D_METHOD("malloc64", "size"), &SqliteWrapper::malloc64);
    ClassDB::bind_method(D_METHOD("busy_handler", "db", "on_busy"), &SqliteWrapper::busy_handler);
    ClassDB::bind_method(D_METHOD("free_table", "result_ptr"), &SqliteWrapper::free_table);
    ClassDB::bind_method(D_METHOD("is_interrupted", "db"), &SqliteWrapper::is_interrupted);
    ClassDB::bind_method(D_METHOD("free_ptr", "ptr"), &SqliteWrapper::free_ptr);
    ClassDB::bind_method(D_METHOD("memory_highwater", "reset"), &SqliteWrapper::memory_highwater);
    ClassDB::bind_method(D_METHOD("realloc", "ptr", "size"), &SqliteWrapper::realloc);
    ClassDB::bind_method(D_METHOD("realloc64", "ptr", "size"), &SqliteWrapper::realloc64);
    ClassDB::bind_method(D_METHOD("malloc", "size"), &SqliteWrapper::malloc);
    ClassDB::bind_method(D_METHOD("memory_used"), &SqliteWrapper::memory_used);
    ClassDB::bind_method(D_METHOD("msize", "ptr"), &SqliteWrapper::msize);
    ClassDB::bind_method(D_METHOD("randomness", "length", "buffer_ptr"), &SqliteWrapper::randomness);
    ClassDB::bind_method(D_METHOD("trace", "db", "callback"), &SqliteWrapper::trace);
    ClassDB::bind_method(D_METHOD("set_authorizer", "db", "callback"), &SqliteWrapper::set_authorizer);
    ClassDB::bind_method(D_METHOD("trace_v2", "db", "mask", "callback", "context"), &SqliteWrapper::trace_v2);
    ClassDB::bind_method(D_METHOD("uri_parameter", "filename", "param"), &SqliteWrapper::uri_parameter);
    ClassDB::bind_method(D_METHOD("uri_boolean", "filename", "param", "default_value"), &SqliteWrapper::uri_boolean);
    ClassDB::bind_method(D_METHOD("uri_int64", "filename", "param", "default_value"), &SqliteWrapper::uri_int64);
    ClassDB::bind_method(D_METHOD("uri_key", "filename", "index"), &SqliteWrapper::uri_key);
    ClassDB::bind_method(D_METHOD("filename_database", "filename"), &SqliteWrapper::filename_database);
    ClassDB::bind_method(D_METHOD("errmsg", "db"), &SqliteWrapper::errmsg);
    ClassDB::bind_method(D_METHOD("filename_wal", "filename"), &SqliteWrapper::filename_wal);
    ClassDB::bind_method(D_METHOD("database_file_object", "filename"), &SqliteWrapper::database_file_object);
    ClassDB::bind_method(D_METHOD("create_filename", "database", "journal", "wal", "param_count", "params"), &SqliteWrapper::create_filename);
    ClassDB::bind_method(D_METHOD("free_filename", "filename_ptr"), &SqliteWrapper::free_filename);
    ClassDB::bind_method(D_METHOD("filename_journal", "filename"), &SqliteWrapper::filename_journal);
    ClassDB::bind_method(D_METHOD("extended_errcode", "db"), &SqliteWrapper::extended_errcode);
    ClassDB::bind_method(D_METHOD("errcode", "db"), &SqliteWrapper::errcode);
    ClassDB::bind_method(D_METHOD("errstr", "result_code"), &SqliteWrapper::errstr);
    ClassDB::bind_method(D_METHOD("limit", "db", "id", "new_value"), &SqliteWrapper::limit);
    ClassDB::bind_method(D_METHOD("get_expanded_sql", "stmt"), &SqliteWrapper::get_expanded_sql);
    ClassDB::bind_method(D_METHOD("bind_blob", "stmt", "index", "data"), &SqliteWrapper::bind_blob);
    ClassDB::bind_method(D_METHOD("bind_blob64", "stmt", "index", "data"), &SqliteWrapper::bind_blob64);
    ClassDB::bind_method(D_METHOD("bind_int64", "stmt", "index", "value"), &SqliteWrapper::bind_int64);
    ClassDB::bind_method(D_METHOD("bind_zeroblob", "stmt", "index", "length"), &SqliteWrapper::bind_zeroblob);
    ClassDB::bind_method(D_METHOD("column_name16", "stmt", "index"), &SqliteWrapper::column_name16);
    ClassDB::bind_method(D_METHOD("column_database_name16", "stmt", "index"), &SqliteWrapper::column_database_name16);
    ClassDB::bind_method(D_METHOD("column_table_name", "stmt", "index"), &SqliteWrapper::column_table_name);
    ClassDB::bind_method(D_METHOD("column_decltype16", "stmt", "index"), &SqliteWrapper::column_decltype16);
    ClassDB::bind_method(D_METHOD("constant_text"), &SqliteWrapper::constant_text);
    ClassDB::bind_method(D_METHOD("column_blob", "stmt", "index"), &SqliteWrapper::column_blob);
    ClassDB::bind_method(D_METHOD("column_double", "stmt", "index"), &SqliteWrapper::column_double);
    ClassDB::bind_method(D_METHOD("column_int", "stmt", "index"), &SqliteWrapper::column_int);
    ClassDB::bind_method(D_METHOD("column_int64", "stmt", "index"), &SqliteWrapper::column_int64);
    ClassDB::bind_method(D_METHOD("value_blob", "value"), &SqliteWrapper::value_blob);
    ClassDB::bind_method(D_METHOD("value_double", "value"), &SqliteWrapper::value_double);
    ClassDB::bind_method(D_METHOD("value_int", "value"), &SqliteWrapper::value_int);
    ClassDB::bind_method(D_METHOD("value_int64", "value"), &SqliteWrapper::value_int64);
    ClassDB::bind_method(D_METHOD("value_pointer", "value", "type_name"), &SqliteWrapper::value_pointer);
    ClassDB::bind_method(D_METHOD("value_bytes", "value"), &SqliteWrapper::value_bytes);
    ClassDB::bind_method(D_METHOD("value_free", "value"), &SqliteWrapper::value_free);
    ClassDB::bind_method(D_METHOD("set_auxdata", "context", "n", "data"), &SqliteWrapper::set_auxdata);
    ClassDB::bind_method(D_METHOD("set_clientdata", "db", "name", "data"), &SqliteWrapper::set_clientdata);
    ClassDB::bind_method(D_METHOD("constant_sqlite_static"), &SqliteWrapper::constant_sqlite_static);
    ClassDB::bind_method(D_METHOD("constant_sqlite_transient"), &SqliteWrapper::constant_sqlite_transient);
    ClassDB::bind_method(D_METHOD("result_blob", "context", "value"), &SqliteWrapper::result_blob);
    ClassDB::bind_method(D_METHOD("result_blob64", "context", "value"), &SqliteWrapper::result_blob64);
    ClassDB::bind_method(D_METHOD("result_double", "context", "value"), &SqliteWrapper::result_double);
    ClassDB::bind_method(D_METHOD("result_error16", "context", "message"), &SqliteWrapper::result_error16);
    ClassDB::bind_method(D_METHOD("result_error_nomem", "context"), &SqliteWrapper::result_error_nomem);
    ClassDB::bind_method(D_METHOD("result_value", "context", "value"), &SqliteWrapper::result_value);
    ClassDB::bind_method(D_METHOD("create_collation_v2", "db", "name", "text_rep", "compare_func"), &SqliteWrapper::create_collation_v2);
    ClassDB::bind_method(D_METHOD("collation_needed16", "db", "callback"), &SqliteWrapper::collation_needed16);
    ClassDB::bind_method(D_METHOD("set_temp_directory", "path"), &SqliteWrapper::set_temp_directory);
    ClassDB::bind_method(D_METHOD("get_temp_directory"), &SqliteWrapper::get_temp_directory);
    ClassDB::bind_method(D_METHOD("set_data_directory", "path"), &SqliteWrapper::set_data_directory);
    ClassDB::bind_method(D_METHOD("get_data_directory"), &SqliteWrapper::get_data_directory);
#if 0
    ClassDB::bind_method(D_METHOD("win32_set_directory", "type", "value"), &SqliteWrapper::win32_set_directory);
    ClassDB::bind_method(D_METHOD("win32_set_directory8", "type", "value"), &SqliteWrapper::win32_set_directory8);
    ClassDB::bind_method(D_METHOD("win32_set_directory16", "type", "value"), &SqliteWrapper::win32_set_directory16);
#endif
    ClassDB::bind_method(D_METHOD("constant_win32_data_directory_type"), &SqliteWrapper::constant_win32_data_directory_type);
    ClassDB::bind_method(D_METHOD("constant_win32_temp_directory_type"), &SqliteWrapper::constant_win32_temp_directory_type);
    ClassDB::bind_method(D_METHOD("get_autocommit", "db"), &SqliteWrapper::get_autocommit);
    ClassDB::bind_method(D_METHOD("next_stmt", "db", "stmt"), &SqliteWrapper::next_stmt);
    ClassDB::bind_method(D_METHOD("rollback_hook", "db", "callback", "user_data"), &SqliteWrapper::rollback_hook);
    ClassDB::bind_method(D_METHOD("release_memory", "bytes"), &SqliteWrapper::release_memory);
    ClassDB::bind_method(D_METHOD("hard_heap_limit", "limit"), &SqliteWrapper::hard_heap_limit);
    ClassDB::bind_method(D_METHOD("soft_heap_limit", "limit"), &SqliteWrapper::soft_heap_limit);
    ClassDB::bind_method(D_METHOD("load_extension", "db", "file", "entry_point"), &SqliteWrapper::load_extension);
    ClassDB::bind_method(D_METHOD("cancel_auto_extension", "entry_point"), &SqliteWrapper::cancel_auto_extension);
    ClassDB::bind_method(D_METHOD("reset_auto_extension"), &SqliteWrapper::reset_auto_extension);
    ClassDB::bind_method(D_METHOD("index_scan_unique"), &SqliteWrapper::index_scan_unique);
    ClassDB::bind_method(D_METHOD("index_scan_hex"), &SqliteWrapper::index_scan_hex);
    ClassDB::bind_method(D_METHOD("index_constraint_eq"), &SqliteWrapper::index_constraint_eq);
    ClassDB::bind_method(D_METHOD("index_constraint_gt"), &SqliteWrapper::index_constraint_gt);
    ClassDB::bind_method(D_METHOD("index_constraint_le"), &SqliteWrapper::index_constraint_le);
    ClassDB::bind_method(D_METHOD("index_constraint_lt"), &SqliteWrapper::index_constraint_lt);
    ClassDB::bind_method(D_METHOD("index_constraint_ge"), &SqliteWrapper::index_constraint_ge);
    ClassDB::bind_method(D_METHOD("index_constraint_match"), &SqliteWrapper::index_constraint_match);
    ClassDB::bind_method(D_METHOD("index_constraint_like"), &SqliteWrapper::index_constraint_like);
    ClassDB::bind_method(D_METHOD("index_constraint_glob"), &SqliteWrapper::index_constraint_glob);
    ClassDB::bind_method(D_METHOD("index_constraint_regexp"), &SqliteWrapper::index_constraint_regexp);
    ClassDB::bind_method(D_METHOD("index_constraint_ne"), &SqliteWrapper::index_constraint_ne);
    ClassDB::bind_method(D_METHOD("index_constraint_isnot"), &SqliteWrapper::index_constraint_isnot);
    ClassDB::bind_method(D_METHOD("index_constraint_isnotnull"), &SqliteWrapper::index_constraint_isnotnull);
    ClassDB::bind_method(D_METHOD("index_constraint_isnull"), &SqliteWrapper::index_constraint_isnull);
    ClassDB::bind_method(D_METHOD("index_constraint_is"), &SqliteWrapper::index_constraint_is);
    ClassDB::bind_method(D_METHOD("index_constraint_limit"), &SqliteWrapper::index_constraint_limit);
    ClassDB::bind_method(D_METHOD("index_constraint_offset"), &SqliteWrapper::index_constraint_offset);
    ClassDB::bind_method(D_METHOD("index_constraint_function"), &SqliteWrapper::index_constraint_function);
    ClassDB::bind_method(D_METHOD("create_module", "db", "name", "module", "client_data"), &SqliteWrapper::create_module);
    ClassDB::bind_method(D_METHOD("blob_open", "db", "db_name", "table_name", "column_name", "row_id", "flags", "out_blob"), &SqliteWrapper::blob_open);
    ClassDB::bind_method(D_METHOD("vfs_register", "vfs", "make_default"), &SqliteWrapper::vfs_register);
    ClassDB::bind_method(D_METHOD("vfs_unregister", "vfs"), &SqliteWrapper::vfs_unregister);
    ClassDB::bind_method(D_METHOD("mutex_free", "mutex"), &SqliteWrapper::mutex_free);
    ClassDB::bind_method(D_METHOD("mutex_enter", "mutex"), &SqliteWrapper::mutex_enter);
    ClassDB::bind_method(D_METHOD("mutex_try", "mutex"), &SqliteWrapper::mutex_try);
    ClassDB::bind_method(D_METHOD("mutex_leave", "mutex"), &SqliteWrapper::mutex_leave);
    ClassDB::bind_method(D_METHOD("db_mutex", "db"), &SqliteWrapper::db_mutex);
    ClassDB::bind_method(D_METHOD("test_control_first"), &SqliteWrapper::test_control_first);
    ClassDB::bind_method(D_METHOD("test_control_prng_save"), &SqliteWrapper::test_control_prng_save);
    ClassDB::bind_method(D_METHOD("test_control_prng_restore"), &SqliteWrapper::test_control_prng_restore);
    ClassDB::bind_method(D_METHOD("test_control_prng_reset"), &SqliteWrapper::test_control_prng_reset);
    ClassDB::bind_method(D_METHOD("test_control_fk_no_action"), &SqliteWrapper::test_control_fk_no_action);
    ClassDB::bind_method(D_METHOD("test_control_bitvec_test"), &SqliteWrapper::test_control_bitvec_test);
    ClassDB::bind_method(D_METHOD("test_control_fault_install"), &SqliteWrapper::test_control_fault_install);
    ClassDB::bind_method(D_METHOD("test_control_benign_malloc_hooks"), &SqliteWrapper::test_control_benign_malloc_hooks);
    ClassDB::bind_method(D_METHOD("test_control_pending_byte"), &SqliteWrapper::test_control_pending_byte);
    ClassDB::bind_method(D_METHOD("test_control_assert"), &SqliteWrapper::test_control_assert);
    ClassDB::bind_method(D_METHOD("test_control_always"), &SqliteWrapper::test_control_always);
    ClassDB::bind_method(D_METHOD("test_control_reserve"), &SqliteWrapper::test_control_reserve);
    ClassDB::bind_method(D_METHOD("test_control_json_selfcheck"), &SqliteWrapper::test_control_json_selfcheck);
    ClassDB::bind_method(D_METHOD("test_control_optimizations"), &SqliteWrapper::test_control_optimizations);
    ClassDB::bind_method(D_METHOD("test_control_iskeyword"), &SqliteWrapper::test_control_iskeyword);
    ClassDB::bind_method(D_METHOD("test_control_getopt"), &SqliteWrapper::test_control_getopt);
    ClassDB::bind_method(D_METHOD("test_control_scratchmalloc"), &SqliteWrapper::test_control_scratchmalloc);
    ClassDB::bind_method(D_METHOD("test_control_internal_functions"), &SqliteWrapper::test_control_internal_functions);
    ClassDB::bind_method(D_METHOD("test_control_localtime_fault"), &SqliteWrapper::test_control_localtime_fault);
    ClassDB::bind_method(D_METHOD("test_control_explain_stmt"), &SqliteWrapper::test_control_explain_stmt);
    ClassDB::bind_method(D_METHOD("test_control_once_reset_threshold"), &SqliteWrapper::test_control_once_reset_threshold);
    ClassDB::bind_method(D_METHOD("test_control_never_corrupt"), &SqliteWrapper::test_control_never_corrupt);
    ClassDB::bind_method(D_METHOD("test_control_vdbe_coverage"), &SqliteWrapper::test_control_vdbe_coverage);
    ClassDB::bind_method(D_METHOD("test_control_byteorder"), &SqliteWrapper::test_control_byteorder);
    ClassDB::bind_method(D_METHOD("test_control_isinit"), &SqliteWrapper::test_control_isinit);
    ClassDB::bind_method(D_METHOD("test_control_sorter_mmap"), &SqliteWrapper::test_control_sorter_mmap);
    ClassDB::bind_method(D_METHOD("test_control_imposter"), &SqliteWrapper::test_control_imposter);
    ClassDB::bind_method(D_METHOD("test_control_parser_coverage"), &SqliteWrapper::test_control_parser_coverage);
    ClassDB::bind_method(D_METHOD("test_control_result_intreal"), &SqliteWrapper::test_control_result_intreal);
    ClassDB::bind_method(D_METHOD("test_control_prng_seed"), &SqliteWrapper::test_control_prng_seed);
    ClassDB::bind_method(D_METHOD("test_control_extra_schema_checks"), &SqliteWrapper::test_control_extra_schema_checks);
    ClassDB::bind_method(D_METHOD("test_control_seek_count"), &SqliteWrapper::test_control_seek_count);
    ClassDB::bind_method(D_METHOD("test_control_traceflags"), &SqliteWrapper::test_control_traceflags);
    ClassDB::bind_method(D_METHOD("test_control_tune"), &SqliteWrapper::test_control_tune);
    ClassDB::bind_method(D_METHOD("test_control_logest"), &SqliteWrapper::test_control_logest);
    ClassDB::bind_method(D_METHOD("test_control_uselongdouble"), &SqliteWrapper::test_control_uselongdouble);
    ClassDB::bind_method(D_METHOD("test_control_last"), &SqliteWrapper::test_control_last);
    ClassDB::bind_method(D_METHOD("keyword_count"), &SqliteWrapper::keyword_count);
    ClassDB::bind_method(D_METHOD("keyword_name", "index"), &SqliteWrapper::keyword_name);
    ClassDB::bind_method(D_METHOD("is_keyword", "identifier"), &SqliteWrapper::is_keyword);
    ClassDB::bind_method(D_METHOD("str_new", "db"), &SqliteWrapper::str_new);
    ClassDB::bind_method(D_METHOD("str_free", "str"), &SqliteWrapper::str_free);
    ClassDB::bind_method(D_METHOD("str_vappendf", "str", "format", "args"), &SqliteWrapper::str_vappendf);
    ClassDB::bind_method(D_METHOD("str_append", "str", "text", "length"), &SqliteWrapper::str_append);
    ClassDB::bind_method(D_METHOD("str_appendall", "str", "text"), &SqliteWrapper::str_appendall);
    ClassDB::bind_method(D_METHOD("str_appendchar", "str", "count", "character"), &SqliteWrapper::str_appendchar);
    ClassDB::bind_method(D_METHOD("str_reset", "str"), &SqliteWrapper::str_reset);
    ClassDB::bind_method(D_METHOD("str_truncate", "str", "length"), &SqliteWrapper::str_truncate);
    ClassDB::bind_method(D_METHOD("str_length", "str"), &SqliteWrapper::str_length);
    ClassDB::bind_method(D_METHOD("str_value", "str"), &SqliteWrapper::str_value);
    ClassDB::bind_method(D_METHOD("status64", "op", "reset_flag"), &SqliteWrapper::status64);
    ClassDB::bind_method(D_METHOD("status_memory_used"), &SqliteWrapper::status_memory_used);
    ClassDB::bind_method(D_METHOD("status_pagecache_used"), &SqliteWrapper::status_pagecache_used);
    ClassDB::bind_method(D_METHOD("status_pagecache_overflow"), &SqliteWrapper::status_pagecache_overflow);
    ClassDB::bind_method(D_METHOD("status_malloc_size"), &SqliteWrapper::status_malloc_size);
    ClassDB::bind_method(D_METHOD("status_parser_stack"), &SqliteWrapper::status_parser_stack);
    ClassDB::bind_method(D_METHOD("status_pagecache_size"), &SqliteWrapper::status_pagecache_size);
    ClassDB::bind_method(D_METHOD("status_malloc_count"), &SqliteWrapper::status_malloc_count);
    ClassDB::bind_method(D_METHOD("db_status", "db", "op", "reset_flag"), &SqliteWrapper::db_status);
    ClassDB::bind_method(D_METHOD("db_status64", "db", "op", "reset_flag"), &SqliteWrapper::db_status64);
    ClassDB::bind_method(D_METHOD("stmt_status", "stmt", "op", "reset_flag"), &SqliteWrapper::stmt_status);
    ClassDB::bind_method(D_METHOD("backup_step", "backup", "n_page"), &SqliteWrapper::backup_step);
    ClassDB::bind_method(D_METHOD("backup_finish", "backup"), &SqliteWrapper::backup_finish);
    ClassDB::bind_method(D_METHOD("backup_remaining", "backup"), &SqliteWrapper::backup_remaining);
    ClassDB::bind_method(D_METHOD("str_nicmp", "a", "b", "n"), &SqliteWrapper::str_nicmp);
    ClassDB::bind_method(D_METHOD("str_glob", "pattern", "str"), &SqliteWrapper::str_glob);
    ClassDB::bind_method(D_METHOD("str_like", "pattern", "str", "escape"), &SqliteWrapper::str_like);
    ClassDB::bind_method(D_METHOD("log", "error_code", "format"), &SqliteWrapper::log);
    ClassDB::bind_method(D_METHOD("wal_hook", "db", "callback", "user_data"), &SqliteWrapper::wal_hook);
    ClassDB::bind_method(D_METHOD("vtab_config", "db", "op", "args"), &SqliteWrapper::vtab_config);
    ClassDB::bind_method(D_METHOD("vtab_on_conflict", "db"), &SqliteWrapper::vtab_on_conflict);
    ClassDB::bind_method(D_METHOD("vtab_in_next", "pVal", "out_value"), &SqliteWrapper::vtab_in_next);
#if 0
    ClassDB::bind_method(D_METHOD("stmt_scanstatus", "stmt", "idx", "scan_status_op", "out_value"), &SqliteWrapper::stmt_scanstatus);
#endif
    ClassDB::bind_method(D_METHOD("stmt_scanstat_complex"), &SqliteWrapper::stmt_scanstat_complex);
    ClassDB::bind_method(D_METHOD("snapshot_get", "db", "schema", "out_snapshot"), &SqliteWrapper::snapshot_get);
    ClassDB::bind_method(D_METHOD("snapshot_free", "snapshot"), &SqliteWrapper::snapshot_free);
    ClassDB::bind_method(D_METHOD("deserialize", "db", "schema", "data", "sz_db", "sz_buf", "flags"), &SqliteWrapper::deserialize);
#if 0
    ClassDB::bind_method(D_METHOD("carray_bind_v2", "stmt", "index", "data", "n_data", "flags"), &SqliteWrapper::carray_bind_v2);
#endif
    ClassDB::bind_method(D_METHOD("rtree_query_callback", "db", "query_func", "on_query"), &SqliteWrapper::rtree_query_callback);
    ClassDB::bind_method(D_METHOD("not_within"), &SqliteWrapper::not_within);
    ClassDB::bind_method(D_METHOD("partly_within"), &SqliteWrapper::partly_within);
    ClassDB::bind_method(D_METHOD("fully_within"), &SqliteWrapper::fully_within);
    ClassDB::bind_method(D_METHOD("session_create", "db", "z_db", "out_session"), &SqliteWrapper::session_create);
    ClassDB::bind_method(D_METHOD("session_enable", "session", "b_enable"), &SqliteWrapper::session_enable);
    ClassDB::bind_method(D_METHOD("session_memory_used", "session"), &SqliteWrapper::session_memory_used);
    ClassDB::bind_method(D_METHOD("changeset_start_v2", "out_iter", "changeset", "flags"), &SqliteWrapper::changeset_start_v2);
    ClassDB::bind_method(D_METHOD("changeset_next", "iter"), &SqliteWrapper::changeset_next);
    ClassDB::bind_method(D_METHOD("changeset_concat", "input_a", "input_b"), &SqliteWrapper::changeset_concat);
    ClassDB::bind_method(D_METHOD("changegroup_new", "out_handle"), &SqliteWrapper::changegroup_new);
    ClassDB::bind_method(D_METHOD("rebaser_create"), &SqliteWrapper::rebaser_create);
    ClassDB::bind_method(D_METHOD("rebaser_configure", "rebaser", "rebase_data"), &SqliteWrapper::rebaser_configure);
    ClassDB::bind_method(D_METHOD("rebaser_destroy", "rebaser"), &SqliteWrapper::rebaser_destroy);
    ClassDB::bind_method(D_METHOD("changeset_concat_stream", "changeset_a", "changeset_b"), &SqliteWrapper::changeset_concat_stream);
    ClassDB::bind_method(D_METHOD("changeset_start_v2_stream", "changeset", "flags"), &SqliteWrapper::changeset_start_v2_stream);
    ClassDB::bind_method(D_METHOD("session_changeset_stream", "session"), &SqliteWrapper::session_changeset_stream);
    ClassDB::bind_method(D_METHOD("session_patchset_stream", "session"), &SqliteWrapper::session_patchset_stream);
    ClassDB::bind_method(D_METHOD("changegroup_add_stream", "changegroup", "data"), &SqliteWrapper::changegroup_add_stream);
    ClassDB::bind_method(D_METHOD("session_config_strmsize"), &SqliteWrapper::session_config_strmsize);
    ClassDB::bind_method(D_METHOD("close_v2", "db"), &SqliteWrapper::close_v2);
    ClassDB::bind_method(D_METHOD("exec", "db", "sql", "callback"), &SqliteWrapper::exec);
    ClassDB::bind_method(D_METHOD("last_insert_rowid", "db"), &SqliteWrapper::last_insert_rowid);
    ClassDB::bind_method(D_METHOD("set_last_insert_rowid", "db", "rowid"), &SqliteWrapper::set_last_insert_rowid);
    ClassDB::bind_method(D_METHOD("changes", "db"), &SqliteWrapper::changes);
    ClassDB::bind_method(D_METHOD("total_changes", "db"), &SqliteWrapper::total_changes);
    ClassDB::bind_method(D_METHOD("complete", "sql"), &SqliteWrapper::complete);
    ClassDB::bind_method(D_METHOD("busy_timeout", "db", "ms"), &SqliteWrapper::busy_timeout);
    ClassDB::bind_method(D_METHOD("setlk_timeout", "db", "ms", "flags"), &SqliteWrapper::setlk_timeout);
    ClassDB::bind_method(D_METHOD("setlk_block_on_connect_flag"), &SqliteWrapper::setlk_block_on_connect_flag);
    ClassDB::bind_method(D_METHOD("get_table", "db", "sql", "out_result", "out_rows", "out_columns", "out_error"), &SqliteWrapper::get_table);
    ClassDB::bind_method(D_METHOD("deny_code"), &SqliteWrapper::deny_code);
    ClassDB::bind_method(D_METHOD("ignore_code"), &SqliteWrapper::ignore_code);
    ClassDB::bind_method(D_METHOD("create_index_action"), &SqliteWrapper::create_index_action);
    ClassDB::bind_method(D_METHOD("create_table_action"), &SqliteWrapper::create_table_action);
    ClassDB::bind_method(D_METHOD("create_temp_index_action"), &SqliteWrapper::create_temp_index_action);
    ClassDB::bind_method(D_METHOD("create_temp_table_action"), &SqliteWrapper::create_temp_table_action);
    ClassDB::bind_method(D_METHOD("create_temp_trigger_action"), &SqliteWrapper::create_temp_trigger_action);
    ClassDB::bind_method(D_METHOD("create_temp_view_action"), &SqliteWrapper::create_temp_view_action);
    ClassDB::bind_method(D_METHOD("create_trigger_action"), &SqliteWrapper::create_trigger_action);
    ClassDB::bind_method(D_METHOD("create_view_action"), &SqliteWrapper::create_view_action);
    ClassDB::bind_method(D_METHOD("delete_action"), &SqliteWrapper::delete_action);
    ClassDB::bind_method(D_METHOD("drop_index_action"), &SqliteWrapper::drop_index_action);
    ClassDB::bind_method(D_METHOD("drop_table_action"), &SqliteWrapper::drop_table_action);
    ClassDB::bind_method(D_METHOD("drop_temp_index_action"), &SqliteWrapper::drop_temp_index_action);
    ClassDB::bind_method(D_METHOD("drop_temp_table_action"), &SqliteWrapper::drop_temp_table_action);
    ClassDB::bind_method(D_METHOD("drop_temp_trigger_action"), &SqliteWrapper::drop_temp_trigger_action);
    ClassDB::bind_method(D_METHOD("drop_temp_view_action"), &SqliteWrapper::drop_temp_view_action);
    ClassDB::bind_method(D_METHOD("drop_trigger_action"), &SqliteWrapper::drop_trigger_action);
    ClassDB::bind_method(D_METHOD("drop_view_action"), &SqliteWrapper::drop_view_action);
    ClassDB::bind_method(D_METHOD("insert_action"), &SqliteWrapper::insert_action);
    ClassDB::bind_method(D_METHOD("pragma_action"), &SqliteWrapper::pragma_action);
    ClassDB::bind_method(D_METHOD("read_action"), &SqliteWrapper::read_action);
    ClassDB::bind_method(D_METHOD("select_action"), &SqliteWrapper::select_action);
    ClassDB::bind_method(D_METHOD("transaction_action"), &SqliteWrapper::transaction_action);
    ClassDB::bind_method(D_METHOD("update_action"), &SqliteWrapper::update_action);
    ClassDB::bind_method(D_METHOD("attach_action"), &SqliteWrapper::attach_action);
    ClassDB::bind_method(D_METHOD("detach_action"), &SqliteWrapper::detach_action);
    ClassDB::bind_method(D_METHOD("alter_table_action"), &SqliteWrapper::alter_table_action);
    ClassDB::bind_method(D_METHOD("reindex_action"), &SqliteWrapper::reindex_action);
    ClassDB::bind_method(D_METHOD("analyze_action"), &SqliteWrapper::analyze_action);
    ClassDB::bind_method(D_METHOD("create_vtable_action"), &SqliteWrapper::create_vtable_action);
    ClassDB::bind_method(D_METHOD("drop_vtable_action"), &SqliteWrapper::drop_vtable_action);
    ClassDB::bind_method(D_METHOD("function_action"), &SqliteWrapper::function_action);
    ClassDB::bind_method(D_METHOD("savepoint_action"), &SqliteWrapper::savepoint_action);
    ClassDB::bind_method(D_METHOD("copy_action"), &SqliteWrapper::copy_action);
    ClassDB::bind_method(D_METHOD("recursive_action"), &SqliteWrapper::recursive_action);
    ClassDB::bind_method(D_METHOD("profile", "db", "callback"), &SqliteWrapper::profile);
    ClassDB::bind_method(D_METHOD("trace_stmt_mask"), &SqliteWrapper::trace_stmt_mask);
    ClassDB::bind_method(D_METHOD("trace_profile_mask"), &SqliteWrapper::trace_profile_mask);
    ClassDB::bind_method(D_METHOD("trace_row_mask"), &SqliteWrapper::trace_row_mask);
    ClassDB::bind_method(D_METHOD("trace_close_mask"), &SqliteWrapper::trace_close_mask);
    ClassDB::bind_method(D_METHOD("progress_handler", "db", "n", "callback"), &SqliteWrapper::progress_handler);
    ClassDB::bind_method(D_METHOD("open", "filename", "out_db"), &SqliteWrapper::open);
    ClassDB::bind_method(D_METHOD("open16", "filename", "out_db"), &SqliteWrapper::open16);
    ClassDB::bind_method(D_METHOD("open_v2", "filename", "out_db", "flags", "vfs"), &SqliteWrapper::open_v2);
    ClassDB::bind_method(D_METHOD("errmsg16", "db"), &SqliteWrapper::errmsg16);
    ClassDB::bind_method(D_METHOD("error_offset", "db"), &SqliteWrapper::error_offset);
    ClassDB::bind_method(D_METHOD("set_errmsg", "db", "errcode", "errmsg"), &SqliteWrapper::set_errmsg);
    ClassDB::bind_method(D_METHOD("limit_length"), &SqliteWrapper::limit_length);
    ClassDB::bind_method(D_METHOD("limit_sql_length"), &SqliteWrapper::limit_sql_length);
    ClassDB::bind_method(D_METHOD("limit_column"), &SqliteWrapper::limit_column);
    ClassDB::bind_method(D_METHOD("limit_expr_depth"), &SqliteWrapper::limit_expr_depth);
    ClassDB::bind_method(D_METHOD("limit_compound_select"), &SqliteWrapper::limit_compound_select);
    ClassDB::bind_method(D_METHOD("limit_vdbe_op"), &SqliteWrapper::limit_vdbe_op);
    ClassDB::bind_method(D_METHOD("limit_function_arg"), &SqliteWrapper::limit_function_arg);
    ClassDB::bind_method(D_METHOD("limit_attached"), &SqliteWrapper::limit_attached);
    ClassDB::bind_method(D_METHOD("limit_like_pattern_length"), &SqliteWrapper::limit_like_pattern_length);
    ClassDB::bind_method(D_METHOD("limit_variable_number"), &SqliteWrapper::limit_variable_number);
    ClassDB::bind_method(D_METHOD("limit_trigger_depth"), &SqliteWrapper::limit_trigger_depth);
    ClassDB::bind_method(D_METHOD("limit_worker_threads"), &SqliteWrapper::limit_worker_threads);
    ClassDB::bind_method(D_METHOD("limit_parser_depth"), &SqliteWrapper::limit_parser_depth);
    ClassDB::bind_method(D_METHOD("prepare_persistent_flag"), &SqliteWrapper::prepare_persistent_flag);
    ClassDB::bind_method(D_METHOD("prepare_normalize_flag"), &SqliteWrapper::prepare_normalize_flag);
    ClassDB::bind_method(D_METHOD("prepare_no_vtab_flag"), &SqliteWrapper::prepare_no_vtab_flag);
    ClassDB::bind_method(D_METHOD("prepare_dont_log_flag"), &SqliteWrapper::prepare_dont_log_flag);
    ClassDB::bind_method(D_METHOD("prepare_from_ddl_flag"), &SqliteWrapper::prepare_from_ddl_flag);
    ClassDB::bind_method(D_METHOD("prepare", "db", "sql", "max_bytes", "out_stmt", "out_tail"), &SqliteWrapper::prepare);
    ClassDB::bind_method(D_METHOD("prepare_v2", "db", "sql", "max_bytes", "out_stmt", "out_tail"), &SqliteWrapper::prepare_v2);
    ClassDB::bind_method(D_METHOD("prepare_v3", "db", "sql", "max_bytes", "prep_flags", "out_stmt", "out_tail"), &SqliteWrapper::prepare_v3);
    ClassDB::bind_method(D_METHOD("prepare16", "db", "sql", "max_bytes", "out_stmt", "out_tail"), &SqliteWrapper::prepare16);
    ClassDB::bind_method(D_METHOD("prepare16_v2", "db", "sql", "max_bytes", "out_stmt", "out_tail"), &SqliteWrapper::prepare16_v2);
    ClassDB::bind_method(D_METHOD("prepare16_v3", "db", "sql", "max_bytes", "prep_flags", "out_stmt", "out_tail"), &SqliteWrapper::prepare16_v3);
    ClassDB::bind_method(D_METHOD("get_sql", "stmt"), &SqliteWrapper::get_sql);
    ClassDB::bind_method(D_METHOD("get_normalized_sql", "stmt"), &SqliteWrapper::get_normalized_sql);
    ClassDB::bind_method(D_METHOD("is_read_only", "stmt"), &SqliteWrapper::is_read_only);
    ClassDB::bind_method(D_METHOD("is_explain", "stmt"), &SqliteWrapper::is_explain);
    ClassDB::bind_method(D_METHOD("set_explain_mode", "stmt", "mode"), &SqliteWrapper::set_explain_mode);
    ClassDB::bind_method(D_METHOD("is_busy", "stmt"), &SqliteWrapper::is_busy);
    ClassDB::bind_method(D_METHOD("bind_double", "stmt", "index", "value"), &SqliteWrapper::bind_double);
    ClassDB::bind_method(D_METHOD("bind_int", "stmt", "index", "value"), &SqliteWrapper::bind_int);
    ClassDB::bind_method(D_METHOD("bind_null", "stmt", "index"), &SqliteWrapper::bind_null);
    ClassDB::bind_method(D_METHOD("bind_text", "stmt", "index", "text"), &SqliteWrapper::bind_text);
    ClassDB::bind_method(D_METHOD("bind_text16", "stmt", "index", "text"), &SqliteWrapper::bind_text16);
    ClassDB::bind_method(D_METHOD("bind_text64", "stmt", "index", "text"), &SqliteWrapper::bind_text64);
    ClassDB::bind_method(D_METHOD("bind_value", "stmt", "index", "value"), &SqliteWrapper::bind_value);
    ClassDB::bind_method(D_METHOD("bind_pointer", "stmt", "index", "pointer", "type"), &SqliteWrapper::bind_pointer);
    ClassDB::bind_method(D_METHOD("bind_zeroblob64", "stmt", "index", "length"), &SqliteWrapper::bind_zeroblob64);
    ClassDB::bind_method(D_METHOD("bind_parameter_count", "stmt"), &SqliteWrapper::bind_parameter_count);
    ClassDB::bind_method(D_METHOD("bind_parameter_name", "stmt", "index"), &SqliteWrapper::bind_parameter_name);
    ClassDB::bind_method(D_METHOD("bind_parameter_index", "stmt", "name"), &SqliteWrapper::bind_parameter_index);
    ClassDB::bind_method(D_METHOD("clear_bindings", "stmt"), &SqliteWrapper::clear_bindings);
    ClassDB::bind_method(D_METHOD("column_count", "stmt"), &SqliteWrapper::column_count);
    ClassDB::bind_method(D_METHOD("column_name", "stmt", "index"), &SqliteWrapper::column_name);
    ClassDB::bind_method(D_METHOD("column_database_name", "stmt", "index"), &SqliteWrapper::column_database_name);
    ClassDB::bind_method(D_METHOD("column_table_name16", "stmt", "index"), &SqliteWrapper::column_table_name16);
    ClassDB::bind_method(D_METHOD("column_origin_name", "stmt", "index"), &SqliteWrapper::column_origin_name);
    ClassDB::bind_method(D_METHOD("column_origin_name16", "stmt", "index"), &SqliteWrapper::column_origin_name16);
    ClassDB::bind_method(D_METHOD("column_decltype", "stmt", "index"), &SqliteWrapper::column_decltype);
    ClassDB::bind_method(D_METHOD("step", "stmt"), &SqliteWrapper::step);
    ClassDB::bind_method(D_METHOD("data_count", "stmt"), &SqliteWrapper::data_count);
    ClassDB::bind_method(D_METHOD("constant_integer"), &SqliteWrapper::constant_integer);
    ClassDB::bind_method(D_METHOD("constant_float"), &SqliteWrapper::constant_float);
    ClassDB::bind_method(D_METHOD("constant_blob"), &SqliteWrapper::constant_blob);
    ClassDB::bind_method(D_METHOD("constant_null"), &SqliteWrapper::constant_null);
    ClassDB::bind_method(D_METHOD("column_text", "stmt", "index"), &SqliteWrapper::column_text);
    ClassDB::bind_method(D_METHOD("column_text16", "stmt", "index"), &SqliteWrapper::column_text16);
    ClassDB::bind_method(D_METHOD("column_value", "stmt", "index"), &SqliteWrapper::column_value);
    ClassDB::bind_method(D_METHOD("column_bytes", "stmt", "index"), &SqliteWrapper::column_bytes);
    ClassDB::bind_method(D_METHOD("column_bytes16", "stmt", "index"), &SqliteWrapper::column_bytes16);
    ClassDB::bind_method(D_METHOD("column_type", "stmt", "index"), &SqliteWrapper::column_type);
    ClassDB::bind_method(D_METHOD("finalize", "stmt"), &SqliteWrapper::finalize);
    ClassDB::bind_method(D_METHOD("reset", "stmt"), &SqliteWrapper::reset);
    ClassDB::bind_method(D_METHOD("create_function", "db", "function_name", "n_arg", "text_rep", "func"), &SqliteWrapper::create_function);
    ClassDB::bind_method(D_METHOD("create_function16", "db", "function_name", "n_arg", "text_rep", "func"), &SqliteWrapper::create_function16);
    ClassDB::bind_method(D_METHOD("create_function_v2", "db", "function_name", "n_arg", "text_rep", "func"), &SqliteWrapper::create_function_v2);
    ClassDB::bind_method(D_METHOD("create_window_function", "db", "function_name", "n_arg", "text_rep", "func"), &SqliteWrapper::create_window_function);
    ClassDB::bind_method(D_METHOD("constant_utf8"), &SqliteWrapper::constant_utf8);
    ClassDB::bind_method(D_METHOD("constant_utf16le"), &SqliteWrapper::constant_utf16le);
    ClassDB::bind_method(D_METHOD("constant_utf16be"), &SqliteWrapper::constant_utf16be);
    ClassDB::bind_method(D_METHOD("constant_utf16"), &SqliteWrapper::constant_utf16);
    ClassDB::bind_method(D_METHOD("constant_any"), &SqliteWrapper::constant_any);
    ClassDB::bind_method(D_METHOD("constant_utf16_aligned"), &SqliteWrapper::constant_utf16_aligned);
    ClassDB::bind_method(D_METHOD("constant_utf8_zt"), &SqliteWrapper::constant_utf8_zt);
    ClassDB::bind_method(D_METHOD("constant_deterministic"), &SqliteWrapper::constant_deterministic);
    ClassDB::bind_method(D_METHOD("constant_directonly"), &SqliteWrapper::constant_directonly);
    ClassDB::bind_method(D_METHOD("constant_subtype"), &SqliteWrapper::constant_subtype);
    ClassDB::bind_method(D_METHOD("constant_innocuous"), &SqliteWrapper::constant_innocuous);
    ClassDB::bind_method(D_METHOD("constant_result_subtype"), &SqliteWrapper::constant_result_subtype);
    ClassDB::bind_method(D_METHOD("constant_selforder1"), &SqliteWrapper::constant_selforder1);
    ClassDB::bind_method(D_METHOD("aggregate_count", "context"), &SqliteWrapper::aggregate_count);
    ClassDB::bind_method(D_METHOD("expired", "stmt"), &SqliteWrapper::expired);
    ClassDB::bind_method(D_METHOD("transfer_bindings", "from_stmt", "to_stmt"), &SqliteWrapper::transfer_bindings);
    ClassDB::bind_method(D_METHOD("global_recover"), &SqliteWrapper::global_recover);
    ClassDB::bind_method(D_METHOD("thread_cleanup"), &SqliteWrapper::thread_cleanup);
    ClassDB::bind_method(D_METHOD("memory_alarm", "callback", "threshold"), &SqliteWrapper::memory_alarm);
    ClassDB::bind_method(D_METHOD("value_text", "value"), &SqliteWrapper::value_text);
    ClassDB::bind_method(D_METHOD("value_text16", "value"), &SqliteWrapper::value_text16);
    ClassDB::bind_method(D_METHOD("value_text16le", "value"), &SqliteWrapper::value_text16le);
    ClassDB::bind_method(D_METHOD("value_text16be", "value"), &SqliteWrapper::value_text16be);
    ClassDB::bind_method(D_METHOD("value_bytes16", "value"), &SqliteWrapper::value_bytes16);
    ClassDB::bind_method(D_METHOD("value_type", "value"), &SqliteWrapper::value_type);
    ClassDB::bind_method(D_METHOD("value_numeric_type", "value"), &SqliteWrapper::value_numeric_type);
    ClassDB::bind_method(D_METHOD("value_nochange", "value"), &SqliteWrapper::value_nochange);
    ClassDB::bind_method(D_METHOD("value_frombind", "value"), &SqliteWrapper::value_frombind);
    ClassDB::bind_method(D_METHOD("value_encoding", "value"), &SqliteWrapper::value_encoding);
    ClassDB::bind_method(D_METHOD("value_subtype", "value"), &SqliteWrapper::value_subtype);
    ClassDB::bind_method(D_METHOD("value_dup", "value"), &SqliteWrapper::value_dup);
    ClassDB::bind_method(D_METHOD("aggregate_context", "context", "n_bytes"), &SqliteWrapper::aggregate_context);
    ClassDB::bind_method(D_METHOD("user_data", "context"), &SqliteWrapper::user_data);
    ClassDB::bind_method(D_METHOD("context_db_handle", "context"), &SqliteWrapper::context_db_handle);
    ClassDB::bind_method(D_METHOD("get_auxdata", "context", "n"), &SqliteWrapper::get_auxdata);
    ClassDB::bind_method(D_METHOD("get_clientdata", "db", "name"), &SqliteWrapper::get_clientdata);
    ClassDB::bind_method(D_METHOD("result_error", "context", "message"), &SqliteWrapper::result_error);
    ClassDB::bind_method(D_METHOD("result_error_toobig", "context"), &SqliteWrapper::result_error_toobig);
    ClassDB::bind_method(D_METHOD("result_error_code", "context", "error_code"), &SqliteWrapper::result_error_code);
    ClassDB::bind_method(D_METHOD("result_int", "context", "value"), &SqliteWrapper::result_int);
    ClassDB::bind_method(D_METHOD("result_int64", "context", "value"), &SqliteWrapper::result_int64);
    ClassDB::bind_method(D_METHOD("result_null", "context"), &SqliteWrapper::result_null);
    ClassDB::bind_method(D_METHOD("result_text", "context", "value"), &SqliteWrapper::result_text);
    ClassDB::bind_method(D_METHOD("result_text64", "context", "value", "encoding"), &SqliteWrapper::result_text64);
    ClassDB::bind_method(D_METHOD("result_text16", "context", "value"), &SqliteWrapper::result_text16);
    ClassDB::bind_method(D_METHOD("result_text16le", "context", "value"), &SqliteWrapper::result_text16le);
    ClassDB::bind_method(D_METHOD("result_text16be", "context", "value"), &SqliteWrapper::result_text16be);
    ClassDB::bind_method(D_METHOD("result_pointer", "context", "value", "type_name"), &SqliteWrapper::result_pointer);
    ClassDB::bind_method(D_METHOD("result_zeroblob", "context", "n"), &SqliteWrapper::result_zeroblob);
    ClassDB::bind_method(D_METHOD("result_zeroblob64", "context", "n"), &SqliteWrapper::result_zeroblob64);
    ClassDB::bind_method(D_METHOD("result_subtype", "context", "subtype"), &SqliteWrapper::result_subtype);
    ClassDB::bind_method(D_METHOD("create_collation", "db", "name", "text_rep", "compare_func"), &SqliteWrapper::create_collation);
    ClassDB::bind_method(D_METHOD("create_collation16", "db", "name", "text_rep", "compare_func"), &SqliteWrapper::create_collation16);
    ClassDB::bind_method(D_METHOD("collation_needed", "db", "callback"), &SqliteWrapper::collation_needed);
    ClassDB::bind_method(D_METHOD("activate_cerod", "passphrase"), &SqliteWrapper::activate_cerod);
    ClassDB::bind_method(D_METHOD("sleep", "milliseconds"), &SqliteWrapper::sleep);
    ClassDB::bind_method(D_METHOD("db_handle", "stmt"), &SqliteWrapper::db_handle);
    ClassDB::bind_method(D_METHOD("db_name", "db", "n"), &SqliteWrapper::db_name);
    ClassDB::bind_method(D_METHOD("db_filename", "db", "db_name"), &SqliteWrapper::db_filename);
    ClassDB::bind_method(D_METHOD("db_readonly", "db", "db_name"), &SqliteWrapper::db_readonly);
    ClassDB::bind_method(D_METHOD("txn_state", "db", "schema"), &SqliteWrapper::txn_state);
    ClassDB::bind_method(D_METHOD("constant_txn_none"), &SqliteWrapper::constant_txn_none);
    ClassDB::bind_method(D_METHOD("constant_txn_read"), &SqliteWrapper::constant_txn_read);
    ClassDB::bind_method(D_METHOD("constant_txn_write"), &SqliteWrapper::constant_txn_write);
    ClassDB::bind_method(D_METHOD("commit_hook", "db", "callback", "user_data"), &SqliteWrapper::commit_hook);
    ClassDB::bind_method(D_METHOD("autovacuum_pages", "db", "callback", "user_data"), &SqliteWrapper::autovacuum_pages);
    ClassDB::bind_method(D_METHOD("update_hook", "db", "callback", "user_data"), &SqliteWrapper::update_hook);
    ClassDB::bind_method(D_METHOD("enable_shared_cache", "enable"), &SqliteWrapper::enable_shared_cache);
    ClassDB::bind_method(D_METHOD("table_column_metadata", "db", "database_name", "table_name", "column_name"), &SqliteWrapper::table_column_metadata);
    ClassDB::bind_method(D_METHOD("enable_load_extension", "db", "enable"), &SqliteWrapper::enable_load_extension);
    ClassDB::bind_method(D_METHOD("auto_extension", "entry_point"), &SqliteWrapper::auto_extension);
    ClassDB::bind_method(D_METHOD("overload_function", "db", "func_name", "n_arg"), &SqliteWrapper::overload_function);
    ClassDB::bind_method(D_METHOD("blob_reopen", "blob", "row_id"), &SqliteWrapper::blob_reopen);
    ClassDB::bind_method(D_METHOD("blob_close", "blob"), &SqliteWrapper::blob_close);
    ClassDB::bind_method(D_METHOD("blob_bytes", "blob"), &SqliteWrapper::blob_bytes);
    ClassDB::bind_method(D_METHOD("blob_read", "blob", "size", "offset"), &SqliteWrapper::blob_read);
    ClassDB::bind_method(D_METHOD("blob_write", "blob", "data", "offset"), &SqliteWrapper::blob_write);
    ClassDB::bind_method(D_METHOD("vfs_find", "vfs_name"), &SqliteWrapper::vfs_find);
    ClassDB::bind_method(D_METHOD("mutex_held", "mutex"), &SqliteWrapper::mutex_held);
    ClassDB::bind_method(D_METHOD("mutex_notheld", "mutex"), &SqliteWrapper::mutex_notheld);
    ClassDB::bind_method(D_METHOD("mutex_fast"), &SqliteWrapper::mutex_fast);
    ClassDB::bind_method(D_METHOD("mutex_recursive"), &SqliteWrapper::mutex_recursive);
    ClassDB::bind_method(D_METHOD("mutex_static_main"), &SqliteWrapper::mutex_static_main);
    ClassDB::bind_method(D_METHOD("mutex_static_mem"), &SqliteWrapper::mutex_static_mem);
    ClassDB::bind_method(D_METHOD("mutex_static_mem2"), &SqliteWrapper::mutex_static_mem2);
    ClassDB::bind_method(D_METHOD("mutex_static_open"), &SqliteWrapper::mutex_static_open);
    ClassDB::bind_method(D_METHOD("mutex_static_prng"), &SqliteWrapper::mutex_static_prng);
    ClassDB::bind_method(D_METHOD("mutex_static_lru"), &SqliteWrapper::mutex_static_lru);
    ClassDB::bind_method(D_METHOD("mutex_static_lru2"), &SqliteWrapper::mutex_static_lru2);
    ClassDB::bind_method(D_METHOD("mutex_static_pmem"), &SqliteWrapper::mutex_static_pmem);
    ClassDB::bind_method(D_METHOD("mutex_static_app1"), &SqliteWrapper::mutex_static_app1);
    ClassDB::bind_method(D_METHOD("mutex_static_app2"), &SqliteWrapper::mutex_static_app2);
    ClassDB::bind_method(D_METHOD("mutex_static_app3"), &SqliteWrapper::mutex_static_app3);
    ClassDB::bind_method(D_METHOD("mutex_static_vfs1"), &SqliteWrapper::mutex_static_vfs1);
    ClassDB::bind_method(D_METHOD("mutex_static_vfs2"), &SqliteWrapper::mutex_static_vfs2);
    ClassDB::bind_method(D_METHOD("mutex_static_vfs3"), &SqliteWrapper::mutex_static_vfs3);
    ClassDB::bind_method(D_METHOD("mutex_static_master"), &SqliteWrapper::mutex_static_master);
    ClassDB::bind_method(D_METHOD("file_control", "db", "db_name", "op", "arg"), &SqliteWrapper::file_control);
    ClassDB::bind_method(D_METHOD("test_control", "op"), &SqliteWrapper::test_control);
    ClassDB::bind_method(D_METHOD("str_finish", "str"), &SqliteWrapper::str_finish);
    ClassDB::bind_method(D_METHOD("db_status_lookaside_used"), &SqliteWrapper::db_status_lookaside_used);
    ClassDB::bind_method(D_METHOD("db_status_cache_used"), &SqliteWrapper::db_status_cache_used);
    ClassDB::bind_method(D_METHOD("db_status_schema_used"), &SqliteWrapper::db_status_schema_used);
    ClassDB::bind_method(D_METHOD("db_status_stmt_used"), &SqliteWrapper::db_status_stmt_used);
    ClassDB::bind_method(D_METHOD("db_status_lookaside_hit"), &SqliteWrapper::db_status_lookaside_hit);
    ClassDB::bind_method(D_METHOD("db_status_lookaside_miss_size"), &SqliteWrapper::db_status_lookaside_miss_size);
    ClassDB::bind_method(D_METHOD("db_status_lookaside_miss_full"), &SqliteWrapper::db_status_lookaside_miss_full);
    ClassDB::bind_method(D_METHOD("db_status_cache_hit"), &SqliteWrapper::db_status_cache_hit);
    ClassDB::bind_method(D_METHOD("db_status_cache_miss"), &SqliteWrapper::db_status_cache_miss);
    ClassDB::bind_method(D_METHOD("db_status_cache_write"), &SqliteWrapper::db_status_cache_write);
    ClassDB::bind_method(D_METHOD("db_status_deferred_fks"), &SqliteWrapper::db_status_deferred_fks);
    ClassDB::bind_method(D_METHOD("db_status_cache_used_shared"), &SqliteWrapper::db_status_cache_used_shared);
    ClassDB::bind_method(D_METHOD("db_status_cache_spill"), &SqliteWrapper::db_status_cache_spill);
    ClassDB::bind_method(D_METHOD("db_status_tempbuf_spill"), &SqliteWrapper::db_status_tempbuf_spill);
    ClassDB::bind_method(D_METHOD("stmtstatus_fullscan_step"), &SqliteWrapper::stmtstatus_fullscan_step);
    ClassDB::bind_method(D_METHOD("stmtstatus_sort"), &SqliteWrapper::stmtstatus_sort);
    ClassDB::bind_method(D_METHOD("stmtstatus_autoindex"), &SqliteWrapper::stmtstatus_autoindex);
    ClassDB::bind_method(D_METHOD("stmtstatus_vm_step"), &SqliteWrapper::stmtstatus_vm_step);
    ClassDB::bind_method(D_METHOD("stmtstatus_reprepare"), &SqliteWrapper::stmtstatus_reprepare);
    ClassDB::bind_method(D_METHOD("stmtstatus_run"), &SqliteWrapper::stmtstatus_run);
    ClassDB::bind_method(D_METHOD("stmtstatus_filter_miss"), &SqliteWrapper::stmtstatus_filter_miss);
    ClassDB::bind_method(D_METHOD("stmtstatus_filter_hit"), &SqliteWrapper::stmtstatus_filter_hit);
    ClassDB::bind_method(D_METHOD("stmtstatus_memused"), &SqliteWrapper::stmtstatus_memused);
    ClassDB::bind_method(D_METHOD("backup_pagecount", "backup"), &SqliteWrapper::backup_pagecount);
    ClassDB::bind_method(D_METHOD("str_icmp", "a", "b"), &SqliteWrapper::str_icmp);
    ClassDB::bind_method(D_METHOD("wal_autocheckpoint", "db", "threshold"), &SqliteWrapper::wal_autocheckpoint);
    ClassDB::bind_method(D_METHOD("wal_checkpoint", "db", "database_name"), &SqliteWrapper::wal_checkpoint);
    ClassDB::bind_method(D_METHOD("wal_checkpoint_v2", "db", "database_name", "mode"), &SqliteWrapper::wal_checkpoint_v2);
    ClassDB::bind_method(D_METHOD("checkpoint_noop"), &SqliteWrapper::checkpoint_noop);
    ClassDB::bind_method(D_METHOD("checkpoint_passive"), &SqliteWrapper::checkpoint_passive);
    ClassDB::bind_method(D_METHOD("checkpoint_full"), &SqliteWrapper::checkpoint_full);
    ClassDB::bind_method(D_METHOD("checkpoint_restart"), &SqliteWrapper::checkpoint_restart);
    ClassDB::bind_method(D_METHOD("checkpoint_truncate"), &SqliteWrapper::checkpoint_truncate);
    ClassDB::bind_method(D_METHOD("vtab_constraint_support"), &SqliteWrapper::vtab_constraint_support);
    ClassDB::bind_method(D_METHOD("vtab_innocuous"), &SqliteWrapper::vtab_innocuous);
    ClassDB::bind_method(D_METHOD("vtab_directonly"), &SqliteWrapper::vtab_directonly);
    ClassDB::bind_method(D_METHOD("vtab_uses_all_schemas"), &SqliteWrapper::vtab_uses_all_schemas);
    ClassDB::bind_method(D_METHOD("vtab_nochange", "context"), &SqliteWrapper::vtab_nochange);
    ClassDB::bind_method(D_METHOD("vtab_collation", "info", "idx"), &SqliteWrapper::vtab_collation);
    ClassDB::bind_method(D_METHOD("vtab_rhs_value", "info", "idx", "out_value"), &SqliteWrapper::vtab_rhs_value);
#if 0
    ClassDB::bind_method(D_METHOD("stmt_scanstatus_v2", "stmt", "idx", "scan_status_op", "flags", "out_value"), &SqliteWrapper::stmt_scanstatus_v2);
    ClassDB::bind_method(D_METHOD("stmt_scanstatus_reset", "stmt"), &SqliteWrapper::stmt_scanstatus_reset);
#endif
    ClassDB::bind_method(D_METHOD("db_cacheflush", "db"), &SqliteWrapper::db_cacheflush);
    ClassDB::bind_method(D_METHOD("preupdate_hook", "db", "callback"), &SqliteWrapper::preupdate_hook);
    ClassDB::bind_method(D_METHOD("preupdate_count", "db"), &SqliteWrapper::preupdate_count);
    ClassDB::bind_method(D_METHOD("preupdate_depth", "db"), &SqliteWrapper::preupdate_depth);
    ClassDB::bind_method(D_METHOD("preupdate_old", "db", "column_index"), &SqliteWrapper::preupdate_old);
    ClassDB::bind_method(D_METHOD("preupdate_new", "db", "column_index"), &SqliteWrapper::preupdate_new);
    ClassDB::bind_method(D_METHOD("preupdate_blobwrite", "db"), &SqliteWrapper::preupdate_blobwrite);
    ClassDB::bind_method(D_METHOD("system_errno", "db"), &SqliteWrapper::system_errno);
    ClassDB::bind_method(D_METHOD("serialize", "db", "schema", "flags"), &SqliteWrapper::serialize);
    ClassDB::bind_method(D_METHOD("serialize_flag_nocopy"), &SqliteWrapper::serialize_flag_nocopy);
    ClassDB::bind_method(D_METHOD("deserialize_flag_freeonclose"), &SqliteWrapper::deserialize_flag_freeonclose);
    ClassDB::bind_method(D_METHOD("deserialize_flag_resizeable"), &SqliteWrapper::deserialize_flag_resizeable);
    ClassDB::bind_method(D_METHOD("deserialize_flag_readonly"), &SqliteWrapper::deserialize_flag_readonly);
#if 0
    ClassDB::bind_method(D_METHOD("carray_bind", "stmt", "index", "data", "n_data", "flags"), &SqliteWrapper::carray_bind);
#endif
    ClassDB::bind_method(D_METHOD("carray_type_int32"), &SqliteWrapper::carray_type_int32);
    ClassDB::bind_method(D_METHOD("carray_type_int64"), &SqliteWrapper::carray_type_int64);
    ClassDB::bind_method(D_METHOD("carray_type_double"), &SqliteWrapper::carray_type_double);
    ClassDB::bind_method(D_METHOD("carray_type_text"), &SqliteWrapper::carray_type_text);
    ClassDB::bind_method(D_METHOD("carray_type_blob"), &SqliteWrapper::carray_type_blob);
    ClassDB::bind_method(D_METHOD("session_delete", "session"), &SqliteWrapper::session_delete);
    ClassDB::bind_method(D_METHOD("mutex_alloc", "type"), &SqliteWrapper::mutex_alloc);
    ClassDB::bind_method(D_METHOD("str_appendf", "str", "format"), &SqliteWrapper::str_appendf);
    ClassDB::bind_method(D_METHOD("str_errcode", "str"), &SqliteWrapper::str_errcode);
    ClassDB::bind_method(D_METHOD("status", "op", "reset_flag"), &SqliteWrapper::status);
    ClassDB::bind_method(D_METHOD("snapshot_open", "db", "schema", "snapshot"), &SqliteWrapper::snapshot_open);
    ClassDB::bind_method(D_METHOD("snapshot_cmp", "p1", "p2"), &SqliteWrapper::snapshot_cmp);
    ClassDB::bind_method(D_METHOD("snapshot_recover", "db", "schema"), &SqliteWrapper::snapshot_recover);
    ClassDB::bind_method(D_METHOD("session_object_config", "session", "op", "p_arg"), &SqliteWrapper::session_object_config);
    ClassDB::bind_method(D_METHOD("session_objconfig_size"), &SqliteWrapper::session_objconfig_size);
    ClassDB::bind_method(D_METHOD("session_objconfig_rowid"), &SqliteWrapper::session_objconfig_rowid);
    ClassDB::bind_method(D_METHOD("session_indirect", "session", "b_indirect"), &SqliteWrapper::session_indirect);
    ClassDB::bind_method(D_METHOD("session_attach", "session", "z_tab"), &SqliteWrapper::session_attach);
    ClassDB::bind_method(D_METHOD("session_table_filter", "session", "filter"), &SqliteWrapper::session_table_filter);
    ClassDB::bind_method(D_METHOD("session_changeset", "session", "out_changeset", "out_size"), &SqliteWrapper::session_changeset);
    ClassDB::bind_method(D_METHOD("session_changeset_size", "session"), &SqliteWrapper::session_changeset_size);
    ClassDB::bind_method(D_METHOD("session_diff", "session", "z_from_db", "z_tbl", "out_error"), &SqliteWrapper::session_diff);
    ClassDB::bind_method(D_METHOD("session_patchset", "session", "out_patchset", "out_size"), &SqliteWrapper::session_patchset);
    ClassDB::bind_method(D_METHOD("session_isempty", "session"), &SqliteWrapper::session_isempty);
    ClassDB::bind_method(D_METHOD("changeset_start", "out_iter", "changeset"), &SqliteWrapper::changeset_start);
    ClassDB::bind_method(D_METHOD("changeset_start_invert_flag"), &SqliteWrapper::changeset_start_invert_flag);
    ClassDB::bind_method(D_METHOD("changeset_op", "iter", "out_table", "out_col_count", "out_op", "out_indirect"), &SqliteWrapper::changeset_op);
    ClassDB::bind_method(D_METHOD("changeset_pk", "iter", "out_pk", "out_col_count"), &SqliteWrapper::changeset_pk);
    ClassDB::bind_method(D_METHOD("changeset_old", "iter", "i_val", "out_value"), &SqliteWrapper::changeset_old);
    ClassDB::bind_method(D_METHOD("changeset_new", "iter", "i_val", "out_value"), &SqliteWrapper::changeset_new);
    ClassDB::bind_method(D_METHOD("changeset_conflict", "iter", "i_val", "out_value"), &SqliteWrapper::changeset_conflict);
    ClassDB::bind_method(D_METHOD("changeset_fk_conflicts", "iter"), &SqliteWrapper::changeset_fk_conflicts);
    ClassDB::bind_method(D_METHOD("changeset_finalize", "iter"), &SqliteWrapper::changeset_finalize);
    ClassDB::bind_method(D_METHOD("changeset_invert", "input"), &SqliteWrapper::changeset_invert);
    ClassDB::bind_method(D_METHOD("changegroup_schema", "changegroup", "db", "db_name"), &SqliteWrapper::changegroup_schema);
    ClassDB::bind_method(D_METHOD("changegroup_add", "changegroup", "input"), &SqliteWrapper::changegroup_add);
    ClassDB::bind_method(D_METHOD("changegroup_add_change", "changegroup", "iter"), &SqliteWrapper::changegroup_add_change);
    ClassDB::bind_method(D_METHOD("changegroup_output", "changegroup"), &SqliteWrapper::changegroup_output);
    ClassDB::bind_method(D_METHOD("changeset_apply", "db", "changeset", "filter_callback", "conflict_callback"), &SqliteWrapper::changeset_apply);
    ClassDB::bind_method(D_METHOD("changeset_apply_v2", "db", "changeset", "filter_callback", "conflict_callback", "rebase_data", "flags"), &SqliteWrapper::changeset_apply_v2);
    ClassDB::bind_method(D_METHOD("changeset_apply_v3", "db", "changeset", "filter_callback", "conflict_callback", "rebase_data", "flags"), &SqliteWrapper::changeset_apply_v3);
    ClassDB::bind_method(D_METHOD("changeset_apply_flag_no_savepoint"), &SqliteWrapper::changeset_apply_flag_no_savepoint);
    ClassDB::bind_method(D_METHOD("changeset_apply_flag_invert"), &SqliteWrapper::changeset_apply_flag_invert);
    ClassDB::bind_method(D_METHOD("changeset_apply_flag_ignore_noop"), &SqliteWrapper::changeset_apply_flag_ignore_noop);
    ClassDB::bind_method(D_METHOD("changeset_apply_flag_fk_no_action"), &SqliteWrapper::changeset_apply_flag_fk_no_action);
    ClassDB::bind_method(D_METHOD("changeset_conflict_type_data"), &SqliteWrapper::changeset_conflict_type_data);
    ClassDB::bind_method(D_METHOD("changeset_conflict_type_not_found"), &SqliteWrapper::changeset_conflict_type_not_found);
    ClassDB::bind_method(D_METHOD("changeset_conflict_type_conflict"), &SqliteWrapper::changeset_conflict_type_conflict);
    ClassDB::bind_method(D_METHOD("changeset_conflict_type_constraint"), &SqliteWrapper::changeset_conflict_type_constraint);
    ClassDB::bind_method(D_METHOD("changeset_conflict_type_foreign_key"), &SqliteWrapper::changeset_conflict_type_foreign_key);
    ClassDB::bind_method(D_METHOD("changeset_conflict_result_omit"), &SqliteWrapper::changeset_conflict_result_omit);
    ClassDB::bind_method(D_METHOD("changeset_conflict_result_replace"), &SqliteWrapper::changeset_conflict_result_replace);
    ClassDB::bind_method(D_METHOD("changeset_conflict_result_abort"), &SqliteWrapper::changeset_conflict_result_abort);
    ClassDB::bind_method(D_METHOD("rebaser_rebase", "rebaser", "changeset"), &SqliteWrapper::rebaser_rebase);
    ClassDB::bind_method(D_METHOD("changegroup_output_stream", "changegroup"), &SqliteWrapper::changegroup_output_stream);
    ClassDB::bind_method(D_METHOD("changeset_apply_stream", "db", "changeset", "filter_callback", "conflict_callback"), &SqliteWrapper::changeset_apply_stream);
    ClassDB::bind_method(D_METHOD("changeset_apply_v2_stream", "db", "changeset", "filter_callback", "conflict_callback", "rebase_data", "flags"), &SqliteWrapper::changeset_apply_v2_stream);
    ClassDB::bind_method(D_METHOD("changeset_apply_v3_stream", "db", "changeset", "filter_callback", "conflict_callback", "rebase_data", "flags"), &SqliteWrapper::changeset_apply_v3_stream);
    ClassDB::bind_method(D_METHOD("changeset_invert_stream", "changeset"), &SqliteWrapper::changeset_invert_stream);
    ClassDB::bind_method(D_METHOD("changeset_start_stream", "changeset"), &SqliteWrapper::changeset_start_stream);
    ClassDB::bind_method(D_METHOD("session_config_stream_size", "new_size"), &SqliteWrapper::session_config_stream_size);
    ClassDB::bind_method(D_METHOD("rebaser_rebase_stream", "rebaser", "input_data"), &SqliteWrapper::rebaser_rebase_stream);
    ClassDB::bind_method(D_METHOD("fts5_tokenize_query"), &SqliteWrapper::fts5_tokenize_query);
    ClassDB::bind_method(D_METHOD("fts5_tokenize_prefix"), &SqliteWrapper::fts5_tokenize_prefix);
    ClassDB::bind_method(D_METHOD("fts5_tokenize_document"), &SqliteWrapper::fts5_tokenize_document);
    ClassDB::bind_method(D_METHOD("fts5_tokenize_aux"), &SqliteWrapper::fts5_tokenize_aux);
    ClassDB::bind_method(D_METHOD("fts5_token_colocated"), &SqliteWrapper::fts5_token_colocated);
    ClassDB::bind_method(D_METHOD("create_module_v2", "db", "name", "module", "client_data", "destructor"), &SqliteWrapper::create_module_v2);
    ClassDB::bind_method(D_METHOD("unlock_notify", "db", "on_notify", "user_data"), &SqliteWrapper::unlock_notify);
    ClassDB::bind_method(D_METHOD("declare_vtab", "db", "sql"), &SqliteWrapper::declare_vtab);
    ClassDB::bind_method(D_METHOD("drop_modules", "db", "keep"), &SqliteWrapper::drop_modules);
    ClassDB::bind_method(D_METHOD("vtab_distinct", "info"), &SqliteWrapper::vtab_distinct);
    ClassDB::bind_method(D_METHOD("conflict_rollback"), &SqliteWrapper::conflict_rollback);
    ClassDB::bind_method(D_METHOD("conflict_ignore"), &SqliteWrapper::conflict_ignore);
    ClassDB::bind_method(D_METHOD("conflict_fail"), &SqliteWrapper::conflict_fail);
    ClassDB::bind_method(D_METHOD("conflict_replace"), &SqliteWrapper::conflict_replace);
    ClassDB::bind_method(D_METHOD("stmt_scanstat_nloop"), &SqliteWrapper::stmt_scanstat_nloop);
    ClassDB::bind_method(D_METHOD("stmt_scanstat_nvisit"), &SqliteWrapper::stmt_scanstat_nvisit);
    ClassDB::bind_method(D_METHOD("stmt_scanstat_est"), &SqliteWrapper::stmt_scanstat_est);
    ClassDB::bind_method(D_METHOD("stmt_scanstat_name"), &SqliteWrapper::stmt_scanstat_name);
    ClassDB::bind_method(D_METHOD("stmt_scanstat_explain"), &SqliteWrapper::stmt_scanstat_explain);
    ClassDB::bind_method(D_METHOD("stmt_scanstat_selectid"), &SqliteWrapper::stmt_scanstat_selectid);
    ClassDB::bind_method(D_METHOD("stmt_scanstat_parentid"), &SqliteWrapper::stmt_scanstat_parentid);
    ClassDB::bind_method(D_METHOD("stmt_scanstat_ncycle"), &SqliteWrapper::stmt_scanstat_ncycle);
    ClassDB::bind_method(D_METHOD("vtab_in", "info", "iCons", "bHandle"), &SqliteWrapper::vtab_in);
    ClassDB::bind_method(D_METHOD("vtab_in_first", "pVal", "out_value"), &SqliteWrapper::vtab_in_first);
}

int SqliteWrapper::version_number(void) {
    return SQLITE_VERSION_NUMBER;
}

String SqliteWrapper::version(void) {
    return String(SQLITE_VERSION);
}

String SqliteWrapper::get_sqlite3_version(void) {
    return String(sqlite3_version);
}

String SqliteWrapper::sqlite3_libversion(void) {
    return String(sqlite3_libversion());
}

String SqliteWrapper::sqlite3_sourceid(void) {
    return String(sqlite3_sourceid());
}

int SqliteWrapper::sqlite3_libversion_number(void) {
    return sqlite3_libversion_number();
}

int SqliteWrapper::compileoption_used(String option_name) {
    return sqlite3_compileoption_used(option_name.utf8().get_data());
}

String SqliteWrapper::compileoption_get(int index) {
    const char *result = sqlite3_compileoption_get(index);
    return result ? String(result) : String();
}

int SqliteWrapper::sqlite3_threadsafe(void) {
    return sqlite3_threadsafe();
}

int SqliteWrapper::close(Ref<Sqlite3Handle> db) {
    return sqlite3_close(db.is_null() ? nullptr : db->handle);
}

int SqliteWrapper::ok(void) {
    return SQLITE_OK;
}

int SqliteWrapper::error(void) {
    return SQLITE_ERROR;
}

int SqliteWrapper::internal(void) {
    return SQLITE_INTERNAL;
}

int SqliteWrapper::perm(void) {
    return SQLITE_PERM;
}

int SqliteWrapper::abort(void) {
    return SQLITE_ABORT;
}

int SqliteWrapper::busy(void) {
    return SQLITE_BUSY;
}

int SqliteWrapper::locked(void) {
    return SQLITE_LOCKED;
}

int SqliteWrapper::nomem(void) {
    return SQLITE_NOMEM;
}

int SqliteWrapper::readonly(void) {
    return SQLITE_READONLY;
}

int SqliteWrapper::interrupt(void) {
    return SQLITE_INTERRUPT;
}

int SqliteWrapper::ioerr(void) {
    return SQLITE_IOERR;
}

int SqliteWrapper::corrupt(void) {
    return SQLITE_CORRUPT;
}

int SqliteWrapper::notfound(void) {
    return SQLITE_NOTFOUND;
}

int SqliteWrapper::full(void) {
    return SQLITE_FULL;
}

int SqliteWrapper::cantopen(void) {
    return SQLITE_CANTOPEN;
}

int SqliteWrapper::protocol(void) {
    return SQLITE_PROTOCOL;
}

int SqliteWrapper::empty(void) {
    return SQLITE_EMPTY;
}

int SqliteWrapper::schema(void) {
    return SQLITE_SCHEMA;
}

int SqliteWrapper::toobig(void) {
    return SQLITE_TOOBIG;
}

int SqliteWrapper::constraint(void) {
    return SQLITE_CONSTRAINT;
}

int SqliteWrapper::mismatch(void) {
    return SQLITE_MISMATCH;
}

int SqliteWrapper::misuse(void) {
    return SQLITE_MISUSE;
}

int SqliteWrapper::nolfs(void) {
    return SQLITE_NOLFS;
}

int SqliteWrapper::auth(void) {
    return SQLITE_AUTH;
}

int SqliteWrapper::format(void) {
    return SQLITE_FORMAT;
}

int SqliteWrapper::range(void) {
    return SQLITE_RANGE;
}

int SqliteWrapper::notadb(void) {
    return SQLITE_NOTADB;
}

int SqliteWrapper::notice(void) {
    return SQLITE_NOTICE;
}

int SqliteWrapper::warning(void) {
    return SQLITE_WARNING;
}

int SqliteWrapper::row(void) {
    return SQLITE_ROW;
}

int SqliteWrapper::done(void) {
    return SQLITE_DONE;
}

int SqliteWrapper::open_readonly(void) {
    return SQLITE_OPEN_READONLY;
}

int SqliteWrapper::open_readwrite(void) {
    return SQLITE_OPEN_READWRITE;
}

int SqliteWrapper::open_create(void) {
    return SQLITE_OPEN_CREATE;
}

int SqliteWrapper::open_memory(void) {
    return SQLITE_OPEN_MEMORY;
}

int SqliteWrapper::open_uri(void) {
    return SQLITE_OPEN_URI;
}

int SqliteWrapper::open_nomutex(void) {
    return SQLITE_OPEN_NOMUTEX;
}

int SqliteWrapper::open_fullmutex(void) {
    return SQLITE_OPEN_FULLMUTEX;
}

int SqliteWrapper::open_sharedcache(void) {
    return SQLITE_OPEN_SHAREDCACHE;
}

int SqliteWrapper::open_privatecache(void) {
    return SQLITE_OPEN_PRIVATECACHE;
}

int SqliteWrapper::open_nofollow(void) {
    return SQLITE_OPEN_NOFOLLOW;
}

int SqliteWrapper::fcntl_lockstate(void) {
    return SQLITE_FCNTL_LOCKSTATE;
}

int SqliteWrapper::fcntl_get_lockproxyfile(void) {
    return SQLITE_FCNTL_GET_LOCKPROXYFILE;
}

int SqliteWrapper::fcntl_set_lockproxyfile(void) {
    return SQLITE_FCNTL_SET_LOCKPROXYFILE;
}

int SqliteWrapper::fcntl_last_errno(void) {
    return SQLITE_FCNTL_LAST_ERRNO;
}

int SqliteWrapper::fcntl_size_hint(void) {
    return SQLITE_FCNTL_SIZE_HINT;
}

int SqliteWrapper::fcntl_chunk_size(void) {
    return SQLITE_FCNTL_CHUNK_SIZE;
}

int SqliteWrapper::fcntl_file_pointer(void) {
    return SQLITE_FCNTL_FILE_POINTER;
}

int SqliteWrapper::fcntl_sync_omitted(void) {
    return SQLITE_FCNTL_SYNC_OMITTED;
}

int SqliteWrapper::fcntl_win32_av_retry(void) {
    return SQLITE_FCNTL_WIN32_AV_RETRY;
}

int SqliteWrapper::fcntl_persist_wal(void) {
    return SQLITE_FCNTL_PERSIST_WAL;
}

int SqliteWrapper::fcntl_overwrite(void) {
    return SQLITE_FCNTL_OVERWRITE;
}

int SqliteWrapper::fcntl_vfsname(void) {
    return SQLITE_FCNTL_VFSNAME;
}

int SqliteWrapper::fcntl_powersafe_overwrite(void) {
    return SQLITE_FCNTL_POWERSAFE_OVERWRITE;
}

int SqliteWrapper::fcntl_pragma(void) {
    return SQLITE_FCNTL_PRAGMA;
}

int SqliteWrapper::fcntl_busyhandler(void) {
    return SQLITE_FCNTL_BUSYHANDLER;
}

int SqliteWrapper::fcntl_tempfilename(void) {
    return SQLITE_FCNTL_TEMPFILENAME;
}

int SqliteWrapper::fcntl_mmap_size(void) {
    return SQLITE_FCNTL_MMAP_SIZE;
}

int SqliteWrapper::fcntl_trace(void) {
    return SQLITE_FCNTL_TRACE;
}

int SqliteWrapper::fcntl_has_moved(void) {
    return SQLITE_FCNTL_HAS_MOVED;
}

int SqliteWrapper::fcntl_sync(void) {
    return SQLITE_FCNTL_SYNC;
}

int SqliteWrapper::fcntl_commit_phasetwo(void) {
    return SQLITE_FCNTL_COMMIT_PHASETWO;
}

int SqliteWrapper::fcntl_win32_set_handle(void) {
    return SQLITE_FCNTL_WIN32_SET_HANDLE;
}

int SqliteWrapper::fcntl_wal_block(void) {
    return SQLITE_FCNTL_WAL_BLOCK;
}

int SqliteWrapper::fcntl_zipvfs(void) {
    return SQLITE_FCNTL_ZIPVFS;
}

int SqliteWrapper::fcntl_rbu(void) {
    return SQLITE_FCNTL_RBU;
}

int SqliteWrapper::fcntl_vfs_pointer(void) {
    return SQLITE_FCNTL_VFS_POINTER;
}

int SqliteWrapper::fcntl_journal_pointer(void) {
    return SQLITE_FCNTL_JOURNAL_POINTER;
}

int SqliteWrapper::fcntl_win32_get_handle(void) {
    return SQLITE_FCNTL_WIN32_GET_HANDLE;
}

int SqliteWrapper::fcntl_pdb(void) {
    return SQLITE_FCNTL_PDB;
}

int SqliteWrapper::fcntl_begin_atomic_write(void) {
    return SQLITE_FCNTL_BEGIN_ATOMIC_WRITE;
}

int SqliteWrapper::fcntl_commit_atomic_write(void) {
    return SQLITE_FCNTL_COMMIT_ATOMIC_WRITE;
}

int SqliteWrapper::fcntl_rollback_atomic_write(void) {
    return SQLITE_FCNTL_ROLLBACK_ATOMIC_WRITE;
}

int SqliteWrapper::fcntl_lock_timeout(void) {
    return SQLITE_FCNTL_LOCK_TIMEOUT;
}

int SqliteWrapper::fcntl_data_version(void) {
    return SQLITE_FCNTL_DATA_VERSION;
}

int SqliteWrapper::fcntl_size_limit(void) {
    return SQLITE_FCNTL_SIZE_LIMIT;
}

int SqliteWrapper::fcntl_ckpt_done(void) {
    return SQLITE_FCNTL_CKPT_DONE;
}

int SqliteWrapper::fcntl_reserve_bytes(void) {
    return SQLITE_FCNTL_RESERVE_BYTES;
}

int SqliteWrapper::fcntl_ckpt_start(void) {
    return SQLITE_FCNTL_CKPT_START;
}

int SqliteWrapper::fcntl_external_reader(void) {
    return SQLITE_FCNTL_EXTERNAL_READER;
}

int SqliteWrapper::fcntl_cks_file(void) {
    return SQLITE_FCNTL_CKSM_FILE;
}

int SqliteWrapper::fcntl_reset_cache(void) {
    return SQLITE_FCNTL_RESET_CACHE;
}

int SqliteWrapper::fcntl_null_io(void) {
    return SQLITE_FCNTL_NULL_IO;
}

int SqliteWrapper::fcntl_block_on_connect(void) {
    return SQLITE_FCNTL_BLOCK_ON_CONNECT;
}

int SqliteWrapper::fcntl_filestat(void) {
    return SQLITE_FCNTL_FILESTAT;
}

int SqliteWrapper::initialize(void) {
    return sqlite3_initialize();
}

int SqliteWrapper::shutdown(void) {
    return sqlite3_shutdown();
}

int SqliteWrapper::os_init(void) {
    return sqlite3_os_init();
}

int SqliteWrapper::os_end(void) {
    return sqlite3_os_end();
}

int SqliteWrapper::access_exists(void) {
    return SQLITE_ACCESS_EXISTS;
}

int SqliteWrapper::access_readwrite(void) {
    return SQLITE_ACCESS_READWRITE;
}

int SqliteWrapper::access_read(void) {
    return SQLITE_ACCESS_READ;
}

int SqliteWrapper::shm_unlock(void) {
    return SQLITE_SHM_UNLOCK;
}

int SqliteWrapper::shm_lock(void) {
    return SQLITE_SHM_LOCK;
}

int SqliteWrapper::shm_shared(void) {
    return SQLITE_SHM_SHARED;
}

int SqliteWrapper::shm_exclusive(void) {
    return SQLITE_SHM_EXCLUSIVE;
}

int SqliteWrapper::shm_nlock(void) {
    return SQLITE_SHM_NLOCK;
}

int64_t SqliteWrapper::total_changes64(Ref<Sqlite3Handle> db) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), 0);
    return sqlite3_total_changes64(db->handle);
}

int SqliteWrapper::config_singlethread(void) {
    return SQLITE_CONFIG_SINGLETHREAD;
}

int SqliteWrapper::config_multithread(void) {
    return SQLITE_CONFIG_MULTITHREAD;
}

int SqliteWrapper::config_serialized(void) {
    return SQLITE_CONFIG_SERIALIZED;
}

int SqliteWrapper::config_malloc(void) {
    return SQLITE_CONFIG_MALLOC;
}

int SqliteWrapper::config_getmalloc(void) {
    return SQLITE_CONFIG_GETMALLOC;
}

int SqliteWrapper::config_scratch(void) {
    return SQLITE_CONFIG_SCRATCH;
}

int SqliteWrapper::config_pagecache(void) {
    return SQLITE_CONFIG_PAGECACHE;
}

int SqliteWrapper::config_heap(void) {
    return SQLITE_CONFIG_HEAP;
}

int SqliteWrapper::config_memstatus(void) {
    return SQLITE_CONFIG_MEMSTATUS;
}

int SqliteWrapper::config_mutex(void) {
    return SQLITE_CONFIG_MUTEX;
}

int SqliteWrapper::config_getmutex(void) {
    return SQLITE_CONFIG_GETMUTEX;
}

int SqliteWrapper::config_lookaside(void) {
    return SQLITE_CONFIG_LOOKASIDE;
}

int SqliteWrapper::config_pcache(void) {
    return SQLITE_CONFIG_PCACHE;
}

int SqliteWrapper::config_getpcache(void) {
    return SQLITE_CONFIG_GETPCACHE;
}

int SqliteWrapper::config_log(void) {
    return SQLITE_CONFIG_LOG;
}

int SqliteWrapper::config_uri(void) {
    return SQLITE_CONFIG_URI;
}

int SqliteWrapper::config_pcache2(void) {
    return SQLITE_CONFIG_PCACHE2;
}

int SqliteWrapper::config_getpcache2(void) {
    return SQLITE_CONFIG_GETPCACHE2;
}

int SqliteWrapper::config_covering_index_scan(void) {
    return SQLITE_CONFIG_COVERING_INDEX_SCAN;
}

int SqliteWrapper::config_sqllog(void) {
    return SQLITE_CONFIG_SQLLOG;
}

int SqliteWrapper::config_mmap_size(void) {
    return SQLITE_CONFIG_MMAP_SIZE;
}

int SqliteWrapper::config_win32_heapsize(void) {
    return SQLITE_CONFIG_WIN32_HEAPSIZE;
}

int SqliteWrapper::config_pcache_hdrsz(void) {
    return SQLITE_CONFIG_PCACHE_HDRSZ;
}

int SqliteWrapper::config_pmasz(void) {
    return SQLITE_CONFIG_PMASZ;
}

int SqliteWrapper::config_stmtjrnl_spill(void) {
    return SQLITE_CONFIG_STMTJRNL_SPILL;
}

int SqliteWrapper::config_small_malloc(void) {
    return SQLITE_CONFIG_SMALL_MALLOC;
}

int SqliteWrapper::config_sorterref_size(void) {
    return SQLITE_CONFIG_SORTERREF_SIZE;
}

int SqliteWrapper::config_memdb_maxsize(void) {
    return SQLITE_CONFIG_MEMDB_MAXSIZE;
}

int SqliteWrapper::config_rowid_in_view(void) {
    return SQLITE_CONFIG_ROWID_IN_VIEW;
}

int SqliteWrapper::dbconfig_maindbname(void) {
    return SQLITE_DBCONFIG_MAINDBNAME;
}

int SqliteWrapper::dbconfig_lookaside(void) {
    return SQLITE_DBCONFIG_LOOKASIDE;
}

int SqliteWrapper::dbconfig_enable_fkey(void) {
    return SQLITE_DBCONFIG_ENABLE_FKEY;
}

int SqliteWrapper::dbconfig_enable_trigger(void) {
    return SQLITE_DBCONFIG_ENABLE_TRIGGER;
}

int SqliteWrapper::dbconfig_enable_fts3_tokenizer(void) {
    return SQLITE_DBCONFIG_ENABLE_FTS3_TOKENIZER;
}

int SqliteWrapper::dbconfig_enable_load_extension(void) {
    return SQLITE_DBCONFIG_ENABLE_LOAD_EXTENSION;
}

int SqliteWrapper::dbconfig_no_ckpt_on_close(void) {
    return SQLITE_DBCONFIG_NO_CKPT_ON_CLOSE;
}

int SqliteWrapper::dbconfig_enable_qpsg(void) {
    return SQLITE_DBCONFIG_ENABLE_QPSG;
}

int SqliteWrapper::dbconfig_trigger_eqp(void) {
    return SQLITE_DBCONFIG_TRIGGER_EQP;
}

int SqliteWrapper::dbconfig_reset_database(void) {
    return SQLITE_DBCONFIG_RESET_DATABASE;
}

int SqliteWrapper::dbconfig_defensive(void) {
    return SQLITE_DBCONFIG_DEFENSIVE;
}

int SqliteWrapper::dbconfig_writable_schema(void) {
    return SQLITE_DBCONFIG_WRITABLE_SCHEMA;
}

int SqliteWrapper::dbconfig_legacy_alter_table(void) {
    return SQLITE_DBCONFIG_LEGACY_ALTER_TABLE;
}

int SqliteWrapper::dbconfig_dqs_dml(void) {
    return SQLITE_DBCONFIG_DQS_DML;
}

int SqliteWrapper::dbconfig_dqs_ddl(void) {
    return SQLITE_DBCONFIG_DQS_DDL;
}

int SqliteWrapper::dbconfig_enable_view(void) {
    return SQLITE_DBCONFIG_ENABLE_VIEW;
}

int SqliteWrapper::dbconfig_legacy_file_format(void) {
    return SQLITE_DBCONFIG_LEGACY_FILE_FORMAT;
}

int SqliteWrapper::dbconfig_trusted_schema(void) {
    return SQLITE_DBCONFIG_TRUSTED_SCHEMA;
}

int SqliteWrapper::dbconfig_stmt_scanstatus(void) {
    return SQLITE_DBCONFIG_STMT_SCANSTATUS;
}

int SqliteWrapper::dbconfig_reverse_scanorder(void) {
    return SQLITE_DBCONFIG_REVERSE_SCANORDER;
}

int SqliteWrapper::dbconfig_enable_attach_create(void) {
    return SQLITE_DBCONFIG_ENABLE_ATTACH_CREATE;
}

int SqliteWrapper::dbconfig_enable_attach_write(void) {
    return SQLITE_DBCONFIG_ENABLE_ATTACH_WRITE;
}

int SqliteWrapper::dbconfig_enable_comments(void) {
    return SQLITE_DBCONFIG_ENABLE_COMMENTS;
}

int SqliteWrapper::dbconfig_fp_digits(void) {
#ifdef SQLITE_DBCONFIG_FP_DIGITS
    return SQLITE_DBCONFIG_FP_DIGITS;
#else
    return -1;
#endif
}

int SqliteWrapper::dbconfig_max(void) {
    return SQLITE_DBCONFIG_MAX;
}

int SqliteWrapper::extended_result_codes(Ref<Sqlite3Handle> db, bool onoff) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    return sqlite3_extended_result_codes(db->handle, onoff ? 1 : 0);
}

int64_t SqliteWrapper::changes64(Ref<Sqlite3Handle> db) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), 0);
    return sqlite3_changes64(db->handle);
}

int SqliteWrapper::complete16(String sql) {
    Char16String utf16 = sql.utf16();
    return sqlite3_complete16(utf16.ptr());
}

int64_t SqliteWrapper::malloc64(uint64_t size) {
    void *ptr = sqlite3_malloc64(size);
    return reinterpret_cast<int64_t>(ptr);
}

int SqliteWrapper::busy_handler(Ref<Sqlite3Handle> db, Callable on_busy) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_ERROR);
    ERR_FAIL_COND_V(!on_busy.is_valid(), SQLITE_ERROR);
    struct _BusyCtx { Callable cb; } ctx{on_busy};
    auto trampoline = [](void* ud, int count) -> int {
        _BusyCtx* ctx = reinterpret_cast<_BusyCtx*>(ud);
        Array args;
        args.push_back(count);
        Variant ret = ctx->cb.callv(args);
        if (ret.get_type() == Variant::INT) {
            return int(ret);
        }
        return 0;
    };
    return sqlite3_busy_handler(db->handle, trampoline, &ctx);
}

void SqliteWrapper::free_table(int64_t result_ptr) {
    char **result = reinterpret_cast<char**>(static_cast<intptr_t>(result_ptr));
    sqlite3_free_table(result);
}

bool SqliteWrapper::is_interrupted(Ref<Sqlite3Handle> db) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), false);
    return sqlite3_is_interrupted(db->handle) != 0;
}

void SqliteWrapper::free_ptr(int64_t ptr) {
    sqlite3_free(reinterpret_cast<void*>(ptr));
}

int64_t SqliteWrapper::memory_highwater(bool reset) {
    return sqlite3_memory_highwater(reset ? 1 : 0);
}

int64_t SqliteWrapper::realloc(int64_t ptr, int size) {
    void *new_ptr = sqlite3_realloc(reinterpret_cast<void*>(ptr), size);
    return reinterpret_cast<int64_t>(new_ptr);
}

int64_t SqliteWrapper::realloc64(int64_t ptr, uint64_t size) {
    void *new_ptr = sqlite3_realloc64(reinterpret_cast<void*>(ptr), size);
    return reinterpret_cast<int64_t>(new_ptr);
}

int64_t SqliteWrapper::malloc(int size) {
    void *ptr = sqlite3_malloc(size);
    return static_cast<int64_t>(reinterpret_cast<intptr_t>(ptr));
}

int64_t SqliteWrapper::memory_used(void) {
    return sqlite3_memory_used();
}

uint64_t SqliteWrapper::msize(int64_t ptr) {
    return sqlite3_msize(reinterpret_cast<void*>(ptr));
}

void SqliteWrapper::randomness(int length, int64_t buffer_ptr) {
    void *buf = buffer_ptr != 0 ? reinterpret_cast<void*>(buffer_ptr) : nullptr;
    sqlite3_randomness(length, buf);
}

int64_t SqliteWrapper::trace(Ref<Sqlite3Handle> db, Callable callback) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), 0);
    ERR_FAIL_COND_V(!callback.is_valid(), 0);
    struct _TraceCtx { Callable cb; } ctx{callback};
    auto trampoline = [](void* ud, const char* sql) {
        _TraceCtx* ctx = static_cast<_TraceCtx*>(ud);
        String s = sql ? String::utf8(sql) : String();
        ctx->cb.call(s);
    };
    void* result = sqlite3_trace(db->handle, trampoline, &ctx);
    return reinterpret_cast<int64_t>(result);
}

int SqliteWrapper::set_authorizer(Ref<Sqlite3Handle> db, Callable callback) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_ERROR);
    ERR_FAIL_COND_V(!callback.is_valid(), SQLITE_ERROR);
    struct _AuthCtx { Callable cb; } ctx{callback};
    auto trampoline = [](void* ud, int action, const char* arg1, const char* arg2, const char* arg3, const char* arg4) -> int {
        _AuthCtx* ctx = reinterpret_cast<_AuthCtx*>(ud);
        String s1 = arg1 ? String::utf8(arg1) : String();
        String s2 = arg2 ? String::utf8(arg2) : String();
        String s3 = arg3 ? String::utf8(arg3) : String();
        String s4 = arg4 ? String::utf8(arg4) : String();
        Array args;
        args.push_back(action);
        args.push_back(s1);
        args.push_back(s2);
        args.push_back(s3);
        args.push_back(s4);
        Variant ret = ctx->cb.callv(args);
        if (ret.get_type() == Variant::INT) {
            return int(ret);
        }
        return SQLITE_OK;
    };
    return sqlite3_set_authorizer(db->handle, trampoline, &ctx);
}

int SqliteWrapper::trace_v2(Ref<Sqlite3Handle> db, unsigned int mask, Callable callback, int64_t context) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    ERR_FAIL_COND_V(!callback.is_valid(), -1);
    (void)(context);
    struct _TraceV2Ctx { Callable cb; } ctx{callback};
    auto trampoline = [](unsigned event, void* context, void* P, void* X) -> int {
        _TraceV2Ctx* ctx = static_cast<_TraceV2Ctx*>(context);
        int64_t ctx_int = reinterpret_cast<int64_t>(context);
        int64_t p_int = reinterpret_cast<int64_t>(P);
        int64_t x_int = reinterpret_cast<int64_t>(X);
        ctx->cb.call((int)event, ctx_int, p_int, x_int);
        return 0;
    };
    return sqlite3_trace_v2(db->handle, mask, trampoline, &ctx);
}

String SqliteWrapper::uri_parameter(String filename, String param) {
    CharString filename_utf8 = filename.utf8();
    const char* filename_c = filename_utf8.get_data();
    CharString param_utf8 = param.utf8();
    const char* param_c = param_utf8.get_data();
    const char* result = sqlite3_uri_parameter(filename_c, param_c);
    return result ? String::utf8(result) : String();
}

bool SqliteWrapper::uri_boolean(String filename, String param, bool default_value) {
    CharString filename_utf8 = filename.utf8();
    const char* filename_c = filename_utf8.get_data();
    CharString param_utf8 = param.utf8();
    const char* param_c = param_utf8.get_data();
    int result = sqlite3_uri_boolean(filename_c, param_c, default_value ? 1 : 0);
    return result != 0;
}

int64_t SqliteWrapper::uri_int64(String filename, String param, int64_t default_value) {
    CharString filename_utf8 = filename.utf8();
    const char* filename_c = filename_utf8.get_data();
    CharString param_utf8 = param.utf8();
    const char* param_c = param_utf8.get_data();
    return sqlite3_uri_int64(filename_c, param_c, default_value);
}

String SqliteWrapper::uri_key(String filename, int index) {
    CharString filename_utf8 = filename.utf8();
    const char* filename_c = filename_utf8.get_data();
    const char* result = sqlite3_uri_key(filename_c, index);
    return result ? String::utf8(result) : String();
}

String SqliteWrapper::filename_database(String filename) {
    CharString filename_utf8 = filename.utf8();
    const char* filename_c = filename_utf8.get_data();
    const char* result = sqlite3_filename_database(filename_c);
    return result ? String::utf8(result) : String();
}

String SqliteWrapper::errmsg(Ref<Sqlite3Handle> db) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), String());
    const char* result = sqlite3_errmsg(db->handle);
    return result ? String::utf8(result) : String();
}

String SqliteWrapper::filename_wal(String filename) {
    CharString filename_utf8 = filename.utf8();
    const char* filename_c = filename_utf8.get_data();
    const char* result = sqlite3_filename_wal(filename_c);
    return result ? String::utf8(result) : String();
}

int64_t SqliteWrapper::database_file_object(String filename) {
    CharString filename_utf8 = filename.utf8();
    const char* filename_c = filename_utf8.get_data();
    sqlite3_file* result = sqlite3_database_file_object(filename_c);
    return static_cast<int64_t>(reinterpret_cast<intptr_t>(result));
}

int64_t SqliteWrapper::create_filename(String database, String journal, String wal, int param_count, Array params) {
    CharString database_utf8 = database.utf8();
    const char* db_c = database_utf8.get_data();
    CharString journal_utf8 = journal.utf8();
    const char* jnl_c = journal_utf8.get_data();
    CharString wal_utf8 = wal.utf8();
    const char* wal_c = wal_utf8.get_data();
    ERR_FAIL_COND_V(param_count < 0, 0);
    ERR_FAIL_COND_V(params.size() != param_count * 2, 0);
    Vector<CharString> kept_strings;
    kept_strings.resize(param_count * 2);
    const char** param_array = (const char**)malloc(param_count * 2 * sizeof(char*));
    ERR_FAIL_COND_V(!param_array, 0);
    for (int i = 0; i < param_count * 2; i++) {
        String s = params[i];
        if (s.is_empty()) {
            ::free(param_array);
            ERR_FAIL_V(0);
        }
        kept_strings.write[i] = s.utf8();
        param_array[i] = kept_strings[i].get_data();
    }
    const char* result = sqlite3_create_filename(db_c, jnl_c, wal_c, param_count, param_array);
    ::free(param_array);
    return static_cast<int64_t>(reinterpret_cast<intptr_t>(result));
}

void SqliteWrapper::free_filename(int64_t filename_ptr) {
    sqlite3_filename fn = reinterpret_cast<sqlite3_filename>(static_cast<intptr_t>(filename_ptr));
    sqlite3_free_filename(fn);
}

String SqliteWrapper::filename_journal(String filename) {
    CharString filename_utf8 = filename.utf8();
    const char* filename_c = filename_utf8.get_data();
    const char* result = sqlite3_filename_journal(filename_c);
    return result ? String::utf8(result) : String();
}

int SqliteWrapper::extended_errcode(Ref<Sqlite3Handle> db) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_ERROR);
    return sqlite3_extended_errcode(db->handle);
}

int SqliteWrapper::errcode(Ref<Sqlite3Handle> db) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_ERROR);
    return sqlite3_errcode(db->handle);
}

String SqliteWrapper::errstr(int result_code) {
    const char* result = sqlite3_errstr(result_code);
    return result ? String::utf8(result) : String();
}

int SqliteWrapper::limit(Ref<Sqlite3Handle> db, int id, int new_value) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    return sqlite3_limit(db->handle, id, new_value);
}

String SqliteWrapper::get_expanded_sql(Ref<Sqlite3StmtHandle> stmt) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), String());
    char* expanded_c = sqlite3_expanded_sql(stmt->handle);
    String result = expanded_c ? String::utf8(expanded_c) : String();
    if (expanded_c) {
        sqlite3_free(expanded_c);
    }
    return result;
}

int SqliteWrapper::bind_blob(Ref<Sqlite3StmtHandle> stmt, int index, PackedByteArray data) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), SQLITE_ERROR);
    ERR_FAIL_COND_V(index < 1, SQLITE_RANGE);
    if (data.is_empty()) {
        return sqlite3_bind_null(stmt->handle, index);
    }
    PackedByteArray data_copy = data.duplicate();
    void* data_ptr = data_copy.ptrw();
    int len = data_copy.size();
    return sqlite3_bind_blob(stmt->handle, index, data_ptr, len, SQLITE_TRANSIENT);
}

int SqliteWrapper::bind_blob64(Ref<Sqlite3StmtHandle> stmt, int index, PackedByteArray data) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), SQLITE_ERROR);
    ERR_FAIL_COND_V(index < 1, SQLITE_RANGE);
    if (data.is_empty()) {
        return sqlite3_bind_null(stmt->handle, index);
    }
    PackedByteArray data_copy = data.duplicate();
    void* data_ptr = data_copy.ptrw();
    sqlite3_uint64 len = static_cast<sqlite3_uint64>(data_copy.size());
    return sqlite3_bind_blob64(stmt->handle, index, data_ptr, len, SQLITE_TRANSIENT);
}

int SqliteWrapper::bind_int64(Ref<Sqlite3StmtHandle> stmt, int index, int64_t value) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), SQLITE_ERROR);
    ERR_FAIL_COND_V(index < 1, SQLITE_RANGE);
    return sqlite3_bind_int64(stmt->handle, index, value);
}

int SqliteWrapper::bind_zeroblob(Ref<Sqlite3StmtHandle> stmt, int index, int length) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), SQLITE_ERROR);
    ERR_FAIL_COND_V(index < 1, SQLITE_RANGE);
    return sqlite3_bind_zeroblob(stmt->handle, index, length);
}

String SqliteWrapper::column_name16(Ref<Sqlite3StmtHandle> stmt, int index) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), String());
    ERR_FAIL_COND_V(index < 0, String());
    const void* name16 = sqlite3_column_name16(stmt->handle, index);
    if (!name16) {
        return String();
    }
    const char16_t* name16_ptr = static_cast<const char16_t*>(name16);
    return String(name16_ptr);
}

String SqliteWrapper::column_database_name16(Ref<Sqlite3StmtHandle> stmt, int index) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), String());
    ERR_FAIL_COND_V(index < 0, String());
    const void* name16 = sqlite3_column_database_name16(stmt->handle, index);
    if (!name16) {
        return String();
    }
    const char16_t* name16_ptr = static_cast<const char16_t*>(name16);
    return String(name16_ptr);
}

String SqliteWrapper::column_table_name(Ref<Sqlite3StmtHandle> stmt, int index) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), String());
    ERR_FAIL_COND_V(index < 0, String());
    const char* name = sqlite3_column_table_name(stmt->handle, index);
    return name ? String::utf8(name) : String();
}

String SqliteWrapper::column_decltype16(Ref<Sqlite3StmtHandle> stmt, int index) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), String());
    ERR_FAIL_COND_V(index < 0, String());
    const void* type16 = sqlite3_column_decltype16(stmt->handle, index);
    if (!type16) {
        return String();
    }
    const char16_t* type16_ptr = static_cast<const char16_t*>(type16);
    return String(type16_ptr);
}

int SqliteWrapper::constant_text(void) {
    return SQLITE_TEXT;
}

PackedByteArray SqliteWrapper::column_blob(Ref<Sqlite3StmtHandle> stmt, int index) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), PackedByteArray());
    ERR_FAIL_COND_V(index < 0, PackedByteArray());
    const void* blob_ptr = sqlite3_column_blob(stmt->handle, index);
    if (!blob_ptr) {
        return PackedByteArray();
    }
    int len = sqlite3_column_bytes(stmt->handle, index);
    PackedByteArray data;
    data.resize(len);
    void* data_ptr = data.ptrw();
    memcpy(data_ptr, blob_ptr, len);
    return data;
}

double SqliteWrapper::column_double(Ref<Sqlite3StmtHandle> stmt, int index) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), 0.0);
    ERR_FAIL_COND_V(index < 0, 0.0);
    return sqlite3_column_double(stmt->handle, index);
}

int SqliteWrapper::column_int(Ref<Sqlite3StmtHandle> stmt, int index) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), 0);
    ERR_FAIL_COND_V(index < 0, 0);
    return sqlite3_column_int(stmt->handle, index);
}

int64_t SqliteWrapper::column_int64(Ref<Sqlite3StmtHandle> stmt, int index) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), 0);
    ERR_FAIL_COND_V(index < 0, 0);
    return sqlite3_column_int64(stmt->handle, index);
}

PackedByteArray SqliteWrapper::value_blob(Ref<Sqlite3ValueHandle> value) {
    ERR_FAIL_COND_V(value.is_null() || !value->is_valid(), PackedByteArray());
    const void* blob_ptr = sqlite3_value_blob(value->handle);
    if (!blob_ptr) {
        return PackedByteArray();
    }
    int len = sqlite3_value_bytes(value->handle);
    PackedByteArray data;
    data.resize(len);
    void* data_ptr = data.ptrw();
    memcpy(data_ptr, blob_ptr, len);
    return data;
}

double SqliteWrapper::value_double(Ref<Sqlite3ValueHandle> value) {
    ERR_FAIL_COND_V(value.is_null() || !value->is_valid(), 0.0);
    return sqlite3_value_double(value->handle);
}

int SqliteWrapper::value_int(Ref<Sqlite3ValueHandle> value) {
    ERR_FAIL_COND_V(value.is_null() || !value->is_valid(), 0);
    return sqlite3_value_int(value->handle);
}

int64_t SqliteWrapper::value_int64(Ref<Sqlite3ValueHandle> value) {
    ERR_FAIL_COND_V(value.is_null() || !value->is_valid(), 0);
    return sqlite3_value_int64(value->handle);
}

int64_t SqliteWrapper::value_pointer(Ref<Sqlite3ValueHandle> value, String type_name) {
    ERR_FAIL_COND_V(value.is_null() || !value->is_valid(), 0);
    void* ptr = sqlite3_value_pointer(value->handle, type_name.utf8().get_data());
    return static_cast<int64_t>(reinterpret_cast<intptr_t>(ptr));
}

int SqliteWrapper::value_bytes(Ref<Sqlite3ValueHandle> value) {
    ERR_FAIL_COND_V(value.is_null() || !value->is_valid(), 0);
    return sqlite3_value_bytes(value->handle);
}

void SqliteWrapper::value_free(Ref<Sqlite3ValueHandle> value) {
    if (value.is_null() || !value->is_valid()) return;
    sqlite3_value_free(value->handle);
    value->handle = nullptr;
}

void SqliteWrapper::set_auxdata(Ref<Sqlite3ContextHandle> context, int n, uint64_t data) {
    ERR_FAIL_COND(context.is_null() || !context->is_valid());
    void *ptr = reinterpret_cast<void*>(data);
    sqlite3_set_auxdata(context->handle, n, ptr, NULL);
}

int SqliteWrapper::set_clientdata(Ref<Sqlite3Handle> db, String name, uint64_t data) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    void *ptr = reinterpret_cast<void*>(data);
    return sqlite3_set_clientdata(db->handle, name.utf8().get_data(), ptr, NULL);
}

int SqliteWrapper::constant_sqlite_static(void) {
    return 0;
}

int SqliteWrapper::constant_sqlite_transient(void) {
    return -1;
}

void SqliteWrapper::result_blob(Ref<Sqlite3ContextHandle> context, PackedByteArray value) {
    ERR_FAIL_COND(context.is_null() || !context->is_valid());
    int size = value.size();
    if (size > 0) {
        const void *ptr = value.ptr();
        sqlite3_result_blob(context->handle, ptr, size, SQLITE_TRANSIENT);
    } else {
        sqlite3_result_blob(context->handle, nullptr, 0, SQLITE_TRANSIENT);
    }
}

void SqliteWrapper::result_blob64(Ref<Sqlite3ContextHandle> context, PackedByteArray value) {
    ERR_FAIL_COND(context.is_null() || !context->is_valid());
    int size = value.size();
    if (size > 0) {
        const void *ptr = value.ptr();
        sqlite3_result_blob64(context->handle, ptr, (sqlite3_uint64)size, SQLITE_TRANSIENT);
    } else {
        sqlite3_result_blob64(context->handle, nullptr, 0, SQLITE_TRANSIENT);
    }
}

void SqliteWrapper::result_double(Ref<Sqlite3ContextHandle> context, double value) {
    ERR_FAIL_COND(context.is_null() || !context->is_valid());
    sqlite3_result_double(context->handle, value);
}

void SqliteWrapper::result_error16(Ref<Sqlite3ContextHandle> context, String message) {
    ERR_FAIL_COND(context.is_null() || !context->is_valid());
    String msg = message;
    Char16String utf16_msg = msg.utf16();
    sqlite3_result_error16(context->handle, utf16_msg.ptr(), -1);
}

void SqliteWrapper::result_error_nomem(Ref<Sqlite3ContextHandle> context) {
    ERR_FAIL_COND(context.is_null() || !context->is_valid());
    sqlite3_result_error_nomem(context->handle);
}

void SqliteWrapper::result_value(Ref<Sqlite3ContextHandle> context, Ref<Sqlite3ValueHandle> value) {
    ERR_FAIL_COND(context.is_null() || !context->is_valid());
    ERR_FAIL_COND(value.is_null() || !value->is_valid());
    sqlite3_result_value(context->handle, value->handle);
}

int SqliteWrapper::create_collation_v2(Ref<Sqlite3Handle> db, String name, int text_rep, Callable compare_func) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_ERROR);
    ERR_FAIL_COND_V(!compare_func.is_valid(), SQLITE_ERROR);

    struct _CollationCtx {
        Callable cb;
        int text_rep;
    } ctx{compare_func, text_rep};

    auto trampoline = [](void *ud, int len1, const void *data1, int len2, const void *data2) -> int {
        _CollationCtx *ctx = reinterpret_cast<_CollationCtx *>(ud);
        
        String str1, str2;
        
        // Convert based on text representation
        switch (ctx->text_rep) {
            case SQLITE_UTF8:
                str1 = len1 > 0 ? String::utf8((const char*)data1, len1) : String::utf8((const char*)data1);
                str2 = len2 > 0 ? String::utf8((const char*)data2, len2) : String::utf8((const char*)data2);
                break;
            case SQLITE_UTF16:
            case SQLITE_UTF16_ALIGNED:
            case SQLITE_UTF16LE:
            case SQLITE_UTF16BE: {
                const char16_t *ptr1 = (const char16_t*)data1;
                const char16_t *ptr2 = (const char16_t*)data2;
                // For simplicity, treat as native UTF-16
                str1 = len1 > 0 ? String::utf16(ptr1, len1/2) : String::utf16(ptr1);
                str2 = len2 > 0 ? String::utf16(ptr2, len2/2) : String::utf16(ptr2);
                break;
            }
            default:
                return SQLITE_ERROR;
        }
        
        Array args;
        args.push_back(str1);
        args.push_back(str2);
        
        Variant ret = ctx->cb.callv(args);
        if (ret.get_type() != Variant::INT) {
            UtilityFunctions::push_error("compare_func must return int, but got: " + ret.stringify() + " (" + Variant::get_type_name(ret.get_type()) + ")");
            return SQLITE_ERROR;
        }
        return int(ret);
    };

    return sqlite3_create_collation_v2(db->handle, name.utf8().get_data(), text_rep, &ctx, trampoline, nullptr);
}

int SqliteWrapper::collation_needed16(Ref<Sqlite3Handle> db, Callable callback) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_ERROR);
    ERR_FAIL_COND_V(!callback.is_valid(), SQLITE_ERROR);

    struct _CollationNeededCtx {
        Callable cb;
    } ctx{callback};

    auto trampoline = [](void *ud, sqlite3* db_conn, int eTextRep, const void* name) {
        _CollationNeededCtx *ctx = reinterpret_cast<_CollationNeededCtx *>(ud);
        
        Ref<Sqlite3Handle> handle;
        handle->handle = db_conn;
        
        const char16_t *name_ptr = (const char16_t*)name;
        String collation_name = String::utf16(name_ptr);
        
        Array args;
        args.push_back(handle);
        args.push_back(eTextRep);
        args.push_back(collation_name);
        
        ctx->cb.callv(args);
    };

    return sqlite3_collation_needed16(db->handle, &ctx, trampoline);
}

void SqliteWrapper::set_temp_directory(String path) {
    sqlite3_temp_directory = sqlite3_mprintf("%s", path.utf8().get_data());
}

String SqliteWrapper::get_temp_directory(void) {
    if (sqlite3_temp_directory == nullptr) {
        return String();
    }
    return String::utf8(sqlite3_temp_directory);
}

void SqliteWrapper::set_data_directory(String path) {
    sqlite3_data_directory = sqlite3_mprintf("%s", path.utf8().get_data());
}

String SqliteWrapper::get_data_directory(void) {
    if (sqlite3_data_directory == nullptr) {
        return String();
    }
    return String::utf8(sqlite3_data_directory);
}

#if 0
int SqliteWrapper::win32_set_directory(uint32_t type, String value) {
    CharString value_utf8 = value.utf8();
    void *value_ptr = value.length() > 0 ? (void*)value_utf8.get_data() : nullptr;
    return sqlite3_win32_set_directory(type, value_ptr);
}

int SqliteWrapper::win32_set_directory8(uint32_t type, String value) {
    CharString value_utf8 = value.utf8();
    const char * value_ptr = value.length() > 0 ? value_utf8.get_data() : nullptr;
    return sqlite3_win32_set_directory8(type, value_ptr);
}

int SqliteWrapper::win32_set_directory16(uint32_t type, String value) {
    const void *value_ptr = value.length() > 0 ? (const void*)value.utf16().ptr() : nullptr;
    return sqlite3_win32_set_directory16(type, value_ptr);
}
#endif

int SqliteWrapper::constant_win32_data_directory_type(void) {
    return SQLITE_WIN32_DATA_DIRECTORY_TYPE;
}

int SqliteWrapper::constant_win32_temp_directory_type(void) {
    return SQLITE_WIN32_TEMP_DIRECTORY_TYPE;
}

bool SqliteWrapper::get_autocommit(Ref<Sqlite3Handle> db) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), false);
    return sqlite3_get_autocommit(db->handle) != 0;
}

Ref<Sqlite3StmtHandle> SqliteWrapper::next_stmt(Ref<Sqlite3Handle> db, Ref<Sqlite3StmtHandle> stmt) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), Ref<Sqlite3StmtHandle>());
    sqlite3_stmt *next = sqlite3_next_stmt(db->handle, stmt.is_valid() ? stmt->handle : nullptr);
    Ref<Sqlite3StmtHandle> result;
    if (next != nullptr) {
        result->handle = next;
    }
    return result;
}

uint64_t SqliteWrapper::rollback_hook(Ref<Sqlite3Handle> db, Callable callback, uint64_t user_data) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), 0);

    struct _RollbackCtx {
        Callable cb;
        uint64_t ud;
    };

    static auto trampoline = [](void *ud) {
        _RollbackCtx *ctx = reinterpret_cast<_RollbackCtx *>(ud);
        ctx->cb.callv(Array());
    };

    _RollbackCtx *ctx = (_RollbackCtx *)sqlite3_rollback_hook(db->handle, trampoline, nullptr);
    uint64_t prev_ud = ctx ? ctx->ud : 0;

    if (callback.is_valid()) {
        ctx = new _RollbackCtx{callback, user_data};
        sqlite3_rollback_hook(db->handle, trampoline, ctx);
    } else {
        sqlite3_rollback_hook(db->handle, nullptr, nullptr);
    }

    return prev_ud;
}

int SqliteWrapper::release_memory(int bytes) {
    return sqlite3_release_memory(bytes);
}

int64_t SqliteWrapper::hard_heap_limit(int64_t limit) {
    return sqlite3_hard_heap_limit64(limit);
}

void SqliteWrapper::soft_heap_limit(int limit) {
    sqlite3_soft_heap_limit(limit);
}

int SqliteWrapper::load_extension(Ref<Sqlite3Handle> db, String file, String entry_point) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);

    char *err_msg = nullptr;
    int result = sqlite3_load_extension(
        db->handle,
        file.utf8().get_data(),
        entry_point.utf8().get_data(),
        &err_msg
    );

    if (result != SQLITE_OK && err_msg != nullptr) {
        // Error message needs to be freed with sqlite3_free()
        sqlite3_free(err_msg);
    }

    return result;
}

int SqliteWrapper::cancel_auto_extension(Callable entry_point) {
    ERR_FAIL_COND_V(!entry_point.is_valid(), 0);

    // Note: This function uses a C language trick where the function pointer
    // is declared with one signature but called with another. The full functionality
    // is not easily translatable to higher-level languages. For now, we'll just return 0.
    return 0;
}

void SqliteWrapper::reset_auto_extension(void) {
    sqlite3_reset_auto_extension();
}

int SqliteWrapper::index_scan_unique(void) {
    return SQLITE_INDEX_SCAN_UNIQUE;
}

int SqliteWrapper::index_scan_hex(void) {
    return SQLITE_INDEX_SCAN_HEX;
}

int SqliteWrapper::index_constraint_eq(void) {
    return SQLITE_INDEX_CONSTRAINT_EQ;
}

int SqliteWrapper::index_constraint_gt(void) {
    return SQLITE_INDEX_CONSTRAINT_GT;
}

int SqliteWrapper::index_constraint_le(void) {
    return SQLITE_INDEX_CONSTRAINT_LE;
}

int SqliteWrapper::index_constraint_lt(void) {
    return SQLITE_INDEX_CONSTRAINT_LT;
}

int SqliteWrapper::index_constraint_ge(void) {
    return SQLITE_INDEX_CONSTRAINT_GE;
}

int SqliteWrapper::index_constraint_match(void) {
    return SQLITE_INDEX_CONSTRAINT_MATCH;
}

int SqliteWrapper::index_constraint_like(void) {
    return SQLITE_INDEX_CONSTRAINT_LIKE;
}

int SqliteWrapper::index_constraint_glob(void) {
    return SQLITE_INDEX_CONSTRAINT_GLOB;
}

int SqliteWrapper::index_constraint_regexp(void) {
    return SQLITE_INDEX_CONSTRAINT_REGEXP;
}

int SqliteWrapper::index_constraint_ne(void) {
    return SQLITE_INDEX_CONSTRAINT_NE;
}

int SqliteWrapper::index_constraint_isnot(void) {
    return SQLITE_INDEX_CONSTRAINT_ISNOT;
}

int SqliteWrapper::index_constraint_isnotnull(void) {
    return SQLITE_INDEX_CONSTRAINT_ISNOTNULL;
}

int SqliteWrapper::index_constraint_isnull(void) {
    return SQLITE_INDEX_CONSTRAINT_ISNULL;
}

int SqliteWrapper::index_constraint_is(void) {
    return SQLITE_INDEX_CONSTRAINT_IS;
}

int SqliteWrapper::index_constraint_limit(void) {
    return SQLITE_INDEX_CONSTRAINT_LIMIT;
}

int SqliteWrapper::index_constraint_offset(void) {
    return SQLITE_INDEX_CONSTRAINT_OFFSET;
}

int SqliteWrapper::index_constraint_function(void) {
    return SQLITE_INDEX_CONSTRAINT_FUNCTION;
}

int SqliteWrapper::create_module(Ref<Sqlite3Handle> db, String name, Ref<Sqlite3ModuleHandle> module, uint64_t client_data) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    ERR_FAIL_COND_V(module.is_null() || !module->is_valid(), -1);

    return sqlite3_create_module(
        db->handle,
        name.utf8().get_data(),
        module->handle,
        reinterpret_cast<void*>(client_data)
    );
}

int SqliteWrapper::blob_open(Ref<Sqlite3Handle> db, String db_name, String table_name, String column_name, int64_t row_id, int flags, Ref<Sqlite3BlobHandle> out_blob) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    ERR_FAIL_COND_V(out_blob.is_null(), -1);

    sqlite3_blob *blob = nullptr;
    int result = sqlite3_blob_open(db->handle, db_name.utf8().get_data(), table_name.utf8().get_data(), column_name.utf8().get_data(), row_id, flags, &blob);

    if (result == SQLITE_OK) {
        out_blob->handle = blob;
    } else {
        out_blob->handle = nullptr;
    }

    return result;
}

int SqliteWrapper::vfs_register(Ref<Sqlite3VfsHandle> vfs, bool make_default) {
    ERR_FAIL_COND_V(vfs.is_null() || !vfs->is_valid(), SQLITE_MISUSE);

    int result = sqlite3_vfs_register(vfs->handle, make_default ? 1 : 0);
    return result;
}

int SqliteWrapper::vfs_unregister(Ref<Sqlite3VfsHandle> vfs) {
    ERR_FAIL_COND_V(vfs.is_null() || !vfs->is_valid(), SQLITE_MISUSE);
    return sqlite3_vfs_unregister(vfs->handle);
}

void SqliteWrapper::mutex_free(Ref<Sqlite3MutexHandle> mutex) {
    ERR_FAIL_COND(mutex.is_null() || !mutex->is_valid());
    sqlite3_mutex_free(mutex->handle);
    mutex->handle = nullptr;
}

void SqliteWrapper::mutex_enter(Ref<Sqlite3MutexHandle> mutex) {
    ERR_FAIL_COND(mutex.is_null() || !mutex->is_valid());
    sqlite3_mutex_enter(mutex->handle);
}

int SqliteWrapper::mutex_try(Ref<Sqlite3MutexHandle> mutex) {
    ERR_FAIL_COND_V(mutex.is_null() || !mutex->is_valid(), SQLITE_BUSY);
    return sqlite3_mutex_try(mutex->handle);
}

void SqliteWrapper::mutex_leave(Ref<Sqlite3MutexHandle> mutex) {
    ERR_FAIL_COND(mutex.is_null() || !mutex->is_valid());
    sqlite3_mutex_leave(mutex->handle);
}

Ref<Sqlite3MutexHandle> SqliteWrapper::db_mutex(Ref<Sqlite3Handle> db) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), Ref<Sqlite3MutexHandle>());
    sqlite3_mutex *mutex = sqlite3_db_mutex(db->handle);
    if (mutex == nullptr) return Ref<Sqlite3MutexHandle>();
    Ref<Sqlite3MutexHandle> handle = Ref<Sqlite3MutexHandle>(memnew(Sqlite3MutexHandle()));
    handle->handle = mutex;
    return handle;
}

int SqliteWrapper::test_control_first(void) {
    return SQLITE_TESTCTRL_FIRST;
}

int SqliteWrapper::test_control_prng_save(void) {
    return SQLITE_TESTCTRL_PRNG_SAVE;
}

int SqliteWrapper::test_control_prng_restore(void) {
    return SQLITE_TESTCTRL_PRNG_RESTORE;
}

int SqliteWrapper::test_control_prng_reset(void) {
    return SQLITE_TESTCTRL_PRNG_RESET;
}

int SqliteWrapper::test_control_fk_no_action(void) {
    return SQLITE_TESTCTRL_FK_NO_ACTION;
}

int SqliteWrapper::test_control_bitvec_test(void) {
    return SQLITE_TESTCTRL_BITVEC_TEST;
}

int SqliteWrapper::test_control_fault_install(void) {
    return SQLITE_TESTCTRL_FAULT_INSTALL;
}

int SqliteWrapper::test_control_benign_malloc_hooks(void) {
    return SQLITE_TESTCTRL_BENIGN_MALLOC_HOOKS;
}

int SqliteWrapper::test_control_pending_byte(void) {
    return SQLITE_TESTCTRL_PENDING_BYTE;
}

int SqliteWrapper::test_control_assert(void) {
    return SQLITE_TESTCTRL_ASSERT;
}

int SqliteWrapper::test_control_always(void) {
    return SQLITE_TESTCTRL_ALWAYS;
}

int SqliteWrapper::test_control_reserve(void) {
    return SQLITE_TESTCTRL_RESERVE;
}

int SqliteWrapper::test_control_json_selfcheck(void) {
    return SQLITE_TESTCTRL_JSON_SELFCHECK;
}

int SqliteWrapper::test_control_optimizations(void) {
    return SQLITE_TESTCTRL_OPTIMIZATIONS;
}

int SqliteWrapper::test_control_iskeyword(void) {
    return SQLITE_TESTCTRL_ISKEYWORD;
}

int SqliteWrapper::test_control_getopt(void) {
    return SQLITE_TESTCTRL_GETOPT;
}

int SqliteWrapper::test_control_scratchmalloc(void) {
    return SQLITE_TESTCTRL_SCRATCHMALLOC;
}

int SqliteWrapper::test_control_internal_functions(void) {
    return SQLITE_TESTCTRL_INTERNAL_FUNCTIONS;
}

int SqliteWrapper::test_control_localtime_fault(void) {
    return SQLITE_TESTCTRL_LOCALTIME_FAULT;
}

int SqliteWrapper::test_control_explain_stmt(void) {
    return SQLITE_TESTCTRL_EXPLAIN_STMT;
}

int SqliteWrapper::test_control_once_reset_threshold(void) {
    return SQLITE_TESTCTRL_ONCE_RESET_THRESHOLD;
}

int SqliteWrapper::test_control_never_corrupt(void) {
    return SQLITE_TESTCTRL_NEVER_CORRUPT;
}

int SqliteWrapper::test_control_vdbe_coverage(void) {
    return SQLITE_TESTCTRL_VDBE_COVERAGE;
}

int SqliteWrapper::test_control_byteorder(void) {
    return SQLITE_TESTCTRL_BYTEORDER;
}

int SqliteWrapper::test_control_isinit(void) {
    return SQLITE_TESTCTRL_ISINIT;
}

int SqliteWrapper::test_control_sorter_mmap(void) {
    return SQLITE_TESTCTRL_SORTER_MMAP;
}

int SqliteWrapper::test_control_imposter(void) {
    return SQLITE_TESTCTRL_IMPOSTER;
}

int SqliteWrapper::test_control_parser_coverage(void) {
    return SQLITE_TESTCTRL_PARSER_COVERAGE;
}

int SqliteWrapper::test_control_result_intreal(void) {
    return SQLITE_TESTCTRL_RESULT_INTREAL;
}

int SqliteWrapper::test_control_prng_seed(void) {
    return SQLITE_TESTCTRL_PRNG_SEED;
}

int SqliteWrapper::test_control_extra_schema_checks(void) {
    return SQLITE_TESTCTRL_EXTRA_SCHEMA_CHECKS;
}

int SqliteWrapper::test_control_seek_count(void) {
    return SQLITE_TESTCTRL_SEEK_COUNT;
}

int SqliteWrapper::test_control_traceflags(void) {
    return SQLITE_TESTCTRL_TRACEFLAGS;
}

int SqliteWrapper::test_control_tune(void) {
    return SQLITE_TESTCTRL_TUNE;
}

int SqliteWrapper::test_control_logest(void) {
    return SQLITE_TESTCTRL_LOGEST;
}

int SqliteWrapper::test_control_uselongdouble(void) {
    return SQLITE_TESTCTRL_USELONGDOUBLE;
}

int SqliteWrapper::test_control_last(void) {
    return SQLITE_TESTCTRL_LAST;
}

int SqliteWrapper::keyword_count(void) {
    return sqlite3_keyword_count();
}

String SqliteWrapper::keyword_name(int index) {
    const char *keyword = nullptr;
    int length = 0;
    int result = sqlite3_keyword_name(index, &keyword, &length);
    if (result != SQLITE_OK || keyword == nullptr || length <= 0) {
        return String();
    }
    return String::utf8(keyword, length);
}

bool SqliteWrapper::is_keyword(String identifier) {
    CharString cs = identifier.utf8();
    return sqlite3_keyword_check(cs.get_data(), cs.length()) != 0;
}

Ref<Sqlite3StrHandle> SqliteWrapper::str_new(Ref<Sqlite3Handle> db) {
    sqlite3_str *handle = sqlite3_str_new(db.is_valid() ? db->handle : nullptr);
    Ref<Sqlite3StrHandle> result = Ref<Sqlite3StrHandle>(memnew(Sqlite3StrHandle));
    result->handle = handle;
    return result;
}

void SqliteWrapper::str_free(Ref<Sqlite3StrHandle> str) {
    if (str.is_valid()) {
        //sqlite3_str_free(str->handle);
        str->handle = nullptr;
    }
}

void SqliteWrapper::str_vappendf(Ref<Sqlite3StrHandle> str, String format, PackedStringArray args) {
    ERR_FAIL_COND(str.is_null() || !str->is_valid());
    String formatted = format;
    if (!args.is_empty()) {
        Array variant_args;
        for (int i = 0; i < args.size(); i++) {
            variant_args.push_back(args[i]);
        }
        formatted = formatted.format(variant_args);
    }
    CharString cs = formatted.utf8();
    sqlite3_str_appendf(str->handle, cs.get_data());
}

void SqliteWrapper::str_append(Ref<Sqlite3StrHandle> str, String text, int length) {
    ERR_FAIL_COND(str.is_null() || !str->is_valid());
    CharString cs = text.utf8();
    int actual_length = cs.length();
    int append_length = length < 0 ? actual_length : MIN(length, actual_length);
    if (append_length > 0) {
        sqlite3_str_append(str->handle, cs.get_data(), append_length);
    }
}

void SqliteWrapper::str_appendall(Ref<Sqlite3StrHandle> str, String text) {
    ERR_FAIL_COND(str.is_null() || !str->is_valid());
    CharString cs = text.utf8();
    sqlite3_str_appendall(str->handle, cs.get_data());
}

void SqliteWrapper::str_appendchar(Ref<Sqlite3StrHandle> str, int count, int character) {
    ERR_FAIL_COND(str.is_null() || !str->is_valid());
    sqlite3_str_appendchar(str->handle, count, static_cast<char>(character));
}

void SqliteWrapper::str_reset(Ref<Sqlite3StrHandle> str) {
    ERR_FAIL_COND(str.is_null() || !str->is_valid());
    sqlite3_str_reset(str->handle);
}

void SqliteWrapper::str_truncate(Ref<Sqlite3StrHandle> str, int length) {
    ERR_FAIL_COND(str.is_null() || !str->is_valid());
    //sqlite3_str_truncate(str->handle, length);
    (void)(length);
}

int SqliteWrapper::str_length(Ref<Sqlite3StrHandle> str) {
    ERR_FAIL_COND_V(str.is_null() || !str->is_valid(), 0);
    return sqlite3_str_length(str->handle);
}

String SqliteWrapper::str_value(Ref<Sqlite3StrHandle> str) {
    ERR_FAIL_COND_V(str.is_null() || !str->is_valid(), String());
    char *result = sqlite3_str_value(str->handle);
    return result ? String::utf8(result) : String();
}

Dictionary SqliteWrapper::status64(int op, int reset_flag) {
    long long current = 0;
    long long highwater = 0;
    int result = sqlite3_status64(op, &current, &highwater, reset_flag);
    if (result != SQLITE_OK) {
        return Dictionary();
    }
    Dictionary result_dict;
    result_dict["current"] = static_cast<int64_t>(current);
    result_dict["highwater"] = static_cast<int64_t>(highwater);
    return result_dict;
}

int SqliteWrapper::status_memory_used(void) {
    return SQLITE_STATUS_MEMORY_USED;
}

int SqliteWrapper::status_pagecache_used(void) {
    return SQLITE_STATUS_PAGECACHE_USED;
}

int SqliteWrapper::status_pagecache_overflow(void) {
    return SQLITE_STATUS_PAGECACHE_OVERFLOW;
}

int SqliteWrapper::status_malloc_size(void) {
    return SQLITE_STATUS_MALLOC_SIZE;
}

int SqliteWrapper::status_parser_stack(void) {
    return SQLITE_STATUS_PARSER_STACK;
}

int SqliteWrapper::status_pagecache_size(void) {
    return SQLITE_STATUS_PAGECACHE_SIZE;
}

int SqliteWrapper::status_malloc_count(void) {
    return SQLITE_STATUS_MALLOC_COUNT;
}

Dictionary SqliteWrapper::db_status(Ref<Sqlite3Handle> db, int op, int reset_flag) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), Dictionary());
    int current = 0;
    int highwater = 0;
    int result = sqlite3_db_status(db->handle, op, &current, &highwater, reset_flag);
    if (result != SQLITE_OK) {
        return Dictionary();
    }
    Dictionary result_dict;
    result_dict["current"] = current;
    result_dict["highwater"] = highwater;
    return result_dict;
}

Dictionary SqliteWrapper::db_status64(Ref<Sqlite3Handle> db, int op, int reset_flag) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), Dictionary());
    long long current = 0;
    long long highwater = 0;
    int result = sqlite3_db_status64(db->handle, op, &current, &highwater, reset_flag);
    if (result != SQLITE_OK) {
        return Dictionary();
    }
    Dictionary result_dict;
    result_dict["current"] = static_cast<int64_t>(current);
    result_dict["highwater"] = static_cast<int64_t>(highwater);
    return result_dict;
}

int SqliteWrapper::stmt_status(Ref<Sqlite3StmtHandle> stmt, int op, bool reset_flag) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), -1);
    return sqlite3_stmt_status(stmt->handle, op, reset_flag ? 1 : 0);
}

int SqliteWrapper::backup_step(Ref<Sqlite3BackupHandle> backup, int n_page) {
    ERR_FAIL_COND_V(backup.is_null() || !backup->is_valid(), -1);
    return sqlite3_backup_step(backup->handle, n_page);
}

int SqliteWrapper::backup_finish(Ref<Sqlite3BackupHandle> backup) {
    ERR_FAIL_COND_V(backup.is_null() || !backup->is_valid(), -1);
    return sqlite3_backup_finish(backup->handle);
}

int SqliteWrapper::backup_remaining(Ref<Sqlite3BackupHandle> backup) {
    ERR_FAIL_COND_V(backup.is_null() || !backup->is_valid(), -1);
    return sqlite3_backup_remaining(backup->handle);
}

int SqliteWrapper::str_nicmp(String a, String b, int n) {
    return sqlite3_strnicmp(a.utf8().get_data(), b.utf8().get_data(), n);
}

int SqliteWrapper::str_glob(String pattern, String str) {
    return sqlite3_strglob(pattern.utf8().get_data(), str.utf8().get_data());
}

int SqliteWrapper::str_like(String pattern, String str, int escape) {
    return sqlite3_strlike(pattern.utf8().get_data(), str.utf8().get_data(), escape);
}

void SqliteWrapper::log(int error_code, String format) {
    // SQLite's sqlite3_log() uses sqlite3_snprintf() internally with printf-style formatting.
    // Since Godot's String doesn't have vformat() in this version, we'll use a simplified approach.
    // For variadic arguments, we'd need to use va_list, but for GDScript compatibility,
    // we'll provide a version that takes a format string and uses String::utf8() directly.
    // Note: This wrapper assumes the format string is already properly formatted or uses
    // simple placeholders that match SQLite's expectations.
    sqlite3_log(error_code, format.utf8().get_data());
}

int64_t SqliteWrapper::wal_hook(Ref<Sqlite3Handle> db, Callable callback, int64_t user_data) {
    (void)(user_data);
    // Trampoline function to convert C callback to Callable
    struct _WalCtx {
        Callable cb;
    };

    auto trampoline = [](void *ud, sqlite3 *db, const char *db_name, int num_wal_pages) -> int {
        _WalCtx *ctx = reinterpret_cast<_WalCtx *>(ud);
        
        // Convert parameters to Godot types
        Ref<Sqlite3Handle> gd_db;
        gd_db.instantiate();
        gd_db->handle = db;
        
        String gd_db_name = db_name ? String::utf8(db_name) : String();
        
        // Call the GDScript callback
        Array args;
        args.push_back(gd_db);
        args.push_back(gd_db_name);
        args.push_back(num_wal_pages);
        
        Variant ret = ctx->cb.callv(args);
        if (ret.get_type() != Variant::INT) {
            UtilityFunctions::push_error("wal_hook callback must return int (SQLite error code), but got: " + ret.stringify() + " (" + Variant::get_type_name(ret.get_type()) + ")");
            return SQLITE_MISUSE;
        }
        return int(ret);
    };

    // Create context and call the original function
    _WalCtx ctx{callback};
    void *prev_user_data = sqlite3_wal_hook(db->handle, trampoline, &ctx);

    // Return the previous user data as int64_t
    return prev_user_data ? reinterpret_cast<int64_t>(prev_user_data) : 0;
}

int SqliteWrapper::vtab_config(Ref<Sqlite3Handle> db, int op, Variant args) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_MISUSE);
    (void)(args);

    // Note: Variadic function - args parameter is a placeholder. In practice,
    // only a few operations are commonly used with specific parameter types.
    // For production code, consider implementing operation-specific wrappers.
    // This simplified wrapper only supports the database handle and operation code.
    // The actual variadic arguments must be handled manually in GDScript or via
    // operation-specific bindings.
    return sqlite3_vtab_config(db->handle, op);
}

int SqliteWrapper::vtab_on_conflict(Ref<Sqlite3Handle> db) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_MISUSE);
    return sqlite3_vtab_on_conflict(db->handle);
}

int SqliteWrapper::vtab_in_next(Ref<Sqlite3ValueHandle> pVal, Ref<Sqlite3ValueHandle> out_value) {
    ERR_FAIL_COND_V(pVal.is_null() || !pVal->is_valid(), SQLITE_MISUSE);
    ERR_FAIL_COND_V(out_value.is_null(), SQLITE_MISUSE);

    sqlite3_value* out_ptr = nullptr;
    int result = sqlite3_vtab_in_next(pVal->handle, &out_ptr);
    out_value->handle = out_ptr;
    return result;
}

#if 0
int SqliteWrapper::stmt_scanstatus(Ref<Sqlite3StmtHandle> stmt, int idx, int scan_status_op, Variant out_value) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), SQLITE_MISUSE);

    // Note: This is a simplified wrapper. The actual sqlite3_stmt_scanstatus function
    // writes to a void* pointer, with the type depending on scan_status_op.
    // For production use, consider implementing operation-specific wrappers.
    // This wrapper only supports the statement handle and index; the scan_status_op
    // and out_value parameters are placeholders and not used in this simplified version.
    return sqlite3_stmt_scanstatus(stmt->handle, idx, scan_status_op, nullptr);
}
#endif

int SqliteWrapper::stmt_scanstat_complex(void) {
    return SQLITE_SCANSTAT_COMPLEX;
}

int SqliteWrapper::snapshot_get(Ref<Sqlite3Handle> db, String schema, Ref<Sqlite3SnapshotHandle> out_snapshot) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    ERR_FAIL_COND_V(out_snapshot.is_null(), -1);

    sqlite3_snapshot *snapshot = nullptr;
    int result = sqlite3_snapshot_get(db->handle, schema.utf8().get_data(), &snapshot);
    if (result == SQLITE_OK) {
        out_snapshot->handle = snapshot;
    }
    return result;
}

void SqliteWrapper::snapshot_free(Ref<Sqlite3SnapshotHandle> snapshot) {
    ERR_FAIL_COND(snapshot.is_null() || !snapshot->is_valid());
    sqlite3_snapshot_free(snapshot->handle);
}

int SqliteWrapper::deserialize(Ref<Sqlite3Handle> db, String schema, PackedByteArray data, int64_t sz_db, int64_t sz_buf, int flags) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);

    ERR_FAIL_COND_V(data.size() < sz_db, -1);

    const uint8_t *ptr = data.ptr();
    return sqlite3_deserialize(db->handle, schema.utf8().get_data(), (unsigned char *)ptr, sz_db, sz_buf, (unsigned int)flags);
}

#if 0
int SqliteWrapper::carray_bind_v2(Ref<Sqlite3StmtHandle> stmt, int index, PackedByteArray data, int n_data, int flags) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), -1);

    const uint8_t *ptr = data.ptr();
    return sqlite3_carray_bind_v2(stmt->handle, index, (void*)ptr, n_data, flags, nullptr, nullptr);
}
#endif

int SqliteWrapper::rtree_query_callback(Ref<Sqlite3Handle> db, String query_func, Callable on_query) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    ERR_FAIL_COND_V(query_func.is_empty(), -1);
    ERR_FAIL_COND_V(!on_query.is_valid(), -1);

    struct _QueryCtx {
        Callable cb;
    } ctx{on_query};

    auto trampoline = [](sqlite3_rtree_query_info* info) -> int {
        // Extract the context from info->pContext
        _QueryCtx* ctx = reinterpret_cast<_QueryCtx*>(info->pContext);

        Ref<Sqlite3RtreeQueryInfoHandle> handle;
        handle.instantiate();
        handle->set_handle(reinterpret_cast<intptr_t>(info));

        Array args;
        args.push_back(handle);

        Variant ret = ctx->cb.callv(args);
        if (ret.get_type() != Variant::INT) {
            UtilityFunctions::push_error("on_query must return int, but got: " + ret.stringify());
            return -1;
        }
        return int(ret);
    };

    return sqlite3_rtree_query_callback(db->handle, query_func.utf8().get_data(), trampoline, &ctx, nullptr);
}

int SqliteWrapper::not_within(void) {
    return NOT_WITHIN;
}

int SqliteWrapper::partly_within(void) {
    return PARTLY_WITHIN;
}

int SqliteWrapper::fully_within(void) {
    return FULLY_WITHIN;
}

int SqliteWrapper::session_create(Ref<Sqlite3Handle> db, String z_db, Ref<Sqlite3SessionHandle> out_session) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    ERR_FAIL_COND_V(z_db.is_empty(), -1);

    sqlite3_session *session = nullptr;
    int result = sqlite3session_create(db->handle, z_db.utf8().get_data(), &session);
    if (result == SQLITE_OK) {
        out_session->handle = session;
    }
    return result;
}

int SqliteWrapper::session_enable(Ref<Sqlite3SessionHandle> session, int b_enable) {
    ERR_FAIL_COND_V(session.is_null() || !session->is_valid(), -1);
    return sqlite3session_enable(session->handle, b_enable);
}

int64_t SqliteWrapper::session_memory_used(Ref<Sqlite3SessionHandle> session) {
    ERR_FAIL_COND_V(session.is_null() || !session->is_valid(), -1);
    return sqlite3session_memory_used(session->handle);
}

int SqliteWrapper::changeset_start_v2(Ref<Sqlite3ChangesetIterHandle> out_iter, PackedByteArray changeset, int flags) {
    ERR_FAIL_COND_V(out_iter.is_null(), -1);
    ERR_FAIL_COND_V(changeset.is_empty(), -1);

    const void *cptr = changeset.ptr();
    void *ptr = const_cast<void*>(cptr);

    sqlite3_changeset_iter *iter = nullptr;
    int result = sqlite3changeset_start_v2(&iter, changeset.size(), ptr, flags);
    if (result == SQLITE_OK) {
        out_iter->handle = iter;
    }
    return result;
}

int SqliteWrapper::changeset_next(Ref<Sqlite3ChangesetIterHandle> iter) {
    ERR_FAIL_COND_V(iter.is_null() || !iter->is_valid(), -1);
    return sqlite3changeset_next(iter->handle);
}

Array SqliteWrapper::changeset_concat(PackedByteArray input_a, PackedByteArray input_b) {
    const void* ptr_a = static_cast<const void*>(input_a.ptr());
    const void* ptr_b = static_cast<const void*>(input_b.ptr());

    int out_size = 0;
    void *out_ptr = nullptr;
    int result = sqlite3changeset_concat(
        input_a.size(), const_cast<void*>(ptr_a),
        input_b.size(), const_cast<void*>(ptr_b),
        &out_size, &out_ptr
    );

    Array result_array;
    result_array.resize(2);
    result_array[0] = result;

    if (result == SQLITE_OK && out_ptr != nullptr) {
        PackedByteArray output;
        output.resize(out_size);
        memcpy(output.ptrw(), out_ptr, out_size);
        sqlite3_free(out_ptr);
        result_array[1] = output;
    } else {
        result_array[1] = PackedByteArray();
    }
    return result_array;
}

int SqliteWrapper::changegroup_new(Ref<Sqlite3ChangegroupHandle> out_handle) {
    ERR_FAIL_COND_V(out_handle.is_null(), -1);

    sqlite3_changegroup *handle = nullptr;
    int result = sqlite3changegroup_new(&handle);
    if (result == SQLITE_OK) {
        out_handle->handle = handle;
    }
    return result;
}

Ref<Sqlite3RebaserHandle> SqliteWrapper::rebaser_create(void) {
    sqlite3_rebaser *handle = nullptr;
    int result = sqlite3rebaser_create(&handle);
    if (result != SQLITE_OK || handle == nullptr) {
        return Ref<Sqlite3RebaserHandle>();
    }
    Ref<Sqlite3RebaserHandle> ref;
    ref.instantiate();
    ref->set_handle(reinterpret_cast<intptr_t>(handle));
    return ref;
}

int SqliteWrapper::rebaser_configure(Ref<Sqlite3RebaserHandle> rebaser, PackedByteArray rebase_data) {
    ERR_FAIL_COND_V(rebaser.is_null() || !rebaser->is_valid(), -1);
    return sqlite3rebaser_configure(rebaser->handle, rebase_data.size(), rebase_data.ptr());
}

void SqliteWrapper::rebaser_destroy(Ref<Sqlite3RebaserHandle> rebaser) {
    if (rebaser.is_null() || !rebaser->is_valid()) {
        return;
    }
    sqlite3rebaser_delete(rebaser->handle);
    rebaser->handle = nullptr;
}

PackedByteArray SqliteWrapper::changeset_concat_stream(PackedByteArray changeset_a, PackedByteArray changeset_b) {
    // Input callback trampoline for first changeset
    auto input_a_tramp = [](void *pIn, void *pData, int *pnData) -> int {
        PackedByteArray *array = reinterpret_cast<PackedByteArray*>(pIn);
        int remaining = array->size();
        int to_copy = *pnData;
        
        if (remaining <= 0) {
            *pnData = 0;
            return SQLITE_OK;
        }
        
        if (to_copy > remaining) {
            to_copy = remaining;
        }
        
        memcpy(pData, array->ptr(), to_copy);
        *pnData = to_copy;
        
        return SQLITE_OK;
    };

    // Input callback trampoline for second changeset
    auto input_b_tramp = [](void *pIn, void *pData, int *pnData) -> int {
        PackedByteArray *array = reinterpret_cast<PackedByteArray*>(pIn);
        int remaining = array->size();
        int to_copy = *pnData;
        
        if (remaining <= 0) {
            *pnData = 0;
            return SQLITE_OK;
        }
        
        if (to_copy > remaining) {
            to_copy = remaining;
        }
        
        memcpy(pData, array->ptr(), to_copy);
        *pnData = to_copy;
        
        return SQLITE_OK;
    };

    // Output callback trampoline - collect all data
    PackedByteArray output_data;
    auto output_tramp = [](void *pOut, const void *pData, int nData) -> int {
        PackedByteArray *array = reinterpret_cast<PackedByteArray*>(pOut);
        int old_size = array->size();
        array->resize(old_size + nData);
        memcpy(array->ptrw() + old_size, pData, nData);
        return SQLITE_OK;
    };

    // Prepare output array
    PackedByteArray output_array;

    int result = sqlite3changeset_concat_strm(
        input_a_tramp,
        &changeset_a,
        input_b_tramp,
        &changeset_b,
        output_tramp,
        &output_array
    );

    if (result != SQLITE_OK) {
        return PackedByteArray();
    }

    return output_array;
}

Ref<Sqlite3ChangesetIterHandle> SqliteWrapper::changeset_start_v2_stream(PackedByteArray changeset, int flags) {
    // Input callback trampoline
    auto input_tramp = [](void *pIn, void *pData, int *pnData) -> int {
        PackedByteArray *array = reinterpret_cast<PackedByteArray*>(pIn);
        int remaining = array->size();
        int to_copy = *pnData;
        
        if (remaining <= 0) {
            *pnData = 0;
            return SQLITE_OK;
        }
        
        if (to_copy > remaining) {
            to_copy = remaining;
        }
        
        memcpy(pData, array->ptr(), to_copy);
        *pnData = to_copy;
        
        return SQLITE_OK;
    };

    sqlite3_changeset_iter *iter = nullptr;
    int result = sqlite3changeset_start_v2_strm(
        &iter,
        input_tramp,
        &changeset,
        flags
    );

    if (result != SQLITE_OK || iter == nullptr) {
        return Ref<Sqlite3ChangesetIterHandle>();
    }

    Ref<Sqlite3ChangesetIterHandle> ref;
    ref.instantiate();
    ref->set_handle(reinterpret_cast<intptr_t>(iter));
    return ref;
}

PackedByteArray SqliteWrapper::session_changeset_stream(Ref<Sqlite3SessionHandle> session) {
    // Output callback trampoline - collect all data
    auto output_tramp = [](void *pOut, const void *pData, int nData) -> int {
        PackedByteArray *array = reinterpret_cast<PackedByteArray*>(pOut);
        int old_size = array->size();
        array->resize(old_size + nData);
        memcpy(array->ptrw() + old_size, pData, nData);
        return SQLITE_OK;
    };

    ERR_FAIL_COND_V(session.is_null() || !session->is_valid(), PackedByteArray());

    PackedByteArray changeset_array;

    int result = sqlite3session_changeset_strm(
        session->handle,
        output_tramp,
        &changeset_array
    );

    if (result != SQLITE_OK) {
        return PackedByteArray();
    }

    return changeset_array;
}

PackedByteArray SqliteWrapper::session_patchset_stream(Ref<Sqlite3SessionHandle> session) {
    // Output callback trampoline - collect all data
    auto output_tramp = [](void *pOut, const void *pData, int nData) -> int {
        PackedByteArray *array = reinterpret_cast<PackedByteArray*>(pOut);
        int old_size = array->size();
        array->resize(old_size + nData);
        memcpy(array->ptrw() + old_size, pData, nData);
        return SQLITE_OK;
    };

    ERR_FAIL_COND_V(session.is_null() || !session->is_valid(), PackedByteArray());

    PackedByteArray patchset_array;

    int result = sqlite3session_patchset_strm(
        session->handle,
        output_tramp,
        &patchset_array
    );

    if (result != SQLITE_OK) {
        return PackedByteArray();
    }

    return patchset_array;
}

int SqliteWrapper::changegroup_add_stream(Ref<Sqlite3ChangegroupHandle> changegroup, PackedByteArray data) {
    // Input callback trampoline - provide data from a PackedByteArray
    struct _InputCtx {
        const uint8_t *data;
        int total_size;
        int position;
    };

    auto input_tramp = [](void *pIn, void *pData, int *pnData) -> int {
        _InputCtx *ctx = reinterpret_cast<_InputCtx*>(pIn);
        int remaining = ctx->total_size - ctx->position;
        int to_copy = *pnData;
        
        if (to_copy > remaining) {
            to_copy = remaining;
        }
        
        if (to_copy > 0) {
            memcpy(pData, ctx->data + ctx->position, to_copy);
            ctx->position += to_copy;
        }
        
        *pnData = to_copy;
        
        if (to_copy == 0 && ctx->position >= ctx->total_size) {
            // No more data
            return SQLITE_OK;
        }
        
        return SQLITE_OK;
    };

    ERR_FAIL_COND_V(changegroup.is_null() || !changegroup->is_valid(), SQLITE_MISUSE);

    if (data.is_empty()) {
        return SQLITE_OK; // Nothing to add
    }

    _InputCtx ctx;
    ctx.data = data.ptr();
    ctx.total_size = data.size();
    ctx.position = 0;

    int result = sqlite3changegroup_add_strm(
        changegroup->handle,
        input_tramp,
        &ctx
    );

    return result;
}

int SqliteWrapper::session_config_strmsize(void) {
    return SQLITE_SESSION_CONFIG_STRMSIZE;
}

int SqliteWrapper::close_v2(Ref<Sqlite3Handle> db) {
    return sqlite3_close_v2(db.is_null() ? nullptr : db->handle);
}

int SqliteWrapper::exec(Ref<Sqlite3Handle> db, String sql, Callable callback) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_MISUSE);

    if (!callback.is_valid()) {
        return sqlite3_exec(db->handle, sql.utf8().get_data(), nullptr, nullptr, nullptr);
    }

    struct _ExecCtx {
        Callable cb;
    } ctx{callback};

    auto trampoline = [](void* ud, int ncols, char** colv, char** colnames) -> int {
        _ExecCtx* ctx = (_ExecCtx*)ud;
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
            UtilityFunctions::push_error("Callback must return int, got: " + ret.stringify() + " (" + Variant::get_type_name(ret.get_type()) + ")");
            return 1;
        }
        return int(ret);
    };

    return sqlite3_exec(db->handle, sql.utf8().get_data(), trampoline, &ctx, nullptr);
}

int64_t SqliteWrapper::last_insert_rowid(Ref<Sqlite3Handle> db) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), 0);
    return sqlite3_last_insert_rowid(db->handle);
}

void SqliteWrapper::set_last_insert_rowid(Ref<Sqlite3Handle> db, int64_t rowid) {
    ERR_FAIL_COND(db.is_null() || !db->is_valid());
    sqlite3_set_last_insert_rowid(db->handle, rowid);
}

int SqliteWrapper::changes(Ref<Sqlite3Handle> db) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), 0);
    return sqlite3_changes(db->handle);
}

int SqliteWrapper::total_changes(Ref<Sqlite3Handle> db) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), 0);
    return sqlite3_total_changes(db->handle);
}

int SqliteWrapper::complete(String sql) {
    return sqlite3_complete(sql.utf8().get_data());
}

int SqliteWrapper::busy_timeout(Ref<Sqlite3Handle> db, int ms) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_ERROR);
    return sqlite3_busy_timeout(db->handle, ms);
}

int SqliteWrapper::setlk_timeout(Ref<Sqlite3Handle> db, int ms, int flags) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_ERROR);
    return sqlite3_setlk_timeout(db->handle, ms, flags);
}

int SqliteWrapper::setlk_block_on_connect_flag(void) {
    return SQLITE_SETLK_BLOCK_ON_CONNECT;
}

int SqliteWrapper::get_table(Ref<Sqlite3Handle> db, String sql, Array out_result, int out_rows, int out_columns, String out_error) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_ERROR);
    char **result = nullptr;
    int rows = 0;
    int columns = 0;
    char *errmsg = nullptr;
    int rc = sqlite3_get_table(db->handle, sql.utf8().get_data(), &result, &rows, &columns, &errmsg);
    if (rc != SQLITE_OK) {
        if (errmsg) {
            out_error = String::utf8(errmsg);
            sqlite3_free(errmsg);
        }
        return rc;
    }
    Array result_array;
    int total_entries = (rows + 1) * columns;
    for (int i = 0; i < total_entries; i++) {
        if (result[i]) {
            result_array.push_back(String::utf8(result[i]));
        } else {
            result_array.push_back(Variant());
        }
    }
    Array reshaped;
    for (int r = 0; r < rows + 1; r++) {
        Array row;
        for (int c = 0; c < columns; c++) {
            row.push_back(result_array[r * columns + c]);
        }
        reshaped.push_back(row);
    }
    sqlite3_free_table(result);
    out_result = reshaped;
    out_rows = rows;
    out_columns = columns;
    out_error = String();
    return SQLITE_OK;
}

int SqliteWrapper::deny_code(void) {
    return SQLITE_DENY;
}

int SqliteWrapper::ignore_code(void) {
    return SQLITE_IGNORE;
}

int SqliteWrapper::create_index_action(void) {
    return SQLITE_CREATE_INDEX;
}

int SqliteWrapper::create_table_action(void) {
    return SQLITE_CREATE_TABLE;
}

int SqliteWrapper::create_temp_index_action(void) {
    return SQLITE_CREATE_TEMP_INDEX;
}

int SqliteWrapper::create_temp_table_action(void) {
    return SQLITE_CREATE_TEMP_TABLE;
}

int SqliteWrapper::create_temp_trigger_action(void) {
    return SQLITE_CREATE_TEMP_TRIGGER;
}

int SqliteWrapper::create_temp_view_action(void) {
    return SQLITE_CREATE_TEMP_VIEW;
}

int SqliteWrapper::create_trigger_action(void) {
    return SQLITE_CREATE_TRIGGER;
}

int SqliteWrapper::create_view_action(void) {
    return SQLITE_CREATE_VIEW;
}

int SqliteWrapper::delete_action(void) {
    return SQLITE_DELETE;
}

int SqliteWrapper::drop_index_action(void) {
    return SQLITE_DROP_INDEX;
}

int SqliteWrapper::drop_table_action(void) {
    return SQLITE_DROP_TABLE;
}

int SqliteWrapper::drop_temp_index_action(void) {
    return SQLITE_DROP_TEMP_INDEX;
}

int SqliteWrapper::drop_temp_table_action(void) {
    return SQLITE_DROP_TEMP_TABLE;
}

int SqliteWrapper::drop_temp_trigger_action(void) {
    return SQLITE_DROP_TEMP_TRIGGER;
}

int SqliteWrapper::drop_temp_view_action(void) {
    return SQLITE_DROP_TEMP_VIEW;
}

int SqliteWrapper::drop_trigger_action(void) {
    return SQLITE_DROP_TRIGGER;
}

int SqliteWrapper::drop_view_action(void) {
    return SQLITE_DROP_VIEW;
}

int SqliteWrapper::insert_action(void) {
    return SQLITE_INSERT;
}

int SqliteWrapper::pragma_action(void) {
    return SQLITE_PRAGMA;
}

int SqliteWrapper::read_action(void) {
    return SQLITE_READ;
}

int SqliteWrapper::select_action(void) {
    return SQLITE_SELECT;
}

int SqliteWrapper::transaction_action(void) {
    return SQLITE_TRANSACTION;
}

int SqliteWrapper::update_action(void) {
    return SQLITE_UPDATE;
}

int SqliteWrapper::attach_action(void) {
    return SQLITE_ATTACH;
}

int SqliteWrapper::detach_action(void) {
    return SQLITE_DETACH;
}

int SqliteWrapper::alter_table_action(void) {
    return SQLITE_ALTER_TABLE;
}

int SqliteWrapper::reindex_action(void) {
    return SQLITE_REINDEX;
}

int SqliteWrapper::analyze_action(void) {
    return SQLITE_ANALYZE;
}

int SqliteWrapper::create_vtable_action(void) {
    return SQLITE_CREATE_VTABLE;
}

int SqliteWrapper::drop_vtable_action(void) {
    return SQLITE_DROP_VTABLE;
}

int SqliteWrapper::function_action(void) {
    return SQLITE_FUNCTION;
}

int SqliteWrapper::savepoint_action(void) {
    return SQLITE_SAVEPOINT;
}

int SqliteWrapper::copy_action(void) {
    return SQLITE_COPY;
}

int SqliteWrapper::recursive_action(void) {
    return SQLITE_RECURSIVE;
}

int64_t SqliteWrapper::profile(Ref<Sqlite3Handle> db, Callable callback) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), 0);
    ERR_FAIL_COND_V(!callback.is_valid(), 0);
    struct _ProfileCtx { Callable cb; } ctx{callback};
    auto trampoline = [](void* ud, const char* sql, sqlite3_uint64 elapsed) {
        _ProfileCtx* ctx = static_cast<_ProfileCtx*>(ud);
        String s = sql ? String::utf8(sql) : String();
        ctx->cb.call(s, (uint64_t)elapsed);
    };
    void* result = sqlite3_profile(db->handle, trampoline, &ctx);
    return reinterpret_cast<int64_t>(result);
}

int SqliteWrapper::trace_stmt_mask(void) {
    return SQLITE_TRACE_STMT;
}

int SqliteWrapper::trace_profile_mask(void) {
    return SQLITE_TRACE_PROFILE;
}

int SqliteWrapper::trace_row_mask(void) {
    return SQLITE_TRACE_ROW;
}

int SqliteWrapper::trace_close_mask(void) {
    return SQLITE_TRACE_CLOSE;
}

void SqliteWrapper::progress_handler(Ref<Sqlite3Handle> db, int n, Callable callback) {
    ERR_FAIL_COND(db.is_null() || !db->is_valid());
    ERR_FAIL_COND(!callback.is_valid());
    struct _ProgressCtx { Callable cb; } ctx{callback};
    auto trampoline = [](void* ud) -> int {
        _ProgressCtx* ctx = static_cast<_ProgressCtx*>(ud);
        Variant ret = ctx->cb.call();
        if (ret.get_type() == Variant::INT) {
            return int(ret);
        }
        return 0;
    };
    sqlite3_progress_handler(db->handle, n, trampoline, &ctx);
}

int SqliteWrapper::open(String filename, Ref<Sqlite3Handle> out_db) {
    ERR_FAIL_COND_V(out_db.is_null(), SQLITE_ERROR);
    CharString filename_utf8 = filename.utf8();
    const char* filename_c = filename_utf8.get_data();
    return sqlite3_open(filename_c, &out_db->handle);
}

int SqliteWrapper::open16(String filename, Ref<Sqlite3Handle> out_db) {
    ERR_FAIL_COND_V(out_db.is_null(), SQLITE_ERROR);
    const char16_t* filename_utf16 = filename.utf16().ptr();
    return sqlite3_open16(filename_utf16, &out_db->handle);
}

int SqliteWrapper::open_v2(String filename, Ref<Sqlite3Handle> out_db, int flags, String vfs) {
    ERR_FAIL_COND_V(out_db.is_null(), SQLITE_ERROR);
    CharString filename_utf8 = filename.utf8();
    const char* filename_c = filename_utf8.get_data();
    CharString vfs_utf8 = vfs.utf8();
    const char* vfs_c = vfs.is_empty() ? nullptr : vfs_utf8.get_data();
    return sqlite3_open_v2(filename_c, &out_db->handle, flags, vfs_c);
}

String SqliteWrapper::errmsg16(Ref<Sqlite3Handle> db) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), String());
    const void* result = sqlite3_errmsg16(db->handle);
    if (!result) return String();
    const char16_t* utf16_ptr = static_cast<const char16_t*>(result);
    return String::utf16(utf16_ptr);
}

int SqliteWrapper::error_offset(Ref<Sqlite3Handle> db) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    return sqlite3_error_offset(db->handle);
}

int SqliteWrapper::set_errmsg(Ref<Sqlite3Handle> db, int errcode, String errmsg) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_MISUSE);
    CharString errmsg_utf8 = errmsg.utf8();
    const char* errmsg_c = errmsg_utf8.get_data();
    return sqlite3_set_errmsg(db->handle, errcode, errmsg_c);
}

int SqliteWrapper::limit_length(void) {
    return SQLITE_LIMIT_LENGTH;
}

int SqliteWrapper::limit_sql_length(void) {
    return SQLITE_LIMIT_SQL_LENGTH;
}

int SqliteWrapper::limit_column(void) {
    return SQLITE_LIMIT_COLUMN;
}

int SqliteWrapper::limit_expr_depth(void) {
    return SQLITE_LIMIT_EXPR_DEPTH;
}

int SqliteWrapper::limit_compound_select(void) {
    return SQLITE_LIMIT_COMPOUND_SELECT;
}

int SqliteWrapper::limit_vdbe_op(void) {
    return SQLITE_LIMIT_VDBE_OP;
}

int SqliteWrapper::limit_function_arg(void) {
    return SQLITE_LIMIT_FUNCTION_ARG;
}

int SqliteWrapper::limit_attached(void) {
    return SQLITE_LIMIT_ATTACHED;
}

int SqliteWrapper::limit_like_pattern_length(void) {
    return SQLITE_LIMIT_LIKE_PATTERN_LENGTH;
}

int SqliteWrapper::limit_variable_number(void) {
    return SQLITE_LIMIT_VARIABLE_NUMBER;
}

int SqliteWrapper::limit_trigger_depth(void) {
    return SQLITE_LIMIT_TRIGGER_DEPTH;
}

int SqliteWrapper::limit_worker_threads(void) {
    return SQLITE_LIMIT_WORKER_THREADS;
}

int SqliteWrapper::limit_parser_depth(void) {
#ifdef SQLITE_LIMIT_PARSER_DEPTH
    return SQLITE_LIMIT_PARSER_DEPTH;
#else
    return -1;
#endif
}

int SqliteWrapper::prepare_persistent_flag(void) {
    return SQLITE_PREPARE_PERSISTENT;
}

int SqliteWrapper::prepare_normalize_flag(void) {
    return SQLITE_PREPARE_NORMALIZE;
}

int SqliteWrapper::prepare_no_vtab_flag(void) {
    return SQLITE_PREPARE_NO_VTAB;
}

int SqliteWrapper::prepare_dont_log_flag(void) {
    return SQLITE_PREPARE_DONT_LOG;
}

int SqliteWrapper::prepare_from_ddl_flag(void) {
#ifdef SQLITE_PREPARE_FROM_DDL
    return SQLITE_PREPARE_FROM_DDL;
#else
    return -1;
#endif
}

int SqliteWrapper::prepare(Ref<Sqlite3Handle> db, String sql, int max_bytes, Ref<Sqlite3StmtHandle> out_stmt, String out_tail) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_ERROR);
    ERR_FAIL_COND_V(out_stmt.is_null(), SQLITE_ERROR);
    CharString sql_utf8 = sql.utf8();
    const char* sql_c = sql_utf8.get_data();
    int len = max_bytes < 0 ? -1 : max_bytes;
    const char* tail_c = nullptr;
    sqlite3_stmt* stmt = nullptr;
    int rc = sqlite3_prepare(db->handle, sql_c, len, &stmt, &tail_c);
    if (rc == SQLITE_OK) {
        out_stmt->handle = stmt;
        out_tail = tail_c ? String::utf8(tail_c) : String();
    } else {
        out_stmt->handle = nullptr;
        out_tail = String();
    }
    return rc;
}

int SqliteWrapper::prepare_v2(Ref<Sqlite3Handle> db, String sql, int max_bytes, Ref<Sqlite3StmtHandle> out_stmt, String out_tail) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_ERROR);
    ERR_FAIL_COND_V(out_stmt.is_null(), SQLITE_ERROR);
    CharString sql_utf8 = sql.utf8();
    const char* sql_c = sql_utf8.get_data();
    int len = max_bytes < 0 ? -1 : max_bytes;
    const char* tail_c = nullptr;
    sqlite3_stmt* stmt = nullptr;
    int rc = sqlite3_prepare_v2(db->handle, sql_c, len, &stmt, &tail_c);
    if (rc == SQLITE_OK) {
        out_stmt->handle = stmt;
        out_tail = tail_c ? String::utf8(tail_c) : String();
    } else {
        out_stmt->handle = nullptr;
        out_tail = String();
    }
    return rc;
}

int SqliteWrapper::prepare_v3(Ref<Sqlite3Handle> db, String sql, int max_bytes, unsigned int prep_flags, Ref<Sqlite3StmtHandle> out_stmt, String out_tail) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_ERROR);
    ERR_FAIL_COND_V(out_stmt.is_null(), SQLITE_ERROR);
    CharString sql_utf8 = sql.utf8();
    const char* sql_c = sql_utf8.get_data();
    int len = max_bytes < 0 ? -1 : max_bytes;
    const char* tail_c = nullptr;
    sqlite3_stmt* stmt = nullptr;
    int rc = sqlite3_prepare_v3(db->handle, sql_c, len, prep_flags, &stmt, &tail_c);
    if (rc == SQLITE_OK) {
        out_stmt->handle = stmt;
        out_tail = tail_c ? String::utf8(tail_c) : String();
    } else {
        out_stmt->handle = nullptr;
        out_tail = String();
    }
    return rc;
}

int SqliteWrapper::prepare16(Ref<Sqlite3Handle> db, String sql, int max_bytes, Ref<Sqlite3StmtHandle> out_stmt, String out_tail) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_ERROR);
    ERR_FAIL_COND_V(out_stmt.is_null(), SQLITE_ERROR);
    Char16String sql_utf16 = sql.utf16();
    const void* sql_ptr = sql_utf16.ptr();
    int len = max_bytes < 0 ? -1 : max_bytes;
    const void* tail_c = nullptr;
    sqlite3_stmt* stmt = nullptr;
    int rc = sqlite3_prepare16(db->handle, sql_ptr, len, &stmt, &tail_c);
    if (rc == SQLITE_OK) {
        out_stmt->handle = stmt;
        if (tail_c) {
            int tail_len_chars = 0;
            const char16_t* p = (const char16_t*)tail_c;
            while (*p != 0 && tail_len_chars < 1024) {
                p++;
                tail_len_chars++;
            }
            out_tail = String::utf16((const char16_t*)tail_c, tail_len_chars);
        } else {
            out_tail = String();
        }
    } else {
        out_stmt->handle = nullptr;
        out_tail = String();
    }
    return rc;
}

int SqliteWrapper::prepare16_v2(Ref<Sqlite3Handle> db, String sql, int max_bytes, Ref<Sqlite3StmtHandle> out_stmt, String out_tail) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_ERROR);
    ERR_FAIL_COND_V(out_stmt.is_null(), SQLITE_ERROR);
    Char16String sql_utf16 = sql.utf16();
    const void* sql_ptr = sql_utf16.ptr();
    int len = max_bytes < 0 ? -1 : max_bytes;
    const void* tail_c = nullptr;
    sqlite3_stmt* stmt = nullptr;
    int rc = sqlite3_prepare16_v2(db->handle, sql_ptr, len, &stmt, &tail_c);
    if (rc == SQLITE_OK) {
        out_stmt->handle = stmt;
        if (tail_c) {
            int tail_len_chars = 0;
            const char16_t* p = (const char16_t*)tail_c;
            while (*p != 0 && tail_len_chars < 1024) {
                p++;
                tail_len_chars++;
            }
            out_tail = String::utf16((const char16_t*)tail_c, tail_len_chars);
        } else {
            out_tail = String();
        }
    } else {
        out_stmt->handle = nullptr;
        out_tail = String();
    }
    return rc;
}

int SqliteWrapper::prepare16_v3(Ref<Sqlite3Handle> db, String sql, int max_bytes, unsigned int prep_flags, Ref<Sqlite3StmtHandle> out_stmt, String out_tail) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_ERROR);
    ERR_FAIL_COND_V(out_stmt.is_null(), SQLITE_ERROR);
    Char16String sql_utf16 = sql.utf16();
    const void* sql_ptr = sql_utf16.ptr();
    int len = max_bytes < 0 ? -1 : max_bytes;
    const void* tail_c = nullptr;
    sqlite3_stmt* stmt = nullptr;
    int rc = sqlite3_prepare16_v3(db->handle, sql_ptr, len, prep_flags, &stmt, &tail_c);
    if (rc == SQLITE_OK) {
        out_stmt->handle = stmt;
        if (tail_c) {
            int tail_len_chars = 0;
            const char16_t* p = (const char16_t*)tail_c;
            while (*p != 0 && tail_len_chars < 1024) {
                p++;
                tail_len_chars++;
            }
            out_tail = String::utf16((const char16_t*)tail_c, tail_len_chars);
        } else {
            out_tail = String();
        }
    } else {
        out_stmt->handle = nullptr;
        out_tail = String();
    }
    return rc;
}

String SqliteWrapper::get_sql(Ref<Sqlite3StmtHandle> stmt) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), String());
    const char* sql_c = sqlite3_sql(stmt->handle);
    return sql_c ? String::utf8(sql_c) : String();
}

String SqliteWrapper::get_normalized_sql(Ref<Sqlite3StmtHandle> stmt) {
    #ifdef SQLITE_ENABLE_NORMALIZE
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), String());
    const char* sql_c = sqlite3_normalized_sql(stmt->handle);
    return sql_c ? String::utf8(sql_c) : String();
    #else
    (void)(stmt);
    return String();
    #endif
}

bool SqliteWrapper::is_read_only(Ref<Sqlite3StmtHandle> stmt) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), false);
    return sqlite3_stmt_readonly(stmt->handle) != 0;
}

int SqliteWrapper::is_explain(Ref<Sqlite3StmtHandle> stmt) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), 0);
    return sqlite3_stmt_isexplain(stmt->handle);
}

int SqliteWrapper::set_explain_mode(Ref<Sqlite3StmtHandle> stmt, int mode) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), SQLITE_ERROR);
    return sqlite3_stmt_explain(stmt->handle, mode);
}

bool SqliteWrapper::is_busy(Ref<Sqlite3StmtHandle> stmt) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), false);
    return sqlite3_stmt_busy(stmt->handle) != 0;
}

int SqliteWrapper::bind_double(Ref<Sqlite3StmtHandle> stmt, int index, double value) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), SQLITE_ERROR);
    ERR_FAIL_COND_V(index < 1, SQLITE_RANGE);
    return sqlite3_bind_double(stmt->handle, index, value);
}

int SqliteWrapper::bind_int(Ref<Sqlite3StmtHandle> stmt, int index, int value) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), SQLITE_ERROR);
    ERR_FAIL_COND_V(index < 1, SQLITE_RANGE);
    return sqlite3_bind_int(stmt->handle, index, value);
}

int SqliteWrapper::bind_null(Ref<Sqlite3StmtHandle> stmt, int index) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), SQLITE_ERROR);
    ERR_FAIL_COND_V(index < 1, SQLITE_RANGE);
    return sqlite3_bind_null(stmt->handle, index);
}

int SqliteWrapper::bind_text(Ref<Sqlite3StmtHandle> stmt, int index, String text) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), SQLITE_ERROR);
    ERR_FAIL_COND_V(index < 1, SQLITE_RANGE);
    if (text.is_empty()) {
        return sqlite3_bind_null(stmt->handle, index);
    }
    String utf8_text = text;
    const CharString utf8_chars = utf8_text.utf8();
    return sqlite3_bind_text(stmt->handle, index, utf8_chars.get_data(), -1, SQLITE_TRANSIENT);
}

int SqliteWrapper::bind_text16(Ref<Sqlite3StmtHandle> stmt, int index, String text) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), SQLITE_ERROR);
    ERR_FAIL_COND_V(index < 1, SQLITE_RANGE);
    if (text.is_empty()) {
        return sqlite3_bind_null(stmt->handle, index);
    }
    String text_copy = text;
    const Char16String utf16_chars = text_copy.utf16();
    int len = utf16_chars.length() * sizeof(char16_t);
    return sqlite3_bind_text16(stmt->handle, index, utf16_chars.get_data(), len, SQLITE_TRANSIENT);
}

int SqliteWrapper::bind_text64(Ref<Sqlite3StmtHandle> stmt, int index, String text) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), SQLITE_ERROR);
    ERR_FAIL_COND_V(index < 1, SQLITE_RANGE);
    if (text.is_empty()) {
        return sqlite3_bind_null(stmt->handle, index);
    }
    String text_copy = text;
    const CharString utf8_chars = text_copy.utf8();
    sqlite3_uint64 len = utf8_chars.length();
    return sqlite3_bind_text64(stmt->handle, index, utf8_chars.get_data(), len, SQLITE_TRANSIENT, SQLITE_UTF8);
}

int SqliteWrapper::bind_value(Ref<Sqlite3StmtHandle> stmt, int index, Ref<Sqlite3ValueHandle> value) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), SQLITE_ERROR);
    ERR_FAIL_COND_V(index < 1, SQLITE_RANGE);
    ERR_FAIL_COND_V(value.is_null() || !value->is_valid(), SQLITE_ERROR);
    return sqlite3_bind_value(stmt->handle, index, value->handle);
}

int SqliteWrapper::bind_pointer(Ref<Sqlite3StmtHandle> stmt, int index, int64_t pointer, String type) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), SQLITE_ERROR);
    ERR_FAIL_COND_V(index < 1, SQLITE_RANGE);
    void* ptr = reinterpret_cast<void*>(pointer);
    return sqlite3_bind_pointer(stmt->handle, index, ptr, type.utf8().get_data(), SQLITE_TRANSIENT);
}

int SqliteWrapper::bind_zeroblob64(Ref<Sqlite3StmtHandle> stmt, int index, uint64_t length) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), SQLITE_ERROR);
    ERR_FAIL_COND_V(index < 1, SQLITE_RANGE);
    return sqlite3_bind_zeroblob64(stmt->handle, index, length);
}

int SqliteWrapper::bind_parameter_count(Ref<Sqlite3StmtHandle> stmt) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), -1);
    return sqlite3_bind_parameter_count(stmt->handle);
}

String SqliteWrapper::bind_parameter_name(Ref<Sqlite3StmtHandle> stmt, int index) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), String());
    ERR_FAIL_COND_V(index < 1, String());
    const char* name = sqlite3_bind_parameter_name(stmt->handle, index);
    return name ? String::utf8(name) : String();
}

int SqliteWrapper::bind_parameter_index(Ref<Sqlite3StmtHandle> stmt, String name) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), 0);
    return sqlite3_bind_parameter_index(stmt->handle, name.utf8().get_data());
}

int SqliteWrapper::clear_bindings(Ref<Sqlite3StmtHandle> stmt) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), SQLITE_ERROR);
    return sqlite3_clear_bindings(stmt->handle);
}

int SqliteWrapper::column_count(Ref<Sqlite3StmtHandle> stmt) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), -1);
    return sqlite3_column_count(stmt->handle);
}

String SqliteWrapper::column_name(Ref<Sqlite3StmtHandle> stmt, int index) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), String());
    ERR_FAIL_COND_V(index < 0, String());
    const char* name = sqlite3_column_name(stmt->handle, index);
    return name ? String::utf8(name) : String();
}

String SqliteWrapper::column_database_name(Ref<Sqlite3StmtHandle> stmt, int index) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), String());
    ERR_FAIL_COND_V(index < 0, String());
    const char* name = sqlite3_column_database_name(stmt->handle, index);
    return name ? String::utf8(name) : String();
}

String SqliteWrapper::column_table_name16(Ref<Sqlite3StmtHandle> stmt, int index) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), String());
    ERR_FAIL_COND_V(index < 0, String());
    const void* name16 = sqlite3_column_table_name16(stmt->handle, index);
    if (!name16) {
        return String();
    }
    const char16_t* name16_ptr = static_cast<const char16_t*>(name16);
    return String(name16_ptr);
}

String SqliteWrapper::column_origin_name(Ref<Sqlite3StmtHandle> stmt, int index) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), String());
    ERR_FAIL_COND_V(index < 0, String());
    const char* name = sqlite3_column_origin_name(stmt->handle, index);
    return name ? String::utf8(name) : String();
}

String SqliteWrapper::column_origin_name16(Ref<Sqlite3StmtHandle> stmt, int index) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), String());
    ERR_FAIL_COND_V(index < 0, String());
    const void* name16 = sqlite3_column_origin_name16(stmt->handle, index);
    if (!name16) {
        return String();
    }
    const char16_t* name16_ptr = static_cast<const char16_t*>(name16);
    return String(name16_ptr);
}

String SqliteWrapper::column_decltype(Ref<Sqlite3StmtHandle> stmt, int index) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), String());
    ERR_FAIL_COND_V(index < 0, String());
    const char* type = sqlite3_column_decltype(stmt->handle, index);
    return type ? String::utf8(type) : String();
}

int SqliteWrapper::step(Ref<Sqlite3StmtHandle> stmt) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), SQLITE_ERROR);
    return sqlite3_step(stmt->handle);
}

int SqliteWrapper::data_count(Ref<Sqlite3StmtHandle> stmt) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), 0);
    return sqlite3_data_count(stmt->handle);
}

int SqliteWrapper::constant_integer(void) {
    return SQLITE_INTEGER;
}

int SqliteWrapper::constant_float(void) {
    return SQLITE_FLOAT;
}

int SqliteWrapper::constant_blob(void) {
    return SQLITE_BLOB;
}

int SqliteWrapper::constant_null(void) {
    return SQLITE_NULL;
}

String SqliteWrapper::column_text(Ref<Sqlite3StmtHandle> stmt, int index) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), String());
    ERR_FAIL_COND_V(index < 0, String());
    const unsigned char* text_ptr = sqlite3_column_text(stmt->handle, index);
    if (!text_ptr) {
        return String();
    }
    return String::utf8((const char*)text_ptr);
}

String SqliteWrapper::column_text16(Ref<Sqlite3StmtHandle> stmt, int index) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), String());
    ERR_FAIL_COND_V(index < 0, String());
    const void* text16_ptr = sqlite3_column_text16(stmt->handle, index);
    if (!text16_ptr) {
        return String();
    }
    Char16String utf16_str = Char16String((const char16_t*)text16_ptr);
    return String(utf16_str);
}

Ref<Sqlite3ValueHandle> SqliteWrapper::column_value(Ref<Sqlite3StmtHandle> stmt, int index) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), Ref<Sqlite3ValueHandle>());
    ERR_FAIL_COND_V(index < 0, Ref<Sqlite3ValueHandle>());
    sqlite3_value* value_ptr = sqlite3_column_value(stmt->handle, index);
    Ref<Sqlite3ValueHandle> value_handle = Ref<Sqlite3ValueHandle>(memnew(Sqlite3ValueHandle()));
    value_handle->handle = value_ptr;
    return value_handle;
}

int SqliteWrapper::column_bytes(Ref<Sqlite3StmtHandle> stmt, int index) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), 0);
    ERR_FAIL_COND_V(index < 0, 0);
    return sqlite3_column_bytes(stmt->handle, index);
}

int SqliteWrapper::column_bytes16(Ref<Sqlite3StmtHandle> stmt, int index) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), 0);
    ERR_FAIL_COND_V(index < 0, 0);
    return sqlite3_column_bytes16(stmt->handle, index);
}

int SqliteWrapper::column_type(Ref<Sqlite3StmtHandle> stmt, int index) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), SQLITE_NULL);
    ERR_FAIL_COND_V(index < 0, SQLITE_NULL);
    return sqlite3_column_type(stmt->handle, index);
}

int SqliteWrapper::finalize(Ref<Sqlite3StmtHandle> stmt) {
    if (stmt.is_null() || !stmt->is_valid()) {
        return SQLITE_OK;
    }
    int result = sqlite3_finalize(stmt->handle);
    stmt->handle = nullptr;
    return result;
}

int SqliteWrapper::reset(Ref<Sqlite3StmtHandle> stmt) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), SQLITE_ERROR);
    return sqlite3_reset(stmt->handle);
}

int SqliteWrapper::create_function(Ref<Sqlite3Handle> db, String function_name, int n_arg, int text_rep, Callable func) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_ERROR);
    ERR_FAIL_COND_V(!func.is_valid(), SQLITE_ERROR);

    struct _FuncCtx {
        Callable cb;
    } ctx{func};

    auto trampoline = [](sqlite3_context* ctx_ptr, int argc, sqlite3_value** argv) {
        // Placeholder for callback implementation
        // Full implementation would require proper handling of sqlite3_context and sqlite3_value
        (void)(ctx_ptr);
        (void)(argc);
        (void)(argv);
    };

    return sqlite3_create_function(db->handle, function_name.utf8().get_data(), n_arg, text_rep, &ctx, trampoline, nullptr, nullptr);
}

int SqliteWrapper::create_function16(Ref<Sqlite3Handle> db, String function_name, int n_arg, int text_rep, Callable func) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_ERROR);
    ERR_FAIL_COND_V(!func.is_valid(), SQLITE_ERROR);

    struct _FuncCtx {
        Callable cb;
    } ctx{func};

    auto trampoline = [](sqlite3_context* ctx_ptr, int argc, sqlite3_value** argv) {
        // Placeholder for callback implementation
        (void)(ctx_ptr);
        (void)(argc);
        (void)(argv);
    };

    Char16String utf16_name = function_name.utf16();
    return sqlite3_create_function16(db->handle, utf16_name.ptr(), n_arg, text_rep, &ctx, trampoline, nullptr, nullptr);
}

int SqliteWrapper::create_function_v2(Ref<Sqlite3Handle> db, String function_name, int n_arg, int text_rep, Callable func) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_ERROR);
    ERR_FAIL_COND_V(!func.is_valid(), SQLITE_ERROR);

    struct _FuncCtx {
        Callable cb;
    } ctx{func};

    auto trampoline = [](sqlite3_context* ctx_ptr, int argc, sqlite3_value** argv) {
        // Placeholder for callback implementation
        (void)(ctx_ptr);
        (void)(argc);
        (void)(argv);
    };

    auto destructor = [](void* ptr) {
        // Placeholder for destructor implementation
        (void)(ptr);
    };

    return sqlite3_create_function_v2(db->handle, function_name.utf8().get_data(), n_arg, text_rep, &ctx, trampoline, nullptr, nullptr, destructor);
}

int SqliteWrapper::create_window_function(Ref<Sqlite3Handle> db, String function_name, int n_arg, int text_rep, Callable func) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_ERROR);
    ERR_FAIL_COND_V(!func.is_valid(), SQLITE_ERROR);

    struct _FuncCtx {
        Callable cb;
    } ctx{func};

    auto trampoline = [](sqlite3_context* ctx_ptr, int argc, sqlite3_value** argv) {
        // Placeholder for callback implementation
        (void)(ctx_ptr);
        (void)(argc);
        (void)(argv);
    };

    auto destructor = [](void* ptr) {
        // Placeholder for destructor implementation
        (void)(ptr);
    };

    return sqlite3_create_window_function(db->handle, function_name.utf8().get_data(), n_arg, text_rep, &ctx, trampoline, nullptr, nullptr, nullptr, destructor);
}

int SqliteWrapper::constant_utf8(void) {
    return SQLITE_UTF8;
}

int SqliteWrapper::constant_utf16le(void) {
    return SQLITE_UTF16LE;
}

int SqliteWrapper::constant_utf16be(void) {
    return SQLITE_UTF16BE;
}

int SqliteWrapper::constant_utf16(void) {
    return SQLITE_UTF16;
}

int SqliteWrapper::constant_any(void) {
    return SQLITE_ANY;
}

int SqliteWrapper::constant_utf16_aligned(void) {
    return SQLITE_UTF16_ALIGNED;
}

int SqliteWrapper::constant_utf8_zt(void) {
#ifdef SQLITE_UTF8_ZT
    return SQLITE_UTF8_ZT;
#else
    return -1;
#endif
}

int SqliteWrapper::constant_deterministic(void) {
    return SQLITE_DETERMINISTIC;
}

int SqliteWrapper::constant_directonly(void) {
    return SQLITE_DIRECTONLY;
}

int SqliteWrapper::constant_subtype(void) {
    return SQLITE_SUBTYPE;
}

int SqliteWrapper::constant_innocuous(void) {
    return SQLITE_INNOCUOUS;
}

int SqliteWrapper::constant_result_subtype(void) {
    return SQLITE_RESULT_SUBTYPE;
}

int SqliteWrapper::constant_selforder1(void) {
    return SQLITE_SELFORDER1;
}

int SqliteWrapper::aggregate_count(Ref<Sqlite3ContextHandle> context) {
    ERR_FAIL_COND_V(context.is_null() || !context->is_valid(), 0);
    return sqlite3_aggregate_count(context->handle);
}

int SqliteWrapper::expired(Ref<Sqlite3StmtHandle> stmt) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), 0);
    return sqlite3_expired(stmt->handle);
}

int SqliteWrapper::transfer_bindings(Ref<Sqlite3StmtHandle> from_stmt, Ref<Sqlite3StmtHandle> to_stmt) {
    ERR_FAIL_COND_V(from_stmt.is_null() || !from_stmt->is_valid(), SQLITE_ERROR);
    ERR_FAIL_COND_V(to_stmt.is_null() || !to_stmt->is_valid(), SQLITE_ERROR);
    return sqlite3_transfer_bindings(from_stmt->handle, to_stmt->handle);
}

int SqliteWrapper::global_recover(void) {
    return sqlite3_global_recover();
}

void SqliteWrapper::thread_cleanup(void) {
    sqlite3_thread_cleanup();
}

int SqliteWrapper::memory_alarm(Callable callback, int64_t threshold) {
    ERR_FAIL_COND_V(!callback.is_valid(), SQLITE_ERROR);

    struct _AlarmCtx {
        Callable cb;
        int64_t threshold;
    } ctx{callback, threshold};

    auto trampoline = [](void* ptr, sqlite3_int64 current, int num) -> void {
        _AlarmCtx* ctx = (_AlarmCtx*)ptr;
        (void)(ctx);
        (void)(current);
        (void)(num);
        // Placeholder for callback implementation
    };

    return sqlite3_memory_alarm(trampoline, &ctx, threshold);
}

String SqliteWrapper::value_text(Ref<Sqlite3ValueHandle> value) {
    ERR_FAIL_COND_V(value.is_null() || !value->is_valid(), String());
    const unsigned char* text_ptr = sqlite3_value_text(value->handle);
    if (!text_ptr) {
        return String();
    }
    return String::utf8((const char*)text_ptr);
}

String SqliteWrapper::value_text16(Ref<Sqlite3ValueHandle> value) {
    ERR_FAIL_COND_V(value.is_null() || !value->is_valid(), String());
    const void* text16_ptr = sqlite3_value_text16(value->handle);
    if (!text16_ptr) {
        return String();
    }
    Char16String utf16_str = Char16String((const char16_t*)text16_ptr);
    return String(utf16_str);
}

String SqliteWrapper::value_text16le(Ref<Sqlite3ValueHandle> value) {
    ERR_FAIL_COND_V(value.is_null() || !value->is_valid(), String());
    const void* text16le_ptr = sqlite3_value_text16le(value->handle);
    if (!text16le_ptr) {
        return String();
    }
    Char16String utf16le_str = Char16String((const char16_t*)text16le_ptr);
    return String(utf16le_str);
}

String SqliteWrapper::value_text16be(Ref<Sqlite3ValueHandle> value) {
    ERR_FAIL_COND_V(value.is_null() || !value->is_valid(), String());
    const void* text16be_ptr = sqlite3_value_text16be(value->handle);
    if (!text16be_ptr) {
        return String();
    }
    Char16String utf16be_str = Char16String((const char16_t*)text16be_ptr);
    return String(utf16be_str);
}

int SqliteWrapper::value_bytes16(Ref<Sqlite3ValueHandle> value) {
    ERR_FAIL_COND_V(value.is_null() || !value->is_valid(), 0);
    return sqlite3_value_bytes16(value->handle);
}

int SqliteWrapper::value_type(Ref<Sqlite3ValueHandle> value) {
    ERR_FAIL_COND_V(value.is_null() || !value->is_valid(), SQLITE_NULL);
    return sqlite3_value_type(value->handle);
}

int SqliteWrapper::value_numeric_type(Ref<Sqlite3ValueHandle> value) {
    ERR_FAIL_COND_V(value.is_null() || !value->is_valid(), SQLITE_NULL);
    return sqlite3_value_numeric_type(value->handle);
}

int SqliteWrapper::value_nochange(Ref<Sqlite3ValueHandle> value) {
    ERR_FAIL_COND_V(value.is_null() || !value->is_valid(), 0);
    return sqlite3_value_nochange(value->handle);
}

int SqliteWrapper::value_frombind(Ref<Sqlite3ValueHandle> value) {
    ERR_FAIL_COND_V(value.is_null() || !value->is_valid(), 0);
    return sqlite3_value_frombind(value->handle);
}

int SqliteWrapper::value_encoding(Ref<Sqlite3ValueHandle> value) {
    ERR_FAIL_COND_V(value.is_null() || !value->is_valid(), 0);
    return sqlite3_value_encoding(value->handle);
}

uint32_t SqliteWrapper::value_subtype(Ref<Sqlite3ValueHandle> value) {
    ERR_FAIL_COND_V(value.is_null() || !value->is_valid(), 0);
    return (uint32_t)sqlite3_value_subtype(value->handle);
}

Ref<Sqlite3ValueHandle> SqliteWrapper::value_dup(Ref<Sqlite3ValueHandle> value) {
    ERR_FAIL_COND_V(value.is_null() || !value->is_valid(), Ref<Sqlite3ValueHandle>());
    sqlite3_value *duped = sqlite3_value_dup(value->handle);
    if (!duped) return Ref<Sqlite3ValueHandle>();
    Ref<Sqlite3ValueHandle> handle = Ref<Sqlite3ValueHandle>(memnew(Sqlite3ValueHandle()));
    handle->handle = duped;
    return handle;
}

uint64_t SqliteWrapper::aggregate_context(Ref<Sqlite3ContextHandle> context, int n_bytes) {
    ERR_FAIL_COND_V(context.is_null() || !context->is_valid(), 0);
    void *ptr = sqlite3_aggregate_context(context->handle, n_bytes);
    return reinterpret_cast<uint64_t>(ptr);
}

uint64_t SqliteWrapper::user_data(Ref<Sqlite3ContextHandle> context) {
    ERR_FAIL_COND_V(context.is_null() || !context->is_valid(), 0);
    void *ptr = sqlite3_user_data(context->handle);
    return reinterpret_cast<uint64_t>(ptr);
}

Ref<Sqlite3Handle> SqliteWrapper::context_db_handle(Ref<Sqlite3ContextHandle> context) {
    ERR_FAIL_COND_V(context.is_null() || !context->is_valid(), Ref<Sqlite3Handle>());
    sqlite3 *db = sqlite3_context_db_handle(context->handle);
    if (!db) return Ref<Sqlite3Handle>();
    Ref<Sqlite3Handle> handle = Ref<Sqlite3Handle>(memnew(Sqlite3Handle()));
    handle->handle = db;
    return handle;
}

uint64_t SqliteWrapper::get_auxdata(Ref<Sqlite3ContextHandle> context, int n) {
    ERR_FAIL_COND_V(context.is_null() || !context->is_valid(), 0);
    void *ptr = sqlite3_get_auxdata(context->handle, n);
    return reinterpret_cast<uint64_t>(ptr);
}

uint64_t SqliteWrapper::get_clientdata(Ref<Sqlite3Handle> db, String name) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), 0);
    void *ptr = sqlite3_get_clientdata(db->handle, name.utf8().get_data());
    return reinterpret_cast<uint64_t>(ptr);
}

void SqliteWrapper::result_error(Ref<Sqlite3ContextHandle> context, String message) {
    ERR_FAIL_COND(context.is_null() || !context->is_valid());
    String msg = message;
    CharString utf8_msg = msg.utf8();
    sqlite3_result_error(context->handle, utf8_msg.get_data(), -1);
}

void SqliteWrapper::result_error_toobig(Ref<Sqlite3ContextHandle> context) {
    ERR_FAIL_COND(context.is_null() || !context->is_valid());
    sqlite3_result_error_toobig(context->handle);
}

void SqliteWrapper::result_error_code(Ref<Sqlite3ContextHandle> context, int error_code) {
    ERR_FAIL_COND(context.is_null() || !context->is_valid());
    sqlite3_result_error_code(context->handle, error_code);
}

void SqliteWrapper::result_int(Ref<Sqlite3ContextHandle> context, int value) {
    ERR_FAIL_COND(context.is_null() || !context->is_valid());
    sqlite3_result_int(context->handle, value);
}

void SqliteWrapper::result_int64(Ref<Sqlite3ContextHandle> context, int64_t value) {
    ERR_FAIL_COND(context.is_null() || !context->is_valid());
    sqlite3_result_int64(context->handle, value);
}

void SqliteWrapper::result_null(Ref<Sqlite3ContextHandle> context) {
    ERR_FAIL_COND(context.is_null() || !context->is_valid());
    sqlite3_result_null(context->handle);
}

void SqliteWrapper::result_text(Ref<Sqlite3ContextHandle> context, String value) {
    ERR_FAIL_COND(context.is_null() || !context->is_valid());
    String val = value;
    CharString utf8_val = val.utf8();
    sqlite3_result_text(context->handle, utf8_val.get_data(), -1, SQLITE_TRANSIENT);
}

void SqliteWrapper::result_text64(Ref<Sqlite3ContextHandle> context, String value, int encoding) {
    ERR_FAIL_COND(context.is_null() || !context->is_valid());
    String val = value;
    CharString utf8_val = val.utf8();
    sqlite3_result_text64(context->handle, utf8_val.get_data(), (sqlite3_uint64)utf8_val.length(), SQLITE_TRANSIENT, (unsigned char)encoding);
}

void SqliteWrapper::result_text16(Ref<Sqlite3ContextHandle> context, String value) {
    ERR_FAIL_COND(context.is_null() || !context->is_valid());
    String val = value;
    Char16String utf16_val = val.utf16();
    sqlite3_result_text16(context->handle, utf16_val.ptr(), -1, SQLITE_TRANSIENT);
}

void SqliteWrapper::result_text16le(Ref<Sqlite3ContextHandle> context, String value) {
    ERR_FAIL_COND(context.is_null() || !context->is_valid());
    String val = value;
    Char16String utf16_val = val.utf16();
    sqlite3_result_text16le(context->handle, utf16_val.ptr(), -1, SQLITE_TRANSIENT);
}

void SqliteWrapper::result_text16be(Ref<Sqlite3ContextHandle> context, String value) {
    ERR_FAIL_COND(context.is_null() || !context->is_valid());
    String val = value;
    Char16String utf16_val = val.utf16();
    sqlite3_result_text16be(context->handle, utf16_val.ptr(), -1, SQLITE_TRANSIENT);
}

void SqliteWrapper::result_pointer(Ref<Sqlite3ContextHandle> context, uint64_t value, String type_name) {
    ERR_FAIL_COND(context.is_null() || !context->is_valid());
    sqlite3_result_pointer(context->handle, reinterpret_cast<void*>(value), type_name.utf8().get_data(), nullptr);
}

void SqliteWrapper::result_zeroblob(Ref<Sqlite3ContextHandle> context, int n) {
    ERR_FAIL_COND(context.is_null() || !context->is_valid());
    sqlite3_result_zeroblob(context->handle, n);
}

int SqliteWrapper::result_zeroblob64(Ref<Sqlite3ContextHandle> context, uint64_t n) {
    ERR_FAIL_COND_V(context.is_null() || !context->is_valid(), SQLITE_ERROR);
    return sqlite3_result_zeroblob64(context->handle, n);
}

void SqliteWrapper::result_subtype(Ref<Sqlite3ContextHandle> context, uint32_t subtype) {
    ERR_FAIL_COND(context.is_null() || !context->is_valid());
    sqlite3_result_subtype(context->handle, subtype);
}

int SqliteWrapper::create_collation(Ref<Sqlite3Handle> db, String name, int text_rep, Callable compare_func) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_ERROR);
    ERR_FAIL_COND_V(!compare_func.is_valid(), SQLITE_ERROR);

    struct _CollationCtx {
        Callable cb;
        int text_rep;
    } ctx{compare_func, text_rep};

    auto trampoline = [](void *ud, int len1, const void *data1, int len2, const void *data2) -> int {
        _CollationCtx *ctx = reinterpret_cast<_CollationCtx *>(ud);
        
        String str1, str2;
        
        // Convert based on text representation
        switch (ctx->text_rep) {
            case SQLITE_UTF8:
                str1 = len1 > 0 ? String::utf8((const char*)data1, len1) : String::utf8((const char*)data1);
                str2 = len2 > 0 ? String::utf8((const char*)data2, len2) : String::utf8((const char*)data2);
                break;
            case SQLITE_UTF16:
            case SQLITE_UTF16_ALIGNED:
            case SQLITE_UTF16LE:
            case SQLITE_UTF16BE: {
                const char16_t *ptr1 = (const char16_t*)data1;
                const char16_t *ptr2 = (const char16_t*)data2;
                // For simplicity, treat as native UTF-16
                str1 = len1 > 0 ? String::utf16(ptr1, len1/2) : String::utf16(ptr1);
                str2 = len2 > 0 ? String::utf16(ptr2, len2/2) : String::utf16(ptr2);
                break;
            }
            default:
                return SQLITE_ERROR;
        }
        
        Array args;
        args.push_back(str1);
        args.push_back(str2);
        
        Variant ret = ctx->cb.callv(args);
        if (ret.get_type() != Variant::INT) {
            UtilityFunctions::push_error("compare_func must return int, but got: " + ret.stringify() + " (" + Variant::get_type_name(ret.get_type()) + ")");
            return SQLITE_ERROR;
        }
        return int(ret);
    };

    return sqlite3_create_collation(db->handle, name.utf8().get_data(), text_rep, &ctx, trampoline);
}

int SqliteWrapper::create_collation16(Ref<Sqlite3Handle> db, String name, int text_rep, Callable compare_func) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_ERROR);
    ERR_FAIL_COND_V(!compare_func.is_valid(), SQLITE_ERROR);

    struct _CollationCtx {
        Callable cb;
        int text_rep;
    } ctx{compare_func, text_rep};

    auto trampoline = [](void *ud, int len1, const void *data1, int len2, const void *data2) -> int {
        _CollationCtx *ctx = reinterpret_cast<_CollationCtx *>(ud);
        
        String str1, str2;
        
        // Convert based on text representation
        switch (ctx->text_rep) {
            case SQLITE_UTF8:
                str1 = len1 > 0 ? String::utf8((const char*)data1, len1) : String::utf8((const char*)data1);
                str2 = len2 > 0 ? String::utf8((const char*)data2, len2) : String::utf8((const char*)data2);
                break;
            case SQLITE_UTF16:
            case SQLITE_UTF16_ALIGNED:
            case SQLITE_UTF16LE:
            case SQLITE_UTF16BE: {
                const char16_t *ptr1 = (const char16_t*)data1;
                const char16_t *ptr2 = (const char16_t*)data2;
                // For simplicity, treat as native UTF-16
                str1 = len1 > 0 ? String::utf16(ptr1, len1/2) : String::utf16(ptr1);
                str2 = len2 > 0 ? String::utf16(ptr2, len2/2) : String::utf16(ptr2);
                break;
            }
            default:
                return SQLITE_ERROR;
        }
        
        Array args;
        args.push_back(str1);
        args.push_back(str2);
        
        Variant ret = ctx->cb.callv(args);
        if (ret.get_type() != Variant::INT) {
            UtilityFunctions::push_error("compare_func must return int, but got: " + ret.stringify() + " (" + Variant::get_type_name(ret.get_type()) + ")");
            return SQLITE_ERROR;
        }
        return int(ret);
    };

    Char16String name_utf16 = name.utf16();
    return sqlite3_create_collation16(db->handle, name_utf16.ptr(), text_rep, &ctx, trampoline);
}

int SqliteWrapper::collation_needed(Ref<Sqlite3Handle> db, Callable callback) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_ERROR);
    ERR_FAIL_COND_V(!callback.is_valid(), SQLITE_ERROR);

    struct _CollationNeededCtx {
        Callable cb;
    } ctx{callback};

    auto trampoline = [](void *ud, sqlite3* db_conn, int eTextRep, const char* name) {
        _CollationNeededCtx *ctx = reinterpret_cast<_CollationNeededCtx *>(ud);
        
        Ref<Sqlite3Handle> handle;
        handle->handle = db_conn;
        
        String collation_name = String::utf8(name);
        
        Array args;
        args.push_back(handle);
        args.push_back(eTextRep);
        args.push_back(collation_name);
        
        ctx->cb.callv(args);
    };

    return sqlite3_collation_needed(db->handle, &ctx, trampoline);
}

void SqliteWrapper::activate_cerod(String passphrase) {
    #ifdef SQLITE_ENABLE_CEROD
        sqlite3_activate_cerod(passphrase.utf8().get_data());
    #else
        // CEROD is not enabled in this SQLite build
        // This function should not be called
        (void)(passphrase);
    #endif
}

int SqliteWrapper::sleep(int milliseconds) {
    return sqlite3_sleep(milliseconds);
}

Ref<Sqlite3Handle> SqliteWrapper::db_handle(Ref<Sqlite3StmtHandle> stmt) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), Ref<Sqlite3Handle>());
    Ref<Sqlite3Handle> db;
    sqlite3 *handle = sqlite3_db_handle(stmt->handle);
    if (handle != nullptr) {
        db->handle = handle;
    }
    return db;
}

String SqliteWrapper::db_name(Ref<Sqlite3Handle> db, int n) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), String());
    const char *name = sqlite3_db_name(db->handle, n);
    return name != nullptr ? String::utf8(name) : String();
}

String SqliteWrapper::db_filename(Ref<Sqlite3Handle> db, String db_name) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), String());
    CharString db_name_utf8 = db_name.utf8();
    const char *filename = sqlite3_db_filename(db->handle, db_name.length() > 0 ? db_name_utf8.get_data() : nullptr);
    return filename != nullptr ? String::utf8(filename) : String();
}

int SqliteWrapper::db_readonly(Ref<Sqlite3Handle> db, String db_name) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    return sqlite3_db_readonly(db->handle, db_name.length() > 0 ? db_name.utf8().get_data() : nullptr);
}

int SqliteWrapper::txn_state(Ref<Sqlite3Handle> db, String schema) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    return sqlite3_txn_state(db->handle, schema.length() > 0 ? schema.utf8().get_data() : nullptr);
}

int SqliteWrapper::constant_txn_none(void) {
    return SQLITE_TXN_NONE;
}

int SqliteWrapper::constant_txn_read(void) {
    return SQLITE_TXN_READ;
}

int SqliteWrapper::constant_txn_write(void) {
    return SQLITE_TXN_WRITE;
}

uint64_t SqliteWrapper::commit_hook(Ref<Sqlite3Handle> db, Callable callback, uint64_t user_data) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), 0);

    struct _CommitCtx {
        Callable cb;
        uint64_t ud;
    };

    static auto trampoline = [](void *ud) -> int {
        _CommitCtx *ctx = reinterpret_cast<_CommitCtx *>(ud);
        Variant ret = ctx->cb.callv(Array());
        if (ret.get_type() != Variant::INT) {
            UtilityFunctions::push_error("commit_hook callback must return int, but got: " + ret.stringify() + " (" + Variant::get_type_name(ret.get_type()) + ")");
            return 0;
        }
        return int(ret);
    };

    _CommitCtx *ctx = (_CommitCtx *)sqlite3_commit_hook(db->handle, trampoline, nullptr);
    uint64_t prev_ud = ctx ? ctx->ud : 0;

    if (callback.is_valid()) {
        ctx = new _CommitCtx{callback, user_data};
        sqlite3_commit_hook(db->handle, trampoline, ctx);
    } else {
        sqlite3_commit_hook(db->handle, nullptr, nullptr);
    }

    return prev_ud;
}

int SqliteWrapper::autovacuum_pages(Ref<Sqlite3Handle> db, Callable callback, uint64_t user_data) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);

    struct _AutovacCtx {
        Callable cb;
        uint64_t ud;
    };

    static auto trampoline = [](void *ud, const char *zSchema, unsigned int nDbPage, unsigned int nFreePage, unsigned int nBytePerPage) -> unsigned int {
        _AutovacCtx *ctx = reinterpret_cast<_AutovacCtx *>(ud);
        
        Array args;
        args.push_back(String::utf8(zSchema));
        args.push_back(int64_t(nDbPage));
        args.push_back(int64_t(nFreePage));
        args.push_back(int64_t(nBytePerPage));
        
        Variant ret = ctx->cb.callv(args);
        if (ret.get_type() != Variant::INT) {
            UtilityFunctions::push_error("autovacuum_pages callback must return int, but got: " + ret.stringify() + " (" + Variant::get_type_name(ret.get_type()) + ")");
            return 0;
        }
        return static_cast<unsigned int>(ret);
    };

    if (callback.is_valid()) {
        _AutovacCtx *ctx = new _AutovacCtx{callback, user_data};
        int result = sqlite3_autovacuum_pages(db->handle, trampoline, ctx, nullptr);
        if (result != 0) {
            delete ctx;
            return result;
        }
    } else {
        sqlite3_autovacuum_pages(db->handle, nullptr, nullptr, nullptr);
    }

    return 0;
}

uint64_t SqliteWrapper::update_hook(Ref<Sqlite3Handle> db, Callable callback, uint64_t user_data) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), 0);

    struct _UpdateCtx {
        Callable cb;
        uint64_t ud;
    };

    static auto trampoline = [](void *ud, int op, char const *db_name, char const *table_name, sqlite3_int64 rowid) {
        _UpdateCtx *ctx = reinterpret_cast<_UpdateCtx *>(ud);
        
        Array args;
        args.push_back(op);
        args.push_back(String::utf8(db_name));
        args.push_back(String::utf8(table_name));
        args.push_back(int64_t(rowid));
        
        ctx->cb.callv(args);
    };

    _UpdateCtx *ctx = (_UpdateCtx *)sqlite3_update_hook(db->handle, nullptr, nullptr);
    uint64_t prev_ud = ctx ? ctx->ud : 0;

    if (callback.is_valid()) {
        ctx = new _UpdateCtx{callback, user_data};
        sqlite3_update_hook(db->handle, trampoline, ctx);
    } else {
        sqlite3_update_hook(db->handle, nullptr, nullptr);
    }

    return prev_ud;
}

int SqliteWrapper::enable_shared_cache(bool enable) {
    return sqlite3_enable_shared_cache(enable ? 1 : 0);
}

Dictionary SqliteWrapper::table_column_metadata(Ref<Sqlite3Handle> db, String database_name, String table_name, String column_name) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), Dictionary());

    const char *data_type = nullptr;
    const char *coll_seq = nullptr;
    int not_null = 0;
    int primary_key = 0;
    int autoinc = 0;

    int result = sqlite3_table_column_metadata(
        db->handle,
        database_name.utf8().get_data(),
        table_name.utf8().get_data(),
        column_name.utf8().get_data(),
        &data_type,
        &coll_seq,
        &not_null,
        &primary_key,
        &autoinc
    );

    if (result != SQLITE_OK) {
        return Dictionary();
    }

    Dictionary metadata;
    metadata["data_type"] = data_type ? String::utf8(data_type) : String();
    metadata["collation_sequence"] = coll_seq ? String::utf8(coll_seq) : String();
    metadata["not_null"] = not_null != 0;
    metadata["primary_key"] = primary_key != 0;
    metadata["auto_increment"] = autoinc != 0;

    return metadata;
}

int SqliteWrapper::enable_load_extension(Ref<Sqlite3Handle> db, bool enable) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    return sqlite3_enable_load_extension(db->handle, enable ? 1 : 0);
}

int SqliteWrapper::auto_extension(Callable entry_point) {
    ERR_FAIL_COND_V(!entry_point.is_valid(), SQLITE_MISUSE);

    // Note: This function uses a C language trick where the function pointer
    // is declared with one signature but called with another. The full functionality
    // is not easily translatable to higher-level languages. For now, we'll just return SQLITE_OK.
    return SQLITE_OK;
}

int SqliteWrapper::overload_function(Ref<Sqlite3Handle> db, String func_name, int n_arg) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);

    int result = sqlite3_overload_function(db->handle, func_name.utf8().get_data(), n_arg);

    return result;
}

int SqliteWrapper::blob_reopen(Ref<Sqlite3BlobHandle> blob, int64_t row_id) {
    ERR_FAIL_COND_V(blob.is_null() || !blob->is_valid(), -1);

    int result = sqlite3_blob_reopen(blob->handle, row_id);

    return result;
}

int SqliteWrapper::blob_close(Ref<Sqlite3BlobHandle> blob) {
    if (blob.is_null() || !blob->is_valid()) {
        return SQLITE_OK; // harmless no-op for null or invalid handle
    }

    int result = sqlite3_blob_close(blob->handle);
    blob->handle = nullptr;
    return result;
}

int SqliteWrapper::blob_bytes(Ref<Sqlite3BlobHandle> blob) {
    ERR_FAIL_COND_V(blob.is_null() || !blob->is_valid(), -1);

    return sqlite3_blob_bytes(blob->handle);
}

PackedByteArray SqliteWrapper::blob_read(Ref<Sqlite3BlobHandle> blob, int size, int offset) {
    ERR_FAIL_COND_V(blob.is_null() || !blob->is_valid(), PackedByteArray());
    ERR_FAIL_COND_V(size < 0, PackedByteArray());
    ERR_FAIL_COND_V(offset < 0, PackedByteArray());

    int blob_size = sqlite3_blob_bytes(blob->handle);
    ERR_FAIL_COND_V(offset > blob_size, PackedByteArray());
    ERR_FAIL_COND_V(offset + size > blob_size, PackedByteArray());

    PackedByteArray buffer;
    buffer.resize(size);
    if (size > 0) {
        uint8_t *w = buffer.ptrw();
        int result = sqlite3_blob_read(blob->handle, w, size, offset);
        ERR_FAIL_COND_V(result != SQLITE_OK, PackedByteArray());
    }

    return buffer;
}

int SqliteWrapper::blob_write(Ref<Sqlite3BlobHandle> blob, PackedByteArray data, int offset) {
    ERR_FAIL_COND_V(blob.is_null() || !blob->is_valid(), SQLITE_MISUSE);
    ERR_FAIL_COND_V(offset < 0, SQLITE_ERROR);

    int data_size = data.size();
    ERR_FAIL_COND_V(data_size < 0, SQLITE_ERROR);

    int blob_size = sqlite3_blob_bytes(blob->handle);
    ERR_FAIL_COND_V(offset > blob_size, SQLITE_ERROR);
    ERR_FAIL_COND_V(offset + data_size > blob_size, SQLITE_ERROR);

    int result = SQLITE_OK;
    if (data_size > 0) {
        const uint8_t *r = data.ptr();
        result = sqlite3_blob_write(blob->handle, r, data_size, offset);
    }

    return result;
}

Ref<Sqlite3VfsHandle> SqliteWrapper::vfs_find(String vfs_name) {
    sqlite3_vfs *vfs = sqlite3_vfs_find(vfs_name.utf8().get_data());

    Ref<Sqlite3VfsHandle> handle = Ref<Sqlite3VfsHandle>(memnew(Sqlite3VfsHandle));
    handle->handle = vfs;
    return handle;
}

bool SqliteWrapper::mutex_held(Ref<Sqlite3MutexHandle> mutex) {
    ERR_FAIL_COND_V(mutex.is_null() || !mutex->is_valid(), true);
#ifdef SQLITE_DEBUG
    return bool(sqlite3_mutex_held(mutex->handle));
#else
    return true;
#endif
}

bool SqliteWrapper::mutex_notheld(Ref<Sqlite3MutexHandle> mutex) {
    ERR_FAIL_COND_V(mutex.is_null() || !mutex->is_valid(), true);
#ifdef SQLITE_DEBUG
    return bool(sqlite3_mutex_notheld(mutex->handle));
#else
    return true;
#endif
}

int SqliteWrapper::mutex_fast(void) {
    return SQLITE_MUTEX_FAST;
}

int SqliteWrapper::mutex_recursive(void) {
    return SQLITE_MUTEX_RECURSIVE;
}

int SqliteWrapper::mutex_static_main(void) {
    return SQLITE_MUTEX_STATIC_MAIN;
}

int SqliteWrapper::mutex_static_mem(void) {
    return SQLITE_MUTEX_STATIC_MEM;
}

int SqliteWrapper::mutex_static_mem2(void) {
    return SQLITE_MUTEX_STATIC_MEM2;
}

int SqliteWrapper::mutex_static_open(void) {
    return SQLITE_MUTEX_STATIC_OPEN;
}

int SqliteWrapper::mutex_static_prng(void) {
    return SQLITE_MUTEX_STATIC_PRNG;
}

int SqliteWrapper::mutex_static_lru(void) {
    return SQLITE_MUTEX_STATIC_LRU;
}

int SqliteWrapper::mutex_static_lru2(void) {
    return SQLITE_MUTEX_STATIC_LRU2;
}

int SqliteWrapper::mutex_static_pmem(void) {
    return SQLITE_MUTEX_STATIC_PMEM;
}

int SqliteWrapper::mutex_static_app1(void) {
    return SQLITE_MUTEX_STATIC_APP1;
}

int SqliteWrapper::mutex_static_app2(void) {
    return SQLITE_MUTEX_STATIC_APP2;
}

int SqliteWrapper::mutex_static_app3(void) {
    return SQLITE_MUTEX_STATIC_APP3;
}

int SqliteWrapper::mutex_static_vfs1(void) {
    return SQLITE_MUTEX_STATIC_VFS1;
}

int SqliteWrapper::mutex_static_vfs2(void) {
    return SQLITE_MUTEX_STATIC_VFS2;
}

int SqliteWrapper::mutex_static_vfs3(void) {
    return SQLITE_MUTEX_STATIC_VFS3;
}

int SqliteWrapper::mutex_static_master(void) {
    return SQLITE_MUTEX_STATIC_MASTER;
}

int SqliteWrapper::file_control(Ref<Sqlite3Handle> db, String db_name, int op, int64_t arg) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_ERROR);
    CharString db_name_utf8 = db_name.utf8();
    const char * db_name_cstr = db_name.is_empty() ? "main" : db_name_utf8.get_data();
    return sqlite3_file_control(db->handle, db_name_cstr, op, reinterpret_cast<void*>(arg));
}

int SqliteWrapper::test_control(int op) {
    return sqlite3_test_control(op);
}

String SqliteWrapper::str_finish(Ref<Sqlite3StrHandle> str) {
    ERR_FAIL_COND_V(str.is_null() || !str->is_valid(), String());
    char *result = sqlite3_str_finish(str->handle);
    String gd_result = result ? String::utf8(result) : String();
    if (result) {
        sqlite3_free(result);
    }
    return gd_result;
}

int SqliteWrapper::db_status_lookaside_used(void) {
    return SQLITE_DBSTATUS_LOOKASIDE_USED;
}

int SqliteWrapper::db_status_cache_used(void) {
    return SQLITE_DBSTATUS_CACHE_USED;
}

int SqliteWrapper::db_status_schema_used(void) {
    return SQLITE_DBSTATUS_SCHEMA_USED;
}

int SqliteWrapper::db_status_stmt_used(void) {
    return SQLITE_DBSTATUS_STMT_USED;
}

int SqliteWrapper::db_status_lookaside_hit(void) {
    return SQLITE_DBSTATUS_LOOKASIDE_HIT;
}

int SqliteWrapper::db_status_lookaside_miss_size(void) {
    return SQLITE_DBSTATUS_LOOKASIDE_MISS_SIZE;
}

int SqliteWrapper::db_status_lookaside_miss_full(void) {
    return SQLITE_DBSTATUS_LOOKASIDE_MISS_FULL;
}

int SqliteWrapper::db_status_cache_hit(void) {
    return SQLITE_DBSTATUS_CACHE_HIT;
}

int SqliteWrapper::db_status_cache_miss(void) {
    return SQLITE_DBSTATUS_CACHE_MISS;
}

int SqliteWrapper::db_status_cache_write(void) {
    return SQLITE_DBSTATUS_CACHE_WRITE;
}

int SqliteWrapper::db_status_deferred_fks(void) {
    return SQLITE_DBSTATUS_DEFERRED_FKS;
}

int SqliteWrapper::db_status_cache_used_shared(void) {
    return SQLITE_DBSTATUS_CACHE_USED_SHARED;
}

int SqliteWrapper::db_status_cache_spill(void) {
    return SQLITE_DBSTATUS_CACHE_SPILL;
}

int SqliteWrapper::db_status_tempbuf_spill(void) {
    return SQLITE_DBSTATUS_TEMPBUF_SPILL;
}

int SqliteWrapper::stmtstatus_fullscan_step(void) {
    return SQLITE_STMTSTATUS_FULLSCAN_STEP;
}

int SqliteWrapper::stmtstatus_sort(void) {
    return SQLITE_STMTSTATUS_SORT;
}

int SqliteWrapper::stmtstatus_autoindex(void) {
    return SQLITE_STMTSTATUS_AUTOINDEX;
}

int SqliteWrapper::stmtstatus_vm_step(void) {
    return SQLITE_STMTSTATUS_VM_STEP;
}

int SqliteWrapper::stmtstatus_reprepare(void) {
    return SQLITE_STMTSTATUS_REPREPARE;
}

int SqliteWrapper::stmtstatus_run(void) {
    return SQLITE_STMTSTATUS_RUN;
}

int SqliteWrapper::stmtstatus_filter_miss(void) {
    return SQLITE_STMTSTATUS_FILTER_MISS;
}

int SqliteWrapper::stmtstatus_filter_hit(void) {
    return SQLITE_STMTSTATUS_FILTER_HIT;
}

int SqliteWrapper::stmtstatus_memused(void) {
    return SQLITE_STMTSTATUS_MEMUSED;
}

int SqliteWrapper::backup_pagecount(Ref<Sqlite3BackupHandle> backup) {
    ERR_FAIL_COND_V(backup.is_null() || !backup->is_valid(), -1);
    return sqlite3_backup_pagecount(backup->handle);
}

int SqliteWrapper::str_icmp(String a, String b) {
    return sqlite3_stricmp(a.utf8().get_data(), b.utf8().get_data());
}

int SqliteWrapper::wal_autocheckpoint(Ref<Sqlite3Handle> db, int threshold) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_MISUSE);
    return sqlite3_wal_autocheckpoint(db->handle, threshold);
}

int SqliteWrapper::wal_checkpoint(Ref<Sqlite3Handle> db, String database_name) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_MISUSE);
    CharString database_name_utf8 = database_name.utf8();
    const char* db_name = database_name_utf8.get_data();
    return sqlite3_wal_checkpoint(db->handle, db_name);
}

Array SqliteWrapper::wal_checkpoint_v2(Ref<Sqlite3Handle> db, String database_name, int mode) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), Array());

    int log_size = 0;
    int ckpt_frames = 0;

    CharString database_name_utf8 = database_name.utf8();
    const char* db_name = database_name_utf8.get_data();
    int result = sqlite3_wal_checkpoint_v2(db->handle, db_name, mode, &log_size, &ckpt_frames);

    Array result_array;
    result_array.push_back(result);
    result_array.push_back(log_size);
    result_array.push_back(ckpt_frames);

    return result_array;
}

int SqliteWrapper::checkpoint_noop(void) {
    return SQLITE_CHECKPOINT_NOOP;
}

int SqliteWrapper::checkpoint_passive(void) {
    return SQLITE_CHECKPOINT_PASSIVE;
}

int SqliteWrapper::checkpoint_full(void) {
    return SQLITE_CHECKPOINT_FULL;
}

int SqliteWrapper::checkpoint_restart(void) {
    return SQLITE_CHECKPOINT_RESTART;
}

int SqliteWrapper::checkpoint_truncate(void) {
    return SQLITE_CHECKPOINT_TRUNCATE;
}

int SqliteWrapper::vtab_constraint_support(void) {
    return SQLITE_VTAB_CONSTRAINT_SUPPORT;
}

int SqliteWrapper::vtab_innocuous(void) {
    return SQLITE_VTAB_INNOCUOUS;
}

int SqliteWrapper::vtab_directonly(void) {
    return SQLITE_VTAB_DIRECTONLY;
}

int SqliteWrapper::vtab_uses_all_schemas(void) {
    return SQLITE_VTAB_USES_ALL_SCHEMAS;
}

bool SqliteWrapper::vtab_nochange(Ref<Sqlite3ContextHandle> context) {
    ERR_FAIL_COND_V(context.is_null() || !context->is_valid(), false);
    return sqlite3_vtab_nochange(context->handle) != 0;
}

String SqliteWrapper::vtab_collation(Ref<Sqlite3IndexInfoHandle> info, int idx) {
    ERR_FAIL_COND_V(info.is_null() || !info->is_valid(), String());
    const char* result = sqlite3_vtab_collation(info->handle, idx);
    return String::utf8(result);
}

int SqliteWrapper::vtab_rhs_value(Ref<Sqlite3IndexInfoHandle> info, int idx, Ref<Sqlite3ValueHandle> out_value) {
    ERR_FAIL_COND_V(info.is_null() || !info->is_valid(), SQLITE_MISUSE);
    ERR_FAIL_COND_V(out_value.is_null(), SQLITE_MISUSE);

    sqlite3_value* out_ptr = nullptr;
    int result = sqlite3_vtab_rhs_value(info->handle, idx, &out_ptr);
    out_value->handle = out_ptr;
    return result;
}

#if 0
int SqliteWrapper::stmt_scanstatus_v2(Ref<Sqlite3StmtHandle> stmt, int idx, int scan_status_op, int flags, Variant out_value) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), SQLITE_MISUSE);

    // Note: This is a simplified wrapper. The actual sqlite3_stmt_scanstatus_v2 function
    // writes to a void* pointer, with the type depending on scan_status_op.
    // For production use, consider implementing operation-specific wrappers.
    // This wrapper only supports the statement handle and index; the scan_status_op,
    // flags, and out_value parameters are placeholders and not used in this simplified version.
    return sqlite3_stmt_scanstatus_v2(stmt->handle, idx, scan_status_op, flags, nullptr);
}

void SqliteWrapper::stmt_scanstatus_reset(Ref<Sqlite3StmtHandle> stmt) {
    ERR_FAIL_COND(stmt.is_null() || !stmt->is_valid());
    sqlite3_stmt_scanstatus_reset(stmt->handle);
}
#endif

int SqliteWrapper::db_cacheflush(Ref<Sqlite3Handle> db) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), SQLITE_MISUSE);
    return sqlite3_db_cacheflush(db->handle);
}

Variant SqliteWrapper::preupdate_hook(Ref<Sqlite3Handle> db, Callable callback) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), Variant());

    struct _PreupdateCtx {
        Callable cb;
        static void trampoline(void *pCtx, sqlite3 *db, int op, const char *zDb, const char *zName, sqlite3_int64 iKey1, sqlite3_int64 iKey2) {
            _PreupdateCtx *ctx = (_PreupdateCtx *)pCtx;
            
            if (!ctx->cb.is_valid()) return;
            
            String db_name = zDb ? String::utf8(zDb) : String();
            String table_name = zName ? String::utf8(zName) : String();
            
            int col_count = sqlite3_preupdate_count(db);
            
            Array old_values;
            Array new_values;
            
            for (int i = 0; i < col_count; i++) {
                sqlite3_value *old_val = nullptr;
                sqlite3_value *new_val = nullptr;
                
                if (op == SQLITE_UPDATE || op == SQLITE_DELETE) {
                    sqlite3_preupdate_old(db, i, &old_val);
                }
                if (op == SQLITE_INSERT || op == SQLITE_UPDATE) {
                    sqlite3_preupdate_new(db, i, &new_val);
                }
                
                // Convert old value
                if (old_val) {
                    int type = sqlite3_value_type(old_val);
                    if (type == SQLITE_NULL) {
                        old_values.push_back(Variant());
                    } else if (type == SQLITE_TEXT) {
                        old_values.push_back(String::utf8((const char*)sqlite3_value_text(old_val)));
                    } else if (type == SQLITE_INTEGER) {
                        old_values.push_back((int64_t)sqlite3_value_int64(old_val));
                    } else if (type == SQLITE_FLOAT) {
                        old_values.push_back(sqlite3_value_double(old_val));
                    } else if (type == SQLITE_BLOB) {
                        int len = sqlite3_value_bytes(old_val);
                        const void *blob = sqlite3_value_blob(old_val);
                        PackedByteArray pba;
                        pba.resize(len);
                        memcpy(pba.ptrw(), blob, len);
                        old_values.push_back(pba);
                    }
                } else {
                    old_values.push_back(Variant());
                }
                
                // Convert new value
                if (new_val) {
                    int type = sqlite3_value_type(new_val);
                    if (type == SQLITE_NULL) {
                        new_values.push_back(Variant());
                    } else if (type == SQLITE_TEXT) {
                        new_values.push_back(String::utf8((const char*)sqlite3_value_text(new_val)));
                    } else if (type == SQLITE_INTEGER) {
                        new_values.push_back((int64_t)sqlite3_value_int64(new_val));
                    } else if (type == SQLITE_FLOAT) {
                        new_values.push_back(sqlite3_value_double(new_val));
                    } else if (type == SQLITE_BLOB) {
                        int len = sqlite3_value_bytes(new_val);
                        const void *blob = sqlite3_value_blob(new_val);
                        PackedByteArray pba;
                        pba.resize(len);
                        memcpy(pba.ptrw(), blob, len);
                        new_values.push_back(pba);
                    }
                } else {
                    new_values.push_back(Variant());
                }
            }
            
            Array args;
            args.push_back(op);
            args.push_back(db_name);
            args.push_back(table_name);
            args.push_back((int64_t)iKey1);
            args.push_back((int64_t)iKey2);
            args.push_back(old_values);
            args.push_back(new_values);
            
            ctx->cb.callv(args);
        }
    };

    _PreupdateCtx *ctx = new _PreupdateCtx{callback};
    void *prev = sqlite3_preupdate_hook(db->handle, _PreupdateCtx::trampoline, ctx);
    if (prev != nullptr && prev != ctx) {
        delete ctx;
    }
    return Variant();
}

int SqliteWrapper::preupdate_count(Ref<Sqlite3Handle> db) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    return sqlite3_preupdate_count(db->handle);
}

int SqliteWrapper::preupdate_depth(Ref<Sqlite3Handle> db) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    return sqlite3_preupdate_depth(db->handle);
}

Variant SqliteWrapper::preupdate_old(Ref<Sqlite3Handle> db, int column_index) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), Variant());
    ERR_FAIL_COND_V(column_index < 0, Variant());
    sqlite3_value *val = nullptr;
    int res = sqlite3_preupdate_old(db->handle, column_index, &val);
    ERR_FAIL_COND_V(res != SQLITE_OK, Variant());
    if (!val) return Variant();
    int type = sqlite3_value_type(val);
    if (type == SQLITE_NULL) return Variant();
    if (type == SQLITE_TEXT) return String::utf8((const char*)sqlite3_value_text(val));
    if (type == SQLITE_INTEGER) return (int64_t)sqlite3_value_int64(val);
    if (type == SQLITE_FLOAT) return sqlite3_value_double(val);
    if (type == SQLITE_BLOB) {
        int len = sqlite3_value_bytes(val);
        const void *blob = sqlite3_value_blob(val);
        PackedByteArray pba;
        pba.resize(len);
        memcpy(pba.ptrw(), blob, len);
        return pba;
    }
    return Variant();
}

Variant SqliteWrapper::preupdate_new(Ref<Sqlite3Handle> db, int column_index) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), Variant());
    ERR_FAIL_COND_V(column_index < 0, Variant());
    sqlite3_value *val = nullptr;
    int res = sqlite3_preupdate_new(db->handle, column_index, &val);
    ERR_FAIL_COND_V(res != SQLITE_OK, Variant());
    if (!val) return Variant();
    int type = sqlite3_value_type(val);
    if (type == SQLITE_NULL) return Variant();
    if (type == SQLITE_TEXT) return String::utf8((const char*)sqlite3_value_text(val));
    if (type == SQLITE_INTEGER) return (int64_t)sqlite3_value_int64(val);
    if (type == SQLITE_FLOAT) return sqlite3_value_double(val);
    if (type == SQLITE_BLOB) {
        int len = sqlite3_value_bytes(val);
        const void *blob = sqlite3_value_blob(val);
        PackedByteArray pba;
        pba.resize(len);
        memcpy(pba.ptrw(), blob, len);
        return pba;
    }
    return Variant();
}

int SqliteWrapper::preupdate_blobwrite(Ref<Sqlite3Handle> db) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    return sqlite3_preupdate_blobwrite(db->handle);
}

int SqliteWrapper::system_errno(Ref<Sqlite3Handle> db) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    return sqlite3_system_errno(db->handle);
}

PackedByteArray SqliteWrapper::serialize(Ref<Sqlite3Handle> db, String schema, int flags) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), PackedByteArray());

    sqlite3_int64 size_storage = 0;
    unsigned char *data = sqlite3_serialize(db->handle, schema.utf8().get_data(), &size_storage, (unsigned int)flags);
    if (data == nullptr) {
        return PackedByteArray();
    }

    int64_t final_size = size_storage;
    PackedByteArray ba;
    ba.resize(final_size);
    memcpy(ba.ptrw(), data, final_size);

    if (!(flags & SQLITE_SERIALIZE_NOCOPY)) {
        sqlite3_free(data);
    }

    return ba;
}

int SqliteWrapper::serialize_flag_nocopy(void) {
    return SQLITE_SERIALIZE_NOCOPY;
}

int SqliteWrapper::deserialize_flag_freeonclose(void) {
    return SQLITE_DESERIALIZE_FREEONCLOSE;
}

int SqliteWrapper::deserialize_flag_resizeable(void) {
    return SQLITE_DESERIALIZE_RESIZEABLE;
}

int SqliteWrapper::deserialize_flag_readonly(void) {
    return SQLITE_DESERIALIZE_READONLY;
}

#if 0
int SqliteWrapper::carray_bind(Ref<Sqlite3StmtHandle> stmt, int index, PackedByteArray data, int n_data, int flags) {
    ERR_FAIL_COND_V(stmt.is_null() || !stmt->is_valid(), -1);

    const uint8_t *ptr = data.ptr();
    return sqlite3_carray_bind(stmt->handle, index, (void*)ptr, n_data, flags, nullptr);
}
#endif

int SqliteWrapper::carray_type_int32(void) {
    return SQLITE_CARRAY_INT32;
}

int SqliteWrapper::carray_type_int64(void) {
    return SQLITE_CARRAY_INT64;
}

int SqliteWrapper::carray_type_double(void) {
    return SQLITE_CARRAY_DOUBLE;
}

int SqliteWrapper::carray_type_text(void) {
    return SQLITE_CARRAY_TEXT;
}

int SqliteWrapper::carray_type_blob(void) {
    return SQLITE_CARRAY_BLOB;
}

void SqliteWrapper::session_delete(Ref<Sqlite3SessionHandle> session) {
    ERR_FAIL_COND(session.is_null() || !session->is_valid());
    sqlite3session_delete(session->handle);
    session->handle = nullptr;
}

Ref<Sqlite3MutexHandle> SqliteWrapper::mutex_alloc(int type) {
    sqlite3_mutex *mutex = sqlite3_mutex_alloc(type);
    Ref<Sqlite3MutexHandle> handle = Ref<Sqlite3MutexHandle>(memnew(Sqlite3MutexHandle));
    handle->handle = mutex;
    return handle;
}

void SqliteWrapper::str_appendf(Ref<Sqlite3StrHandle> str, String format) {
    ERR_FAIL_COND(str.is_null() || !str->is_valid());
    CharString cs = format.utf8();
    sqlite3_str_appendf(str->handle, cs.get_data());
}

int SqliteWrapper::str_errcode(Ref<Sqlite3StrHandle> str) {
    ERR_FAIL_COND_V(str.is_null() || !str->is_valid(), SQLITE_ERROR);
    return sqlite3_str_errcode(str->handle);
}

Dictionary SqliteWrapper::status(int op, int reset_flag) {
    int current = 0;
    int highwater = 0;
    int result = sqlite3_status(op, &current, &highwater, reset_flag);
    if (result != SQLITE_OK) {
        return Dictionary();
    }
    Dictionary result_dict;
    result_dict["current"] = current;
    result_dict["highwater"] = highwater;
    return result_dict;
}

int SqliteWrapper::snapshot_open(Ref<Sqlite3Handle> db, String schema, Ref<Sqlite3SnapshotHandle> snapshot) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    ERR_FAIL_COND_V(snapshot.is_null() || !snapshot->is_valid(), -1);

    return sqlite3_snapshot_open(db->handle, schema.utf8().get_data(), snapshot->handle);
}

int SqliteWrapper::snapshot_cmp(Ref<Sqlite3SnapshotHandle> p1, Ref<Sqlite3SnapshotHandle> p2) {
    ERR_FAIL_COND_V(!p1->is_valid() || !p2->is_valid(), -1);
    return sqlite3_snapshot_cmp(p1->handle, p2->handle);
}

int SqliteWrapper::snapshot_recover(Ref<Sqlite3Handle> db, String schema) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    return sqlite3_snapshot_recover(db->handle, schema.utf8().get_data());
}

int SqliteWrapper::session_object_config(Ref<Sqlite3SessionHandle> session, int op, int64_t p_arg) {
    ERR_FAIL_COND_V(session.is_null() || !session->is_valid(), -1);
    void *arg = reinterpret_cast<void*>(static_cast<intptr_t>(p_arg));
    return sqlite3session_object_config(session->handle, op, arg);
}

int SqliteWrapper::session_objconfig_size(void) {
    return SQLITE_SESSION_OBJCONFIG_SIZE;
}

int SqliteWrapper::session_objconfig_rowid(void) {
    return SQLITE_SESSION_OBJCONFIG_ROWID;
}

int SqliteWrapper::session_indirect(Ref<Sqlite3SessionHandle> session, int b_indirect) {
    ERR_FAIL_COND_V(session.is_null() || !session->is_valid(), -1);
    return sqlite3session_indirect(session->handle, b_indirect);
}

int SqliteWrapper::session_attach(Ref<Sqlite3SessionHandle> session, String z_tab) {
    ERR_FAIL_COND_V(session.is_null() || !session->is_valid(), -1);
    CharString z_tab_utf8 = z_tab.utf8();
    const char * tab = z_tab.is_empty() ? nullptr : z_tab_utf8.get_data();
    return sqlite3session_attach(session->handle, tab);
}

void SqliteWrapper::session_table_filter(Ref<Sqlite3SessionHandle> session, Callable filter) {
    ERR_FAIL_COND(session.is_null() || !session->is_valid());
    ERR_FAIL_COND(!filter.is_valid());

    struct _FilterCtx {
        Callable cb;
    } ctx{filter};

    auto trampoline = [](void *ud, const char *zTab) -> int {
        _FilterCtx *ctx = reinterpret_cast<_FilterCtx*>(ud);
        String table_name = zTab ? String::utf8(zTab) : String();
        Array args;
        args.push_back(table_name);
        Variant ret = ctx->cb.callv(args);
        if (ret.get_type() != Variant::INT) {
            UtilityFunctions::push_error("filter must return int, but got: " + ret.stringify());
            return 1; // Default to track if error
        }
        return int(ret);
    };

    sqlite3session_table_filter(session->handle, trampoline, &ctx);
}

int SqliteWrapper::session_changeset(Ref<Sqlite3SessionHandle> session, PackedByteArray out_changeset, int out_size) {
    ERR_FAIL_COND_V(session.is_null() || !session->is_valid(), -1);

    int size = 0;
    void *changeset = nullptr;
    int result = sqlite3session_changeset(session->handle, &size, &changeset);

    if (result == SQLITE_OK && changeset != nullptr) {
        if (size > 0) {
            out_changeset.resize(size);
            memcpy(out_changeset.ptrw(), changeset, size);
        } else {
            out_changeset.clear();
        }
        sqlite3_free(changeset);
    } else {
        out_changeset.clear();
    }
    out_size = size;
    return result;
}

int64_t SqliteWrapper::session_changeset_size(Ref<Sqlite3SessionHandle> session) {
    ERR_FAIL_COND_V(session.is_null() || !session->is_valid(), -1);
    return sqlite3session_changeset_size(session->handle);
}

int SqliteWrapper::session_diff(Ref<Sqlite3SessionHandle> session, String z_from_db, String z_tbl, String out_error) {
    ERR_FAIL_COND_V(session.is_null() || !session->is_valid(), -1);

    char *errmsg = nullptr;
    int result = sqlite3session_diff(session->handle, z_from_db.utf8().get_data(), z_tbl.utf8().get_data(), &errmsg);

    if (errmsg != nullptr) {
        out_error = String::utf8(errmsg);
        sqlite3_free(errmsg);
    } else {
        out_error = String();
    }

    return result;
}

int SqliteWrapper::session_patchset(Ref<Sqlite3SessionHandle> session, PackedByteArray out_patchset, int out_size) {
    ERR_FAIL_COND_V(session.is_null() || !session->is_valid(), -1);

    int size = 0;
    void *patchset = nullptr;
    int result = sqlite3session_patchset(session->handle, &size, &patchset);

    if (result == SQLITE_OK && patchset != nullptr) {
        if (size > 0) {
            out_patchset.resize(size);
            memcpy(out_patchset.ptrw(), patchset, size);
        } else {
            out_patchset.clear();
        }
        sqlite3_free(patchset);
    } else {
        out_patchset.clear();
    }
    out_size = size;
    return result;
}

bool SqliteWrapper::session_isempty(Ref<Sqlite3SessionHandle> session) {
    ERR_FAIL_COND_V(session.is_null() || !session->is_valid(), true);
    return sqlite3session_isempty(session->handle) != 0;
}

int SqliteWrapper::changeset_start(Ref<Sqlite3ChangesetIterHandle> out_iter, PackedByteArray changeset) {
    ERR_FAIL_COND_V(out_iter.is_null(), -1);
    ERR_FAIL_COND_V(changeset.is_empty(), -1);

    const void *cptr = changeset.ptr();
    void *ptr = const_cast<void*>(cptr);

    sqlite3_changeset_iter *iter = nullptr;
    int result = sqlite3changeset_start(&iter, changeset.size(), ptr);
    if (result == SQLITE_OK) {
        out_iter->handle = iter;
    }
    return result;
}

int SqliteWrapper::changeset_start_invert_flag(void) {
    return SQLITE_CHANGESETSTART_INVERT;
}

int SqliteWrapper::changeset_op(Ref<Sqlite3ChangesetIterHandle> iter, String out_table, int out_col_count, int out_op, bool out_indirect) {
    ERR_FAIL_COND_V(iter.is_null() || !iter->is_valid(), -1);

    const char *tab = nullptr;
    int col = 0;
    int op = 0;
    int indirect = 0;
    int result = sqlite3changeset_op(iter->handle, &tab, &col, &op, &indirect);

    if (result == SQLITE_OK) {
        out_table = tab ? String::utf8(tab) : String();
        out_col_count = col;
        out_op = op;
        out_indirect = indirect != 0;
    }

    return result;
}

int SqliteWrapper::changeset_pk(Ref<Sqlite3ChangesetIterHandle> iter, PackedByteArray out_pk, int out_col_count) {
    ERR_FAIL_COND_V(iter.is_null() || !iter->is_valid(), -1);

    unsigned char *pk = nullptr;
    int col = 0;
    int result = sqlite3changeset_pk(iter->handle, &pk, &col);

    if (result == SQLITE_OK) {
        if (col > 0 && pk != nullptr) {
            out_pk.resize(col);
            memcpy(out_pk.ptrw(), pk, col);
        } else {
            out_pk.clear();
        }
        out_col_count = col;
    } else {
        out_pk.clear();
        out_col_count = 0;
    }

    return result;
}

int SqliteWrapper::changeset_old(Ref<Sqlite3ChangesetIterHandle> iter, int i_val, Ref<Sqlite3ValueHandle> out_value) {
    ERR_FAIL_COND_V(iter.is_null() || !iter->is_valid(), -1);
    ERR_FAIL_COND_V(out_value.is_null(), -1);

    sqlite3_value *value = nullptr;
    int result = sqlite3changeset_old(iter->handle, i_val, &value);
    if (result == SQLITE_OK) {
        out_value->handle = value;
    }
    return result;
}

int SqliteWrapper::changeset_new(Ref<Sqlite3ChangesetIterHandle> iter, int i_val, Ref<Sqlite3ValueHandle> out_value) {
    ERR_FAIL_COND_V(iter.is_null() || !iter->is_valid(), -1);
    ERR_FAIL_COND_V(out_value.is_null(), -1);

    sqlite3_value *value = nullptr;
    int result = sqlite3changeset_new(iter->handle, i_val, &value);
    if (result == SQLITE_OK) {
        out_value->handle = value;
    }
    return result;
}

int SqliteWrapper::changeset_conflict(Ref<Sqlite3ChangesetIterHandle> iter, int i_val, Ref<Sqlite3ValueHandle> out_value) {
    ERR_FAIL_COND_V(iter.is_null() || !iter->is_valid(), -1);
    ERR_FAIL_COND_V(out_value.is_null(), -1);

    sqlite3_value *value = nullptr;
    int result = sqlite3changeset_conflict(iter->handle, i_val, &value);
    if (result == SQLITE_OK) {
        out_value->handle = value;
    }
    return result;
}

Array SqliteWrapper::changeset_fk_conflicts(Ref<Sqlite3ChangesetIterHandle> iter) {
    ERR_FAIL_COND_V(iter.is_null() || !iter->is_valid(), Array());

    int count = 0;
    int result = sqlite3changeset_fk_conflicts(iter->handle, &count);
    Array result_array;
    result_array.resize(2);
    result_array[0] = result;
    result_array[1] = count;
    return result_array;
}

int SqliteWrapper::changeset_finalize(Ref<Sqlite3ChangesetIterHandle> iter) {
    ERR_FAIL_COND_V(iter.is_null() || !iter->is_valid(), -1);
    return sqlite3changeset_finalize(iter->handle);
}

Array SqliteWrapper::changeset_invert(PackedByteArray input) {
    ERR_FAIL_COND_V(input.is_empty(), Array());

    int out_size = 0;
    void *out_ptr = nullptr;
    int result = sqlite3changeset_invert(input.size(), input.ptr(), &out_size, &out_ptr);

    Array result_array;
    result_array.resize(2);
    result_array[0] = result;

    if (result == SQLITE_OK && out_ptr != nullptr) {
        PackedByteArray output;
        output.resize(out_size);
        memcpy(output.ptrw(), out_ptr, out_size);
        sqlite3_free(out_ptr);
        result_array[1] = output;
    } else {
        result_array[1] = PackedByteArray();
    }
    return result_array;
}

int SqliteWrapper::changegroup_schema(Ref<Sqlite3ChangegroupHandle> changegroup, Ref<Sqlite3Handle> db, String db_name) {
    ERR_FAIL_COND_V(changegroup.is_null() || !changegroup->is_valid(), -1);
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);

    return sqlite3changegroup_schema(changegroup->handle, db->handle, db_name.utf8().get_data());
}

int SqliteWrapper::changegroup_add(Ref<Sqlite3ChangegroupHandle> changegroup, PackedByteArray input) {
    ERR_FAIL_COND_V(changegroup.is_null() || !changegroup->is_valid(), -1);

    return sqlite3changegroup_add(
        changegroup->handle,
        input.size(),
        const_cast<void*>(static_cast<const void*>(input.ptr()))
    );
}

int SqliteWrapper::changegroup_add_change(Ref<Sqlite3ChangegroupHandle> changegroup, Ref<Sqlite3ChangesetIterHandle> iter) {
    ERR_FAIL_COND_V(changegroup.is_null() || !changegroup->is_valid(), -1);
    ERR_FAIL_COND_V(iter.is_null() || !iter->is_valid(), -1);

    return sqlite3changegroup_add_change(changegroup->handle, iter->handle);
}

Array SqliteWrapper::changegroup_output(Ref<Sqlite3ChangegroupHandle> changegroup) {
    ERR_FAIL_COND_V(changegroup.is_null() || !changegroup->is_valid(), Array());

    int data_size = 0;
    void *data_ptr = nullptr;
    int result = sqlite3changegroup_output(changegroup->handle, &data_size, &data_ptr);

    Array result_array;
    result_array.resize(2);
    result_array[0] = result;

    if (result == SQLITE_OK && data_ptr != nullptr) {
        PackedByteArray output;
        output.resize(data_size);
        memcpy(output.ptrw(), data_ptr, data_size);
        sqlite3_free(data_ptr);
        result_array[1] = output;
    } else {
        result_array[1] = PackedByteArray();
    }
    return result_array;
}

int SqliteWrapper::changeset_apply(Ref<Sqlite3Handle> db, PackedByteArray changeset, Callable filter_callback, Callable conflict_callback) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    ERR_FAIL_COND_V(!conflict_callback.is_valid(), -1);

    // Filter callback trampoline
    auto filter_tramp = [](void *pCtx, const char *zTab) -> int {
        if (!zTab) return 0;
        Callable cb = *reinterpret_cast<Callable*>(pCtx);
        if (!cb.is_valid()) return 0;
        
        Array args;
        args.push_back(String::utf8(zTab));
        Variant ret = cb.callv(args);
        if (ret.get_type() != Variant::INT) {
            return 0;
        }
        return int(ret);
    };

    // Conflict callback trampoline
    auto conflict_tramp = [](void *pCtx, int eConflict, sqlite3_changeset_iter *pIter) -> int {
        if (!pIter) return SQLITE_CHANGESET_OMIT;
        
        Callable cb = *reinterpret_cast<Callable*>(pCtx);
        if (!cb.is_valid()) return SQLITE_CHANGESET_OMIT;
        
        // Create iterator handle
        Ref<Sqlite3ChangesetIterHandle> iter_handle;
        iter_handle.instantiate();
        iter_handle->handle = pIter;
        
        Array args;
        args.push_back(eConflict);
        args.push_back(iter_handle);
        
        Variant ret = cb.callv(args);
        if (ret.get_type() != Variant::INT) {
            return SQLITE_CHANGESET_OMIT;
        }
        return int(ret);
    };

    // Context for callbacks
    Callable filter_ctx = filter_callback.is_valid() ? filter_callback : Callable();
    Callable conflict_ctx = conflict_callback;

    int (*filter_fn)(void*, const char*) = filter_callback.is_valid() ? +filter_tramp : nullptr;
    return sqlite3changeset_apply(
        db->handle,
        changeset.size(),
        const_cast<void*>(static_cast<const void*>(changeset.ptr())),
        filter_fn,
        conflict_tramp,
        filter_callback.is_valid() ? &filter_ctx : &conflict_ctx
    );
}

int SqliteWrapper::changeset_apply_v2(Ref<Sqlite3Handle> db, PackedByteArray changeset, Callable filter_callback, Callable conflict_callback, PackedByteArray rebase_data, int flags) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    ERR_FAIL_COND_V(!conflict_callback.is_valid(), -1);

    // Filter callback trampoline
    auto filter_tramp = [](void *pCtx, const char *zTab) -> int {
        if (!zTab) return 0;
        Callable cb = *reinterpret_cast<Callable*>(pCtx);
        if (!cb.is_valid()) return 0;
        
        Array args;
        args.push_back(String::utf8(zTab));
        Variant ret = cb.callv(args);
        if (ret.get_type() != Variant::INT) {
            return 0;
        }
        return int(ret);
    };

    // Conflict callback trampoline
    auto conflict_tramp = [](void *pCtx, int eConflict, sqlite3_changeset_iter *pIter) -> int {
        if (!pIter) return SQLITE_CHANGESET_OMIT;
        
        Callable cb = *reinterpret_cast<Callable*>(pCtx);
        if (!cb.is_valid()) return SQLITE_CHANGESET_OMIT;
        
        // Create iterator handle
        Ref<Sqlite3ChangesetIterHandle> iter_handle;
        iter_handle.instantiate();
        iter_handle->handle = pIter;
        
        Array args;
        args.push_back(eConflict);
        args.push_back(iter_handle);
        
        Variant ret = cb.callv(args);
        if (ret.get_type() != Variant::INT) {
            return SQLITE_CHANGESET_OMIT;
        }
        return int(ret);
    };

    // Context for callbacks
    Callable filter_ctx = filter_callback.is_valid() ? filter_callback : Callable();
    Callable conflict_ctx = conflict_callback;

    void *rebase_ptr = nullptr;
    int rebase_size = 0;

    int (*filter_fn)(void*, const char*) = filter_callback.is_valid() ? +filter_tramp : nullptr;
    int result = sqlite3changeset_apply_v2(
        db->handle,
        changeset.size(),
        const_cast<void*>(static_cast<const void*>(changeset.ptr())),
        filter_fn,
        conflict_tramp,
        filter_callback.is_valid() ? &filter_ctx : &conflict_ctx,
        &rebase_ptr,
        &rebase_size,
        flags
    );

    // Handle rebase output
    if (result == SQLITE_OK && rebase_ptr != nullptr && rebase_size > 0) {
        PackedByteArray rebase_data_array;
        rebase_data_array.resize(rebase_size);
        memcpy(rebase_data_array.ptrw(), rebase_ptr, rebase_size);
        rebase_data = rebase_data_array;
        sqlite3_free(rebase_ptr);
    } else if (rebase_ptr != nullptr) {
        sqlite3_free(rebase_ptr);
    }

    return result;
}

int SqliteWrapper::changeset_apply_v3(Ref<Sqlite3Handle> db, PackedByteArray changeset, Callable filter_callback, Callable conflict_callback, PackedByteArray rebase_data, int flags) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    ERR_FAIL_COND_V(!conflict_callback.is_valid(), -1);

    // Filter callback trampoline - now receives iterator handle instead of table name
    auto filter_tramp = [](void *pCtx, sqlite3_changeset_iter *pIter) -> int {
        if (!pIter) return 0;
        
        Callable cb = *reinterpret_cast<Callable*>(pCtx);
        if (!cb.is_valid()) return 0;
        
        // Create iterator handle
        Ref<Sqlite3ChangesetIterHandle> iter_handle;
        iter_handle.instantiate();
        iter_handle->handle = pIter;
        
        Array args;
        args.push_back(iter_handle);
        
        Variant ret = cb.callv(args);
        if (ret.get_type() != Variant::INT) {
            return 0;
        }
        return int(ret);
    };

    // Conflict callback trampoline
    auto conflict_tramp = [](void *pCtx, int eConflict, sqlite3_changeset_iter *pIter) -> int {
        if (!pIter) return SQLITE_CHANGESET_OMIT;
        
        Callable cb = *reinterpret_cast<Callable*>(pCtx);
        if (!cb.is_valid()) return SQLITE_CHANGESET_OMIT;
        
        // Create iterator handle
        Ref<Sqlite3ChangesetIterHandle> iter_handle;
        iter_handle.instantiate();
        iter_handle->handle = pIter;
        
        Array args;
        args.push_back(eConflict);
        args.push_back(iter_handle);
        
        Variant ret = cb.callv(args);
        if (ret.get_type() != Variant::INT) {
            return SQLITE_CHANGESET_OMIT;
        }
        return int(ret);
    };

    // Context for callbacks
    Callable filter_ctx = filter_callback.is_valid() ? filter_callback : Callable();
    Callable conflict_ctx = conflict_callback;

    void *rebase_ptr = nullptr;
    int rebase_size = 0;

    int (*filter_fn)(void*, sqlite3_changeset_iter*) = filter_callback.is_valid() ? +filter_tramp : nullptr;
    int result = sqlite3changeset_apply_v3(
        db->handle,
        changeset.size(),
        const_cast<void*>(static_cast<const void*>(changeset.ptr())),
        filter_fn,
        conflict_tramp,
        filter_callback.is_valid() ? &filter_ctx : &conflict_ctx,
        &rebase_ptr,
        &rebase_size,
        flags
    );

    // Handle rebase output
    if (result == SQLITE_OK && rebase_ptr != nullptr && rebase_size > 0) {
        PackedByteArray rebase_data_array;
        rebase_data_array.resize(rebase_size);
        memcpy(rebase_data_array.ptrw(), rebase_ptr, rebase_size);
        rebase_data = rebase_data_array;
        sqlite3_free(rebase_ptr);
    } else if (rebase_ptr != nullptr) {
        sqlite3_free(rebase_ptr);
    }

    return result;
}

int SqliteWrapper::changeset_apply_flag_no_savepoint(void) {
    return SQLITE_CHANGESETAPPLY_NOSAVEPOINT;
}

int SqliteWrapper::changeset_apply_flag_invert(void) {
    return SQLITE_CHANGESETAPPLY_INVERT;
}

int SqliteWrapper::changeset_apply_flag_ignore_noop(void) {
    return SQLITE_CHANGESETAPPLY_IGNORENOOP;
}

int SqliteWrapper::changeset_apply_flag_fk_no_action(void) {
    return SQLITE_CHANGESETAPPLY_FKNOACTION;
}

int SqliteWrapper::changeset_conflict_type_data(void) {
    return SQLITE_CHANGESET_DATA;
}

int SqliteWrapper::changeset_conflict_type_not_found(void) {
    return SQLITE_CHANGESET_NOTFOUND;
}

int SqliteWrapper::changeset_conflict_type_conflict(void) {
    return SQLITE_CHANGESET_CONFLICT;
}

int SqliteWrapper::changeset_conflict_type_constraint(void) {
    return SQLITE_CHANGESET_CONSTRAINT;
}

int SqliteWrapper::changeset_conflict_type_foreign_key(void) {
    return SQLITE_CHANGESET_FOREIGN_KEY;
}

int SqliteWrapper::changeset_conflict_result_omit(void) {
    return SQLITE_CHANGESET_OMIT;
}

int SqliteWrapper::changeset_conflict_result_replace(void) {
    return SQLITE_CHANGESET_REPLACE;
}

int SqliteWrapper::changeset_conflict_result_abort(void) {
    return SQLITE_CHANGESET_ABORT;
}

PackedByteArray SqliteWrapper::rebaser_rebase(Ref<Sqlite3RebaserHandle> rebaser, PackedByteArray changeset) {
    ERR_FAIL_COND_V(rebaser.is_null() || !rebaser->is_valid(), PackedByteArray());

    void *rebased_ptr = nullptr;
    int rebased_size = 0;

    int result = sqlite3rebaser_rebase(rebaser->handle, changeset.size(), changeset.ptr(), &rebased_size, &rebased_ptr);

    PackedByteArray result_array;
    if (result == SQLITE_OK && rebased_ptr != nullptr && rebased_size > 0) {
        result_array.resize(rebased_size);
        memcpy(result_array.ptrw(), rebased_ptr, rebased_size);
        sqlite3_free(rebased_ptr);
    } else if (rebased_ptr != nullptr) {
        sqlite3_free(rebased_ptr);
    }

    return result_array;
}

PackedByteArray SqliteWrapper::changegroup_output_stream(Ref<Sqlite3ChangegroupHandle> changegroup) {
    // Output callback trampoline - collect all data
    auto output_tramp = [](void *pOut, const void *pData, int nData) -> int {
        PackedByteArray *array = reinterpret_cast<PackedByteArray*>(pOut);
        int old_size = array->size();
        array->resize(old_size + nData);
        memcpy(array->ptrw() + old_size, pData, nData);
        return SQLITE_OK;
    };

    ERR_FAIL_COND_V(changegroup.is_null() || !changegroup->is_valid(), PackedByteArray());

    PackedByteArray output_array;

    int result = sqlite3changegroup_output_strm(
        changegroup->handle,
        output_tramp,
        &output_array
    );

    if (result != SQLITE_OK) {
        return PackedByteArray();
    }

    return output_array;
}

int SqliteWrapper::changeset_apply_stream(Ref<Sqlite3Handle> db, PackedByteArray changeset, Callable filter_callback, Callable conflict_callback) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    ERR_FAIL_COND_V(!conflict_callback.is_valid(), -1);

    // Input callback trampoline
    auto input_tramp = [](void *pIn, void *pData, int *pnData) -> int {
        PackedByteArray *array = reinterpret_cast<PackedByteArray*>(pIn);
        int remaining = array->size();
        int to_copy = *pnData;
        
        if (remaining <= 0) {
            *pnData = 0;
            return SQLITE_OK;
        }
        
        if (to_copy > remaining) {
            to_copy = remaining;
        }
        
        memcpy(pData, array->ptr(), to_copy);
        *pnData = to_copy;
        
        return SQLITE_OK;
    };

    // Filter callback trampoline
    auto filter_tramp = [](void *pCtx, const char *zTab) -> int {
        if (!zTab) return 0;
        Callable cb = *reinterpret_cast<Callable*>(pCtx);
        if (!cb.is_valid()) return 0;
        
        Array args;
        args.push_back(String::utf8(zTab));
        Variant ret = cb.callv(args);
        if (ret.get_type() != Variant::INT) {
            return 0;
        }
        return int(ret);
    };

    // Conflict callback trampoline
    auto conflict_tramp = [](void *pCtx, int eConflict, sqlite3_changeset_iter *pIter) -> int {
        if (!pIter) return SQLITE_CHANGESET_OMIT;
        
        Callable cb = *reinterpret_cast<Callable*>(pCtx);
        if (!cb.is_valid()) return SQLITE_CHANGESET_OMIT;
        
        // Create iterator handle
        Ref<Sqlite3ChangesetIterHandle> iter_handle;
        iter_handle.instantiate();
        iter_handle->handle = pIter;
        
        Array args;
        args.push_back(eConflict);
        args.push_back(iter_handle);
        
        Variant ret = cb.callv(args);
        if (ret.get_type() != Variant::INT) {
            return SQLITE_CHANGESET_OMIT;
        }
        return int(ret);
    };

    Callable filter_ctx = filter_callback.is_valid() ? filter_callback : Callable();
    Callable conflict_ctx = conflict_callback;

    int (*filter_fn)(void*, const char*) = filter_callback.is_valid() ? +filter_tramp : nullptr;
    return sqlite3changeset_apply_strm(
        db->handle,
        input_tramp,
        &changeset,
        filter_fn,
        conflict_tramp,
        filter_callback.is_valid() ? &filter_ctx : &conflict_ctx
    );
}

int SqliteWrapper::changeset_apply_v2_stream(Ref<Sqlite3Handle> db, PackedByteArray changeset, Callable filter_callback, Callable conflict_callback, PackedByteArray rebase_data, int flags) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    ERR_FAIL_COND_V(!conflict_callback.is_valid(), -1);

    // Input callback trampoline
    auto input_tramp = [](void *pIn, void *pData, int *pnData) -> int {
        PackedByteArray *array = reinterpret_cast<PackedByteArray*>(pIn);
        int remaining = array->size();
        int to_copy = *pnData;
        
        if (remaining <= 0) {
            *pnData = 0;
            return SQLITE_OK;
        }
        
        if (to_copy > remaining) {
            to_copy = remaining;
        }
        
        memcpy(pData, array->ptr(), to_copy);
        *pnData = to_copy;
        
        return SQLITE_OK;
    };

    // Filter callback trampoline
    auto filter_tramp = [](void *pCtx, const char *zTab) -> int {
        if (!zTab) return 0;
        Callable cb = *reinterpret_cast<Callable*>(pCtx);
        if (!cb.is_valid()) return 0;
        
        Array args;
        args.push_back(String::utf8(zTab));
        Variant ret = cb.callv(args);
        if (ret.get_type() != Variant::INT) {
            return 0;
        }
        return int(ret);
    };

    // Conflict callback trampoline
    auto conflict_tramp = [](void *pCtx, int eConflict, sqlite3_changeset_iter *pIter) -> int {
        if (!pIter) return SQLITE_CHANGESET_OMIT;
        
        Callable cb = *reinterpret_cast<Callable*>(pCtx);
        if (!cb.is_valid()) return SQLITE_CHANGESET_OMIT;
        
        // Create iterator handle
        Ref<Sqlite3ChangesetIterHandle> iter_handle;
        iter_handle.instantiate();
        iter_handle->handle = pIter;
        
        Array args;
        args.push_back(eConflict);
        args.push_back(iter_handle);
        
        Variant ret = cb.callv(args);
        if (ret.get_type() != Variant::INT) {
            return SQLITE_CHANGESET_OMIT;
        }
        return int(ret);
    };

    Callable filter_ctx = filter_callback.is_valid() ? filter_callback : Callable();
    Callable conflict_ctx = conflict_callback;

    void *rebase_ptr = nullptr;
    int rebase_size = 0;

    int (*filter_fn)(void*, const char*) = filter_callback.is_valid() ? +filter_tramp : nullptr;
    int result = sqlite3changeset_apply_v2_strm(
        db->handle,
        input_tramp,
        &changeset,
        filter_fn,
        conflict_tramp,
        filter_callback.is_valid() ? &filter_ctx : &conflict_ctx,
        &rebase_ptr,
        &rebase_size,
        flags
    );

    // Handle rebase output
    if (result == SQLITE_OK && rebase_ptr != nullptr && rebase_size > 0) {
        PackedByteArray rebase_data_array;
        rebase_data_array.resize(rebase_size);
        memcpy(rebase_data_array.ptrw(), rebase_ptr, rebase_size);
        rebase_data = rebase_data_array;
        sqlite3_free(rebase_ptr);
    } else if (rebase_ptr != nullptr) {
        sqlite3_free(rebase_ptr);
    }

    return result;
}

int SqliteWrapper::changeset_apply_v3_stream(Ref<Sqlite3Handle> db, PackedByteArray changeset, Callable filter_callback, Callable conflict_callback, PackedByteArray rebase_data, int flags) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    ERR_FAIL_COND_V(!conflict_callback.is_valid(), -1);

    // Input callback trampoline
    auto input_tramp = [](void *pIn, void *pData, int *pnData) -> int {
        PackedByteArray *array = reinterpret_cast<PackedByteArray*>(pIn);
        int remaining = array->size();
        int to_copy = *pnData;
        
        if (remaining <= 0) {
            *pnData = 0;
            return SQLITE_OK;
        }
        
        if (to_copy > remaining) {
            to_copy = remaining;
        }
        
        memcpy(pData, array->ptr(), to_copy);
        *pnData = to_copy;
        
        return SQLITE_OK;
    };

    // Filter callback trampoline - receives iterator handle instead of table name
    auto filter_tramp = [](void *pCtx, sqlite3_changeset_iter *pIter) -> int {
        if (!pIter) return 0;
        
        Callable cb = *reinterpret_cast<Callable*>(pCtx);
        if (!cb.is_valid()) return 0;
        
        // Create iterator handle
        Ref<Sqlite3ChangesetIterHandle> iter_handle;
        iter_handle.instantiate();
        iter_handle->handle = pIter;
        
        Array args;
        args.push_back(iter_handle);
        
        Variant ret = cb.callv(args);
        if (ret.get_type() != Variant::INT) {
            return 0;
        }
        return int(ret);
    };

    // Conflict callback trampoline
    auto conflict_tramp = [](void *pCtx, int eConflict, sqlite3_changeset_iter *pIter) -> int {
        if (!pIter) return SQLITE_CHANGESET_OMIT;
        
        Callable cb = *reinterpret_cast<Callable*>(pCtx);
        if (!cb.is_valid()) return SQLITE_CHANGESET_OMIT;
        
        // Create iterator handle
        Ref<Sqlite3ChangesetIterHandle> iter_handle;
        iter_handle.instantiate();
        iter_handle->handle = pIter;
        
        Array args;
        args.push_back(eConflict);
        args.push_back(iter_handle);
        
        Variant ret = cb.callv(args);
        if (ret.get_type() != Variant::INT) {
            return SQLITE_CHANGESET_OMIT;
        }
        return int(ret);
    };

    Callable filter_ctx = filter_callback.is_valid() ? filter_callback : Callable();
    Callable conflict_ctx = conflict_callback;

    void *rebase_ptr = nullptr;
    int rebase_size = 0;

    int (*filter_fn)(void*, sqlite3_changeset_iter*) = filter_callback.is_valid() ? +filter_tramp : nullptr;
    int result = sqlite3changeset_apply_v3_strm(
        db->handle,
        input_tramp,
        &changeset,
        filter_fn,
        conflict_tramp,
        filter_callback.is_valid() ? &filter_ctx : &conflict_ctx,
        &rebase_ptr,
        &rebase_size,
        flags
    );

    // Handle rebase output
    if (result == SQLITE_OK && rebase_ptr != nullptr && rebase_size > 0) {
        PackedByteArray rebase_data_array;
        rebase_data_array.resize(rebase_size);
        memcpy(rebase_data_array.ptrw(), rebase_ptr, rebase_size);
        rebase_data = rebase_data_array;
        sqlite3_free(rebase_ptr);
    } else if (rebase_ptr != nullptr) {
        sqlite3_free(rebase_ptr);
    }

    return result;
}

PackedByteArray SqliteWrapper::changeset_invert_stream(PackedByteArray changeset) {
    // Input callback trampoline
    auto input_tramp = [](void *pIn, void *pData, int *pnData) -> int {
        PackedByteArray *array = reinterpret_cast<PackedByteArray*>(pIn);
        int remaining = array->size();
        int to_copy = *pnData;
        
        if (remaining <= 0) {
            *pnData = 0;
            return SQLITE_OK;
        }
        
        if (to_copy > remaining) {
            to_copy = remaining;
        }
        
        memcpy(pData, array->ptr(), to_copy);
        *pnData = to_copy;
        
        return SQLITE_OK;
    };

    // Output callback trampoline - collect all data
    auto output_tramp = [](void *pOut, const void *pData, int nData) -> int {
        PackedByteArray *array = reinterpret_cast<PackedByteArray*>(pOut);
        int old_size = array->size();
        array->resize(old_size + nData);
        memcpy(array->ptrw() + old_size, pData, nData);
        return SQLITE_OK;
    };

    // Prepare output array
    PackedByteArray output_array;

    int result = sqlite3changeset_invert_strm(
        input_tramp,
        &changeset,
        output_tramp,
        &output_array
    );

    if (result != SQLITE_OK) {
        return PackedByteArray();
    }

    return output_array;
}

Ref<Sqlite3ChangesetIterHandle> SqliteWrapper::changeset_start_stream(PackedByteArray changeset) {
    // Input callback trampoline
    auto input_tramp = [](void *pIn, void *pData, int *pnData) -> int {
        PackedByteArray *array = reinterpret_cast<PackedByteArray*>(pIn);
        int remaining = array->size();
        int to_copy = *pnData;
        
        if (remaining <= 0) {
            *pnData = 0;
            return SQLITE_OK;
        }
        
        if (to_copy > remaining) {
            to_copy = remaining;
        }
        
        memcpy(pData, array->ptr(), to_copy);
        *pnData = to_copy;
        
        return SQLITE_OK;
    };

    sqlite3_changeset_iter *iter = nullptr;
    int result = sqlite3changeset_start_strm(
        &iter,
        input_tramp,
        &changeset
    );

    if (result != SQLITE_OK || iter == nullptr) {
        return Ref<Sqlite3ChangesetIterHandle>();
    }

    Ref<Sqlite3ChangesetIterHandle> ref;
    ref.instantiate();
    ref->set_handle(reinterpret_cast<intptr_t>(iter));
    return ref;
}

int SqliteWrapper::session_config_stream_size(int new_size) {
    int size = new_size;
    int result = sqlite3session_config(SQLITE_SESSION_CONFIG_STRMSIZE, &size);
    if (result == SQLITE_OK) {
        return size;
    } else {
        return result; // Return the SQLite error code on failure
    }
}

PackedByteArray SqliteWrapper::rebaser_rebase_stream(Ref<Sqlite3RebaserHandle> rebaser, PackedByteArray input_data) {
    // Input callback trampoline - provide data from a PackedByteArray
    struct _InputCtx {
        const uint8_t *data;
        int total_size;
        int position;
    };

    auto input_tramp = [](void *pIn, void *pData, int *pnData) -> int {
        _InputCtx *ctx = reinterpret_cast<_InputCtx*>(pIn);
        int remaining = ctx->total_size - ctx->position;
        int to_copy = *pnData;
        
        if (to_copy > remaining) {
            to_copy = remaining;
        }
        
        if (to_copy > 0) {
            memcpy(pData, ctx->data + ctx->position, to_copy);
            ctx->position += to_copy;
        }
        
        *pnData = to_copy;
        
        if (to_copy == 0 && ctx->position >= ctx->total_size) {
            // No more data
            return SQLITE_OK;
        }
        
        return SQLITE_OK;
    };

    // Output callback trampoline - collect all data
    auto output_tramp = [](void *pOut, const void *pData, int nData) -> int {
        PackedByteArray *array = reinterpret_cast<PackedByteArray*>(pOut);
        int old_size = array->size();
        array->resize(old_size + nData);
        memcpy(array->ptrw() + old_size, pData, nData);
        return SQLITE_OK;
    };

    ERR_FAIL_COND_V(rebaser.is_null() || !rebaser->is_valid(), PackedByteArray());

    if (input_data.is_empty()) {
        return PackedByteArray(); // Nothing to rebase
    }

    PackedByteArray output_array;

    _InputCtx input_ctx;
    input_ctx.data = input_data.ptr();
    input_ctx.total_size = input_data.size();
    input_ctx.position = 0;

    int result = sqlite3rebaser_rebase_strm(
        rebaser->handle,
        input_tramp,
        &input_ctx,
        output_tramp,
        &output_array
    );

    if (result != SQLITE_OK) {
        return PackedByteArray();
    }

    return output_array;
}

int SqliteWrapper::fts5_tokenize_query(void) {
    return FTS5_TOKENIZE_QUERY;
}

int SqliteWrapper::fts5_tokenize_prefix(void) {
    return FTS5_TOKENIZE_PREFIX;
}

int SqliteWrapper::fts5_tokenize_document(void) {
    return FTS5_TOKENIZE_DOCUMENT;
}

int SqliteWrapper::fts5_tokenize_aux(void) {
    return FTS5_TOKENIZE_AUX;
}

int SqliteWrapper::fts5_token_colocated(void) {
    return FTS5_TOKEN_COLOCATED;
}

int SqliteWrapper::create_module_v2(Ref<Sqlite3Handle> db, String name, Ref<Sqlite3ModuleHandle> module, uint64_t client_data, Callable destructor) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    ERR_FAIL_COND_V(module.is_null() || !module->is_valid(), -1);

    struct _DestroyCtx {
        Callable cb;
    };

    static auto trampoline = [](void* ud) {
        _DestroyCtx* ctx = (_DestroyCtx*)ud;
        ctx->cb.callv(Array());
    };

    _DestroyCtx* ctx = new _DestroyCtx{destructor};
    int result = sqlite3_create_module_v2(
        db->handle,
        name.utf8().get_data(),
        module->handle,
        reinterpret_cast<void*>(client_data),
        trampoline
    );

    if (result != SQLITE_OK) {
        delete ctx;
    }

    return result;
}

int SqliteWrapper::unlock_notify(Ref<Sqlite3Handle> db, Callable on_notify, Variant user_data) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);
    ERR_FAIL_COND_V(!on_notify.is_valid(), -1);

    struct _UnlockNotifyCtx {
        Callable cb;
        Variant ud;
    } ctx{on_notify, user_data};

    auto trampoline = [](void **apArg, int nArg) {
        if (nArg < 1 || apArg[0] == nullptr) return;
        _UnlockNotifyCtx *ctx = reinterpret_cast<_UnlockNotifyCtx *>(apArg[0]);
        Array args;
        args.push_back(ctx->ud);
        ctx->cb.callv(args);
    };

    return sqlite3_unlock_notify(db->handle, trampoline, &ctx);
}

int SqliteWrapper::declare_vtab(Ref<Sqlite3Handle> db, String sql) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);

    int result = sqlite3_declare_vtab(db->handle, sql.utf8().get_data());

    return result;
}

int SqliteWrapper::drop_modules(Ref<Sqlite3Handle> db, PackedStringArray keep) {
    ERR_FAIL_COND_V(db.is_null() || !db->is_valid(), -1);

    const char** keep_array = nullptr;
    Vector<CharString> char_strings;
    Vector<char*> keep_cstrs;

    if (keep.size() > 0) {
        int count = keep.size();
        char_strings.resize(count);
        
        for (int i = 0; i < count; i++) {
            char_strings.write[i] = keep[i].utf8();
        }
        
        keep_cstrs.resize(count + 1);
        
        for (int i = 0; i < count; i++) {
            keep_cstrs.write[i] = (char*)char_strings[i].get_data();
        }
        keep_cstrs.write[count] = nullptr;
        
        keep_array = (const char**)keep_cstrs.ptr();
    }

    int result = sqlite3_drop_modules(db->handle, keep_array);

    return result;
}

int SqliteWrapper::vtab_distinct(Ref<Sqlite3IndexInfoHandle> info) {
    ERR_FAIL_COND_V(info.is_null() || !info->is_valid(), -1);
    return sqlite3_vtab_distinct(info->handle);
}

int SqliteWrapper::conflict_rollback(void) {
    return SQLITE_ROLLBACK;
}

int SqliteWrapper::conflict_ignore(void) {
    return SQLITE_IGNORE;
}

int SqliteWrapper::conflict_fail(void) {
    return SQLITE_FAIL;
}

int SqliteWrapper::conflict_replace(void) {
    return SQLITE_REPLACE;
}

int SqliteWrapper::stmt_scanstat_nloop(void) {
    return SQLITE_SCANSTAT_NLOOP;
}

int SqliteWrapper::stmt_scanstat_nvisit(void) {
    return SQLITE_SCANSTAT_NVISIT;
}

int SqliteWrapper::stmt_scanstat_est(void) {
    return SQLITE_SCANSTAT_EST;
}

int SqliteWrapper::stmt_scanstat_name(void) {
    return SQLITE_SCANSTAT_NAME;
}

int SqliteWrapper::stmt_scanstat_explain(void) {
    return SQLITE_SCANSTAT_EXPLAIN;
}

int SqliteWrapper::stmt_scanstat_selectid(void) {
    return SQLITE_SCANSTAT_SELECTID;
}

int SqliteWrapper::stmt_scanstat_parentid(void) {
    return SQLITE_SCANSTAT_PARENTID;
}

int SqliteWrapper::stmt_scanstat_ncycle(void) {
    return SQLITE_SCANSTAT_NCYCLE;
}

int SqliteWrapper::vtab_in(Ref<Sqlite3IndexInfoHandle> info, int iCons, int bHandle) {
    ERR_FAIL_COND_V(info.is_null() || !info->is_valid(), 0);
    return sqlite3_vtab_in(info->handle, iCons, bHandle);
}

int SqliteWrapper::vtab_in_first(Ref<Sqlite3ValueHandle> pVal, Ref<Sqlite3ValueHandle> out_value) {
    ERR_FAIL_COND_V(pVal.is_null() || !pVal->is_valid(), SQLITE_MISUSE);
    ERR_FAIL_COND_V(out_value.is_null(), SQLITE_MISUSE);

    sqlite3_value* out_ptr = nullptr;
    int result = sqlite3_vtab_in_first(pVal->handle, &out_ptr);
    out_value->handle = out_ptr;
    return result;
}
