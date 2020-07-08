#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace mumlib {

    using namespace std;

    class Callback {
    public:
        virtual void version(
                uint16_t major,
                uint8_t minor,
                uint8_t patch,
                string release,
                string os,
                string os_version) {
			(void) major;
			(void) minor;
			(void) patch;
			(void) release;
			(void) os;
			(void) os_version;
		};

        virtual void audio(
                int target,
                int sessionId,
                int sequenceNumber,
                int16_t *pcm_data,
                uint32_t pcm_data_size) {
			(void) target;
			(void) sessionId;
			(void) sequenceNumber;
			(void) pcm_data;
			(void) pcm_data_size;
		};

        virtual void unsupportedAudio(
                int target,
                int sessionId,
                int sequenceNumber,
                uint8_t *encoded_audio_data,
                uint32_t encoded_audio_data_size) {
			(void) target;
			(void) sessionId;
			(void) sequenceNumber;
			(void) encoded_audio_data;
			(void) encoded_audio_data_size;
		};

        virtual void serverSync(
                string welcome_text,
                int32_t session,
                int32_t max_bandwidth,
                int64_t permissions) {
			(void) welcome_text;
			(void) session;
			(void) max_bandwidth;
			(void) permissions;
		};

        virtual void channelRemove(uint32_t channel_id) {
			(void) channel_id;
		};

        virtual void channelState(
                string name,
                int32_t channel_id,
                int32_t parent,
                string description,
                vector<uint32_t> links,
                vector<uint32_t> inks_add,
                vector<uint32_t> links_remove,
                bool temporary,
                int32_t position) {
			(void) name;
			(void) channel_id;
			(void) parent;
			(void) description;
			(void) links;
			(void) inks_add;
			(void) links_remove;
			(void) temporary;
			(void) position;
		};

        virtual void userRemove(
                uint32_t session,
                int32_t actor,
                string reason,
                bool ban) {
			(void) session;
			(void) actor;
			(void) reason;
			(void) ban;
		};

        virtual void userState(
                int32_t session,
                int32_t actor,
                string name,
                int32_t user_id,
                int32_t channel_id,
                int32_t mute,
                int32_t deaf,
                int32_t suppress,
                int32_t self_mute,
                int32_t self_deaf,
                string comment,
                int32_t priority_speaker,
                int32_t recording) {
			(void) session;
			(void) actor;
			(void) name;
			(void) user_id;
			(void) channel_id;
			(void) mute;
			(void) deaf;
			(void) suppress;
			(void) self_mute;
			(void) self_deaf;
			(void) comment;
			(void) priority_speaker;
			(void) recording;
		};

        virtual void banList(
                const uint8_t *ip_data,
                uint32_t ip_data_size,
                uint32_t mask,
                string name,
                string hash,
                string reason,
                string start,
                int32_t duration) {
			(void) ip_data;
			(void) ip_data_size;
			(void) mask;
			(void) name;
			(void) hash;
			(void) reason;
			(void) start;
			(void) duration;
		};

        virtual void textMessage(
                uint32_t actor,
                std::vector<uint32_t> session,
                std::vector<uint32_t> channel_id,
                std::vector<uint32_t> tree_id,
                string message) {
			(void) actor;
			(void) session;
			(void) channel_id;
			(void) tree_id;
			(void) message;
		};

        virtual void permissionDenied(
                int32_t permission,
                int32_t channel_id,
                int32_t session,
                string reason,
                int32_t deny_type,
                string name) {
			(void) permission;
			(void) channel_id;
			(void) session;
			(void) reason;
			(void) deny_type;
			(void) name;
		};

        virtual void queryUsers(
                uint32_t n_ids,
                uint32_t *ids,
                uint32_t n_names,
                string *names) {
			(void) n_ids;
			(void) ids;
			(void) n_names;
			(void) names;
		};

        virtual void contextActionModify(
                string action,
                string text,
                uint32_t m_context,
                uint32_t operation) {
			(void) action;
			(void) text;
			(void) m_context;
			(void) operation;
		};

        virtual void contextAction(
                int32_t session,
                int32_t channel_id,
                string action) {
			(void) session;
			(void) channel_id;
			(void) action;
		};

        virtual void userList(
                uint32_t user_id,
                string name,
                string last_seen,
                int32_t last_channel) {
			(void) user_id;
			(void) name;
			(void) last_seen;
			(void) last_channel;
		};

        virtual void permissionQuery(
                int32_t channel_id,
                uint32_t permissions,
                int32_t flush) {
			(void) channel_id;
			(void) permissions;
			(void) flush;
		};

        virtual void codecVersion(
                int32_t alpha,
                int32_t beta,
                uint32_t prefer_alpha,
                int32_t opus) {
			(void) alpha;
			(void) beta;
			(void) prefer_alpha;
			(void) opus;
		};

        virtual void serverConfig(
                uint32_t max_bandwidth,
                string welcome_text,
                uint32_t allow_html,
                uint32_t message_length,
                uint32_t image_message_length) {
			(void) max_bandwidth;
			(void) welcome_text;
			(void) allow_html;
			(void) message_length;
			(void) image_message_length;
		};

        virtual void suggestConfig(
                uint32_t version,
                uint32_t positional,
                uint32_t push_to_talk) {
			(void) version;
			(void) positional;
			(void) push_to_talk;
		};

    };

    class _BasicCallback_Private;

    class BasicCallback : public Callback {
    public:
        BasicCallback();

        ~BasicCallback();

        void version(
                uint16_t major,
                uint8_t minor,
                uint8_t patch,
                string release,
                string os,
                string os_version) override;

        void audio(
                int target,
                int sessionId,
                int sequenceNumber,
                int16_t *pcm_data,
                uint32_t pcm_data_size) override;

        void unsupportedAudio(
                int target,
                int sessionId,
                int sequenceNumber,
                uint8_t *encoded_audio_data,
                uint32_t encoded_audio_data_size) override;

        void serverSync(
                string welcome_text,
                int32_t session,
                int32_t max_bandwidth,
                int64_t permissions) override;

        void channelRemove(uint32_t channel_id) override;

        void channelState(
                string name,
                int32_t channel_id,
                int32_t parent,
                string description,
                vector<uint32_t> links,
                vector<uint32_t> inks_add,
                vector<uint32_t> links_remove,
                bool temporary,
                int32_t position) override;

        void userRemove(
                uint32_t session,
                int32_t actor,
                string reason,
                bool ban) override;

        void userState(
                int32_t session,
                int32_t actor,
                string name,
                int32_t user_id,
                int32_t channel_id,
                int32_t mute,
                int32_t deaf,
                int32_t suppress,
                int32_t self_mute,
                int32_t self_deaf,
                string comment,
                int32_t priority_speaker,
                int32_t recording) override;

        void banList(
                const uint8_t *ip_data,
                uint32_t ip_data_size,
                uint32_t mask,
                string name,
                string hash,
                string reason,
                string start,
                int32_t duration) override;

        void textMessage(
                uint32_t actor,
                std::vector<uint32_t> session,
                std::vector<uint32_t> channel_id,
                std::vector<uint32_t> tree_id,
                string message) override;

        void permissionDenied(
                int32_t permission,
                int32_t channel_id,
                int32_t session,
                string reason,
                int32_t deny_type,
                string name) override;

        void queryUsers(
                uint32_t n_ids,
                uint32_t *ids,
                uint32_t n_names,
                string *names) override;

        void contextActionModify(
                string action,
                string text,
                uint32_t m_context,
                uint32_t operation) override;

        void contextAction(
                int32_t session,
                int32_t channel_id,
                string action) override;

        void userList(
                uint32_t user_id,
                string name,
                string last_seen,
                int32_t last_channel) override;

        void permissionQuery(
                int32_t channel_id,
                uint32_t permissions,
                int32_t flush) override;

        void codecVersion(
                int32_t alpha,
                int32_t beta,
                uint32_t prefer_alpha,
                int32_t opus) override;

        void serverConfig(
                uint32_t max_bandwidth,
                string welcome_text,
                uint32_t allow_html,
                uint32_t message_length,
                uint32_t image_message_length) override;

        void suggestConfig(
                uint32_t version,
                uint32_t positional,
                uint32_t push_to_talk) override;

    private:
        _BasicCallback_Private *impl;
    };
}
