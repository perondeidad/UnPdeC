#ifndef OFFSET_LOG_H
#define OFFSET_LOG_H

#include "Common.h"
#include "GV.h"

namespace UnPdeC {

    /// <summary>
    /// ƫ�Ƽ�¼��
    /// </summary>
    class OffsetLog {
    public:
        /// <summary>
        /// ���ƫ�Ƽ�¼
        /// </summary>
        /// <param name="BlockOffset">���ݿ�������Ϣ���������ƫ��ֵ</param>
        /// <param name="OriginalOffset">�������е�ԭʼƫ��ֵ</param>
        /// <param name="PdeOffset">������ԭʼƫ��ֵת��������PDE�ļ���ʵ��ƫ��ֵ</param>
        /// <param name="Size">�����ݵĴ�С</param>
        /// <param name="Name">����</param>
        /// <param name="Type">����</param>
        /// <param name="Path">·��</param>
        static void AddEntry(uint32_t BlockOffset, uint32_t OriginalOffset, uint32_t PdeOffset, uint32_t Size,
            std::string_view Name, uint8_t Type, std::string_view Path);

        /// <summary>
        /// ��ȡ�򴴽�·��
        /// </summary>
        /// <param name="Path">·��</param>
        /// <returns>*LogData</returns>
        static nlohmann::json& GetOrCreatePath(std::string_view Path);

        /// <summary>
        /// ����JSON�ļ���Ӳ��
        /// </summary>
        static void SaveToFile();

        /// <summary>
        /// д��ȫ�ֱ���
        /// </summary>
        static void WriteToGV();

    private:
        /// <summary>
        /// ƫ����־����
        /// </summary>
        static nlohmann::json LogData;

        /// <summary>
        /// ��ʼ��ƫ��ֵ��־
        /// </summary>
        static void InitializeLogDataIfNeeded();

        /// <summary>
        /// 10��ת16����
        /// </summary>
        /// <param name="value">10����</param>
        /// <returns>16����</returns>
        static std::string ToHex(uint32_t value);
    };

} // namespace UnPdeC
#endif // OFFSET_LOG_H